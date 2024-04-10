#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
const ll mod=1e9+7,MAXN=2010;
ll power(ll a,ll n){
	if(!n)return 1;
	ll tmp=power(a,n/2);tmp=tmp*tmp%mod;if(n&1)tmp=tmp*a%mod;return tmp;
}
ll f[70],k,n;
ll u[MAXN],w[MAXN];
string tmp;
map<pair<ll,ll>,ll>g;
map<ll,ll>col;
ll calc(ll u,ll c){
	if(g.find(mp(u,c))!=g.end())return g[mp(u,c)];
	rep(lev,1,60){
		if((1LL<<lev)>u){
			return g[mp(u,c)]=f[k-lev+1];
		}
	}
	return 114514;
}
void update(ll u){
	rep(i,0,5){
		if(col.find(u)!=col.end() && col[u]!=i){g[mp(u,i)]=0;continue;}
		if(u*2<(1LL<<k)){
			ll ret=0;
			rep(x,0,5){
				if(x==i || x+i==5)continue;
				ll val1=calc(u*2,x);
				rep(y,0,5){
					if(y==i || y+i==5)continue;
					ll val2=calc(u*2+1,y);
					ret=(ret+val1*val2%mod)%mod;
				} 
			}
			g[mp(u,i)]=ret;
		}else{
			g[mp(u,i)]=1;
		}
	}
}
int main(){
	rep(i,1,60){
		f[i]=power(4,(1LL<<i)-2);
	}
	cin>>k>>n;
	rep(i,1,n){
		cin>>u[i]>>tmp;
		if(tmp=="white")w[i]=0;
		else if(tmp=="yellow")w[i]=5;
		else if(tmp=="green")w[i]=1;
		else if(tmp=="blue")w[i]=4;
		else if(tmp=="red")w[i]=2;
		else w[i]=3;
		col[u[i]]=w[i];
	}
	rep(i,1,n){
		ll node=u[i];
		while(node){
			update(node);
			node>>=1; 
		}
	}
	ll ans=0;
	rep(i,0,5){
		ans=(ans+calc(1,i))%mod;
	}
	cout<<ans;
	
	return 0;
}