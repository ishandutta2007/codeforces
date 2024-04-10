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

const int maxn=1000005;
//i_am_noob
int n,cur=1,val[maxn]={0};
string str;

int segtree[4*maxn],tag[4*maxn]={0};
void pull(int k){segtree[k]=max(segtree[k<<1],segtree[(k<<1)+1]);}
void build(int k, int l, int r){
	if(l==r){
		segtree[k]=0;
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

int segtree2[4*maxn],tag2[4*maxn]={0};
void pull2(int k){segtree2[k]=min(segtree2[k<<1],segtree2[(k<<1)+1]);}
void build2(int k, int l, int r){
	if(l==r){
		segtree2[k]=0;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build((k<<1)+1,mid+1,r);
	pull2(k);
}
void push2(int k, int l, int r){
	if(!tag2[k]) return;
	if(l!=r){
		int mid=l+r>>1;
		tag2[k<<1]+=tag2[k];
		tag2[(k<<1)+1]+=tag2[k];
		segtree2[k<<1]+=tag2[k];
		segtree2[(k<<1)+1]+=tag2[k];
	}
	tag2[k]=0;
}
void modify2(int k, int l, int r, int ql, int qr, int x){
	if(ql>r||qr<l) return;
	if(ql<=l&&qr>=r){
		segtree2[k]+=x;
		tag2[k]+=x;
		return;
	}
	push2(k,l,r);
	int mid=l+r>>1;
	modify2(k<<1,l,mid,ql,qr,x);
	modify2((k<<1)+1,mid+1,r,ql,qr,x);
	pull2(k);
}
int query2(int k, int l, int r, int ql, int qr){
	if(ql>r||qr<l) return 2e9+5;
	if(ql<=l&&qr>=r) return segtree2[k];
	push2(k,l,r);
	int mid=l+r>>1;
	return min(query2(k<<1,l,mid,ql,qr),query2((k<<1)+1,mid+1,r,ql,qr));
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n >> str;
	build(1,1,n);
	build2(1,1,n);
	rep(n){
		if(str[i]=='R') cur++;
		else if(str[i]=='L'){
			if(cur>1) cur--;
		}
		else if(str[i]=='('){
			if(val[cur]!=1){
				modify(1,1,n,cur,n,1-val[cur]);
				modify2(1,1,n,cur,n,1-val[cur]);
				val[cur]=1;
			}	
		}
		else if(str[i]==')'){
			if(val[cur]!=-1){
				modify(1,1,n,cur,n,-1-val[cur]);
				modify2(1,1,n,cur,n,-1-val[cur]);
				val[cur]=-1;
			}	
		}
		else{
			if(val[cur]!=0){
				modify(1,1,n,cur,n,-val[cur]);
				modify2(1,1,n,cur,n,-val[cur]);
				val[cur]=0;
			}
		}
		if(query2(1,1,n,1,n)<0||query(1,1,n,n,n)!=0) print0(-1);
		else print0(query(1,1,n,1,n));
	}
	cout << '\n';
	return 0;
}