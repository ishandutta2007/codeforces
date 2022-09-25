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
#define printvec(a) rep(a.size()) print0(a[i])
#define debug(a) print2(#a,a)
 
using namespace std;

const ll Mod=1000000007,Mod2=998244353;
const ll MOD=Mod2;
 
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
int n,m,a[maxn],ans[maxn],cur=1,l,r,mid;
pii num[maxn];

bool comp1(pii p1, pii p2){
	return p1.first!=p2.first?p1.first>p2.first:p1.second<p2.second;
}

struct query{
	int x,y,pos;
}q[maxn];
bool comp(query q1, query q2){
	return q1.x!=q2.x?q1.x<q2.x:q1.y<q2.y;
}

int BIT[maxn]={0};
void add(int x, int y){for(int i=x; i<maxn; i+=i&-i) BIT[i]+=y;}
int query(int x){
	int ret=0;
	for(int i=x; i>0; i-=i&-i) ret+=BIT[i];
	return ret;
}
int query(int x, int y){
	int ret=0;
	for(int i=y; i>0; i-=i&-i) ret+=BIT[i];
	for(int i=x-1; i>0; i-=i&-i) ret-=BIT[i];
	return ret;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	rep(n) cin >> num[i].first;
	rep(n) a[i]=num[i].first;
	rep(n) num[i].second=i+1;
	sort(num,num+n,comp1);
	cin >> m;
	rep(m) cin >> q[i].x >> q[i].y;
	rep(m) q[i].pos=i;
	sort(q,q+m,comp);
	rep(m){
		while(cur<=q[i].x){
			add(num[cur-1].second,1);
			cur++;
		}
		l=1,r=maxn-1;
		while(l!=r){
			mid=l+r>>1;
			if(query(mid)>=q[i].y) r=mid;
			else l=mid+1;
		}
		ans[q[i].pos]=a[l-1];
	}
	rep(m) print1(ans[i]);
	return 0;
}