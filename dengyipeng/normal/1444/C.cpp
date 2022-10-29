#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 500005
#define ll long long
using namespace std;

int n,m,p,i,j,k,v[maxn],bz[maxn],cnt,tp[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];
vector<int> d[maxn];
ll ans;

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int fa[maxn];
int bfs(int s){
	static int d[maxn];
	int t=0,w=1; d[1]=s,bz[s]=0,fa[s]=s;
	while (t<w){
		int x=d[++t];
		for(int i=ls[x];i;i=nx[i]) if (v[e[i]]==v[x]){
			if (bz[e[i]]==-1){
				bz[e[i]]=bz[x]^1;
				fa[e[i]]=s;
				d[++w]=e[i];
			} else 
			if (bz[e[i]]!=bz[x]^1) return 0;
		}
	}
	return 1;
}

int a[maxn*2][2];
vector<int> E[maxn];
int cmp(int i,int j){return v[a[i][1]]<v[a[j][1]];}

int Fa[maxn],g[maxn];
int father(int x){
	if (Fa[x]==x) return x;
	int p=father(Fa[x]);
	g[x]^=g[Fa[x]]; return Fa[x]=p;
}
int link(int x,int y,int z){
	if (father(x)!=father(y)){
		int p=Fa[y];
		Fa[p]=Fa[x];
		g[p]^=g[x]^g[y]^z;
	} else 
	if (g[x]^g[y]^z) return 0;
	return 1;
}

int main(){
	read(n),read(m),read(p);
	for(i=1;i<=n;i++) read(v[i]),bz[i]=-1;
	for(i=1;i<=m;i++) {
		int x,y; read(x),read(y);
		insert(x,y);
		if (v[x]!=v[y]){
			a[2*i-1][0]=x,a[2*i-1][1]=y;
			a[2*i][0]=y,a[2*i][1]=x;
			E[v[x]].push_back(2*i-1),E[v[y]].push_back(2*i);
		}
	}
	for(i=1;i<=p;i++) sort(E[i].begin(),E[i].end(),cmp);
	
	for(i=1;i<=n;i++) d[v[i]].push_back(i);
	for(int now=1;now<=p;now++){
		tp[now]=1;
		for(i=0;i<d[now].size()&&tp[now];i++) if (bz[d[now][i]]==-1)
			tp[now]&=bfs(d[now][i]);
		cnt+=tp[now];
	}
	
	for(i=1;i<=n;i++) if (fa[i]==i) Fa[i]=i,g[i]=0;
	for(int now=1;now<=p;now++) if (tp[now]){
		ans+=cnt-1;
		for(i=0;i<E[now].size();i=j){
			for(j=i;j<E[now].size()&&v[a[E[now][j]][1]]==v[a[E[now][i]][1]];j++);
			if (!tp[v[a[E[now][i]][1]]]) continue;
			int tp=1;
			for(k=i;k<j&&tp;k++){
				int x=a[E[now][k]][0],y=a[E[now][k]][1];
				tp&=link(fa[x],fa[y],bz[x]^bz[y]^1);
			}
			if (!tp) ans--;
			for(k=i;k<j;k++){
				int x=a[E[now][k]][0],y=a[E[now][k]][1];
				Fa[fa[x]]=fa[x],g[fa[x]]=0;
				Fa[fa[y]]=fa[y],g[fa[y]]=0;
			}
		}
	}
	printf("%lld\n",ans/2);
}