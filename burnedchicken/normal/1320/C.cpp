#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=(int(a)); i--)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define debug(a) print2(#a,a)

using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod;

inline ll add(ll a, ll b){return (a+b>=MOD?a+b-MOD:a+b);}
inline ll sub(ll a, ll b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
ll Pow(ll a, ll b){
	if(!b) return 1;
	ll tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline ll inverse(ll n){return Pow(n,MOD-2);}
ll dgts2(ll n){return (n?dgts2(n>>1)+1:0);}
ll dgts(ll n, ll k){return (n?dgts(n/k,k)+1:0);}
inline ll v2(ll n){return __builtin_ctzll(n);}

const int maxn=200005;
//i_am_noob
int n,m,p,cur=0,ans=-2e9-5,l,r,mid;
struct weapon{int atk,cost;}w[maxn];
struct armor{int def,cost;}a[maxn];
struct monster{int atk,def,val;}mo[maxn];
bool comp1(weapon w1, weapon w2){return w1.atk<w2.atk;}
bool comp2(armor a1, armor a2){return a1.def<a2.def;}
bool comp3(monster mo1, monster mo2){return mo1.def<mo2.def;};

int segtree[4*maxn],tag[4*maxn]={0};
void pull(int k){segtree[k]=max(segtree[k<<1],segtree[(k<<1)+1]);}
void build(int k, int l, int r){
	if(l==r){
		segtree[k]=-a[l-1].cost;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
	pull(k);
}
void push(int k, int l, int r){
	if(!tag[k]) return;
	if(l!=r){
		int mid=l+r>>1;
		tag[k<<1]+=tag[k];
		tag[(k<<1)+1]+=tag[k];
		segtree[k<<1]+=tag[k];
		segtree[(k<<1)+1]+=tag[k];
	}
	tag[k]=0;
}
void modify(int k, int l, int r, int ql, int qr, int x){
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r){
		segtree[k]+=x;
		tag[k]+=x;
		return;
	}
	push(k,l,r);
	int mid=l+r>>1;
	modify(k<<1,l,mid,ql,qr,x);
	modify((k<<1)+1,mid+1,r,ql,qr,x);
	pull(k);
}
int query(int k, int l, int r, int ql, int qr){
	if(ql>r||qr<l) return -2e9-5;
	if(ql<=l&&qr>=r) return segtree[k];
	push(k,l,r);
	int mid=l+r>>1;
	return max(query(k<<1,l,mid,ql,qr),query((k<<1)+1,mid+1,r,ql,qr));
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> m >> p;
	rep(n) cin >> w[i].atk >> w[i].cost;
	rep(m) cin >> a[i].def >> a[i].cost;
	rep(p) cin >> mo[i].def >> mo[i].atk >> mo[i].val;
	sort(w,w+n,comp1);
	sort(a,a+m,comp2);
	sort(mo,mo+p,comp3);
	build(1,1,m);
	rep(n){
		modify(1,1,m,1,m,(i==0?-w[i].cost:w[i-1].cost-w[i].cost));
		if(cur<p){
			while(w[i].atk>mo[cur].def){
				l=0,r=m-1;
				while(l!=r){
					mid=l+r>>1;
					if(a[mid].def>mo[cur].atk) r=mid;
					else l=mid+1;
				}
				if(a[m-1].def>mo[cur].atk) modify(1,1,m,l+1,m,mo[cur].val);
				cur++;
				if(cur==p) break;
			}
		}
		ans=max(ans,query(1,1,m,1,m));
	}
	print1(ans);
	return 0;
}