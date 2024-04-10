#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e3+10;
int n,m,k,vis[MAXN],u,v;
int ans,fa[MAXN],size[MAXN];
int use[MAXN],maxn;
int Find(int x){if(x==fa[x])return x;else return fa[x]=Find(fa[x]);}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){cin>>u;vis[u]=1;}
	for(int i=1;i<=n;i++){fa[i]=i;size[i]=1;}
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		if(Find(u)!=Find(v)){size[Find(u)]+=size[Find(v)],fa[Find(v)]=Find(u);}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			use[Find(i)]=1;
			if(!maxn || size[maxn]<size[Find(i)])maxn=Find(i);
		}
	}
	//maxn 
	for(int i=1;i<=n;i++){
		if(use[Find(i)])continue;
		size[maxn]+=size[Find(i)];
		fa[Find(i)]=maxn;
		use[Find(i)]=1;
	}
	memset(use,0,sizeof use);
	for(int i=1;i<=n;i++){
		if(use[Find(i)])continue;
		ans+=(size[Find(i)]-1)*(size[Find(i)])/2;
		use[Find(i)]=1;
	}
	cout<<ans-m;
	return 0;
}