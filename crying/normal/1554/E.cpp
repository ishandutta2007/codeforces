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
const int MAXN=1e5+10,mod=998244353;
ll T,n,u,v,f[MAXN],power[MAXN];
ll a[MAXN];
vector<int>e[MAXN];
int dfs(int u,int fa,int k){
	for(vit it=e[u].begin();it!=e[u].end();it++){
		ll v=*it;if(v==fa)continue; 
		if(dfs(v,u,k)==0)return 0;
		if(a[v]%k==0)a[u]++;
		else{
			a[v]++;
			if(a[v]%k)return 0;
		}
	}
	if(u==1 && a[1]%k)return 0;
	return 1;
}
int main(){
	power[0]=1;
	rep(i,1,1e5)power[i]=power[i-1]*2%mod;
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n)e[i].clear(),f[i]=0;
		rep(i,1,n-1){
			cin>>u>>v;
			e[u].pb(v);e[v].pb(u);
		}
		f[1]=power[n-1];
		rep(i,2,n-1){
			if((n-1)%i)continue;
			rep(j,1,n)a[j]=0;
			f[i]=dfs(1,-1,i);
		}
		per(i,n-1,1){
			ll j=i+i;
			while(j<n){
				f[i]=(f[i]-f[j]+mod)%mod;
				j+=i;
			}
		}
		rep(i,1,n)printf("%lld ",f[i]);
		printf("\n");
	}

	return 0;
}