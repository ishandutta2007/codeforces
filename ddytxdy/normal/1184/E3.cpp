#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,M=1e6+60;
int n,m,ver[N*2],nxt[N*2],edge[N*2],head[N],tot,f[18][N],ma[18][N],mi[18][N],d[N],fa[N];
struct node{
	int x,y,z,id,ans;bool flag;
	bool friend operator <(node a,node b){return a.z<b.z;}
	void init(){scanf("%d%d%d",&x,&y,&z);}
}a[M];
void cmax(int &x,int y){y>x?x=y:0;}
void cmin(int &x,int y){y<x?x=y:0;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void add(int x,int y,int z){ver[++tot]=y;edge[tot]=z;nxt[tot]=head[x];head[x]=tot;}
bool cmp(node a,node b){return a.id<b.id;}
void pre(int x,int fa){
	d[x]=d[fa]+1;
	for(int i=1;i<18;i++){
		int y=f[i-1][x];
		f[i][x]=f[i-1][y];mi[i][x]=1e9;
		ma[i][x]=max(ma[i-1][x],ma[i-1][y]);
	}
	for(int i=head[x];i;i=nxt[i]){
		int y=ver[i];if(y==fa)continue;
		f[0][y]=x;ma[0][y]=edge[i];mi[0][y]=1e9;
		pre(y,x);
	}
}
int solve(int x,int y,int z){
	int maxn=0;
	if(d[x]<d[y])swap(x,y);
	for(int i=17;i>=0;i--)if(d[x]-(1<<i)>=d[y])
		cmax(maxn,ma[i][x]),cmin(mi[i][x],z),x=f[i][x];
	if(x==y)return maxn;
	for(int i=17;i>=0;i--)if(f[i][x]!=f[i][y]){
		maxn=max(maxn,max(ma[i][x],ma[i][y]));
		cmin(mi[i][x],z);cmin(mi[i][y],z);
		x=f[i][x];y=f[i][y];
	}
	cmin(mi[0][x],z);cmin(mi[0][y],z);
	return max(maxn,max(ma[0][x],ma[0][y]));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y,z;i<=m;i++)a[i].init(),a[i].id=i;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int x=a[i].x,y=a[i].y,z=a[i].z;
		int fx=find(x),fy=find(y);
		if(fx!=fy){
			fa[fx]=fy;a[i].flag=1;
			add(x,y,z);add(y,x,z);
		}
	}
	pre(1,0);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)if(!a[i].flag)a[i].ans=solve(a[i].x,a[i].y,a[i].z);
	for(int i=17;i;i--)for(int j=1;j<=n;j++){
		int y=f[i-1][j];
		cmin(mi[i-1][j],mi[i][j]),cmin(mi[i-1][y],mi[i][j]);
	}
	for(int i=1;i<=m;i++)if(a[i].flag){
		if(d[a[i].x]>d[a[i].y])a[i].ans=mi[0][a[i].x];
		else a[i].ans=mi[0][a[i].y];
	}
	for(int i=1;i<=m;i++)printf("%d\n",a[i].ans);
	return 0;
}