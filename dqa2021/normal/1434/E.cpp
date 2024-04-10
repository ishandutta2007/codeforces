#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9,U=1e5;

int n,m,v[100010];
/*int fat[455][100010],L[455][100010]; char dep[455][100010];
int find(int x,int *f){return f[x]==x?x:f[x]=find(f[x]);}  //f[i]=i
int merge(int x,int y,int *fat,int *L,char *dep){  //x <- y
	x=find(x,fat),y=find(y,fat);
	if (x==y) return;
	if (dep[x]<dep[y]) swap(x,y);
	fat[y]=x,L[x]=min(L[x],L[y]);
	dep[x]=max(dep[x],dep[y]+1);
}*/
int f[455][100010],g[455][100010];
int find(int x,int *f){return f[x]==x?x:f[x]=find(f[x],f);}
void work(int l,int r,int *f,int *g,int v){
	while ((r=find(r,f))>=l){
		f[r]=r-1; g[r]=v;
	}
}
int p[455],d[455];
int q[100010];
int c[100010],ctim;
int solve(){
	m=read();
	for (int i=U+1;~i;i--) q[i]=0;
	for (int i=1;i<=m;i++) q[v[i]=read()]=i;
	for (int i=U;~i;i--) if (!q[i]) q[i]=q[i+1];
	//if (m==1) return 0;
	for (int i=0;i<=450;i++){
		int *f=::f[i],*g=::g[i];
		for (int j=0;j<=m;j++)
			f[j]=j,g[j]=-1;
	}
	++ctim; c[0]=ctim;
	work(1,m,f[0],g[0],m);
	for (int i=m-1,j;i;i--){
		p[0]=INF;
		for (j=0;j<450;j++){
			if (!~g[j][i]){break;}
			p[j+1]=min(p[j],g[j][i]);
		}
		c[j]=ctim;
		int rmax=i+1;
		for (int u=j;u;u--){
			int t=v[i]*2-v[p[u]]+1;
			if (t<0) d[u]=1;
			else d[u]=q[t];
			if (d[u]>=rmax) continue;
			//[d_u,rmax)
			work(d[u],rmax-1,f[u],g[u],i);
			rmax=d[u];
		}
		// mex = 0 not necessary
	}
	int res=0; while (c[res]==ctim) ++res;
	return res;
}
int main()
{
	n=read(); int ans=0;
	while (n--) ans^=solve();
	puts(ans?"YES":"NO");
	return 0;
}