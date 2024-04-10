#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,mod=998244353,LIM=2e5;
ll n,x[MAXN],y[MAXN],s[MAXN],f[MAXN],ans;
struct BIT{
	ll tree[MAXN];
	void update(ll x,ll val){
		if(x<1 || x>LIM)return;
		for(;x<=LIM;x+=lowbit(x))tree[x]=(tree[x]+val)%mod;
	}
	void query(ll x,ll& val){
		if(x<1 || x>LIM)return;
		for(;x;x-=lowbit(x))val=(tree[x]+val)%mod;
	}
	void query(ll L,ll R,ll& val){
		if(L>R)return;
		ll a=0,b=0;query(L-1,a);query(R,b);
		val=(b-a+mod)%mod;
	}
}tree;
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>x[i]>>y[i]>>s[i];
	}
	rep(i,1,n){
		int pos=upper_bound(x+1,x+1+n,y[i])-x;
		tree.query(pos,i,f[i]);
		f[i]+=(x[i]-y[i]);
		f[i]%=mod;
		tree.update(i,f[i]);
	}
	ans=(x[n]+1)%mod;
	rep(i,1,n){
		if(s[i]){
			ans=(ans+f[i])%mod;
		}
	}
	cout<<ans;
	return 0;
}