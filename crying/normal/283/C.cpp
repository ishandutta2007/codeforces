#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=310,MAXM=1e5+10,moder=1e9+7;
int to[MAXN];
int n,a[MAXN],b,c,t,q;
int vis[MAXN],fa[MAXN],tot;
ll f[MAXN][MAXM];
vector<int>dev[MAXN];
void dfs(int u){
	vis[u]=1;
	dev[tot].pb(u);
	if(to[u])dfs(to[u]);
}
int main(){
	scanf("%d%d%d",&n,&q,&t);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,q){
		scanf("%d%d",&b,&c);
		to[c]=b;
		fa[b]=c;
	}
	rep(i,1,n){
		if(vis[i])continue;
		if(!fa[i]){
			tot++;
			dfs(i);
		}
	}
	rep(i,1,n){
		if(!vis[i]){
			printf("0");return 0;
		}
	}
	rep(i,1,tot){
		ll sum=0,cnt=0,k,sz=dev[i].size();
		for(vit it=dev[i].begin();it!=dev[i].end();it++){
			sum+=cnt*a[*it];
			cnt++;
		}
		if(sum>t){
			printf("0");return 0;
		}
		t-=sum;
		per(j,sz-2,0){
			a[dev[i][j]]+=a[dev[i][j+1]];
		}
	}
	f[0][0]=1;
	rep(i,1,n){
		rep(j,0,t){
			f[i][j]=f[i-1][j];
			if(j>=a[i])f[i][j]=(f[i][j]+f[i][j-a[i]])%moder;
		}
	}
	printf("%lld",f[n][t]);
	return 0;
}