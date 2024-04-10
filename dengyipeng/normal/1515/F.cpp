#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#define maxn 300005
#define ll long long 
using namespace std;

int n,m,i,j,k,fa[maxn];
ll L,a[maxn];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
int em,e[maxn*2],nx[maxn*2],ls[maxn];
map<int,int> S[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

ll s[maxn]; int sz[maxn];
void dfs(int x,int p){
	s[x]=a[x],sz[x]=1;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		dfs(e[i],x),s[x]+=s[e[i]],sz[x]+=sz[e[i]];
}

vector<int> E[maxn];
int cmp(int i,int j){return s[i]-L*sz[i]>s[j]-L*sz[j];}
void dfs2(int x,int p){
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p) E[x].push_back(e[i]);
	sort(E[x].begin(),E[x].end(),cmp);
	for(int i=0;i<E[x].size();i++){
		int y=E[x][i];
		if (s[y]<L*(sz[y]-1)) printf("%d\n",S[x][y]),dfs2(y,x);
		else dfs2(y,x),printf("%d\n",S[x][y]);
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&L);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),fa[i]=i;
	for(i=1;i<=m;i++) {
		scanf("%d%d",&j,&k),S[j][k]=S[k][j]=i;
		if (father(j)!=father(k)) 
			fa[fa[j]]=fa[k],insert(j,k);
	}
	ll sum=0;
	for(i=1;i<=n;i++) sum+=a[i];
	if (sum<L*(n-1)) printf("NO\n"),exit(0);
	dfs(1,0);
	printf("YES\n");
	dfs2(1,0);
}