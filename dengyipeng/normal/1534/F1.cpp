#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define maxn 1000005
#define maxm 10000005
#define I(x,y) ((x-1)*m+y)
using namespace std;
 
int n,m,i,j,k,bz[maxn],a[maxn],M,bz0[maxn];
int em,e[maxm],nx[maxm],ls[maxn];
int A(int x,int y){return bz[I(x,y)];}
 
void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
}
 
int tot,dfn[maxn],low[maxn],d[maxn],vis[maxn],fr[maxn],cnt,c[maxn],c0[maxn];
int Em,E[maxm],Nx[maxm],Ls[maxn],du[maxn];
void Insert(int x,int y){
	Em++; E[Em]=y; Nx[Em]=Ls[x]; Ls[x]=Em; du[y]++;
}
 
void tarjan(int x){
	dfn[x]=low[x]=++tot,d[++d[0]]=x,vis[x]=1;
	for(int i=ls[x];i;i=nx[i]){
		int y=e[i];
		if (dfn[y]){
			if (vis[y]) low[x]=min(low[x],low[y]);
		} else tarjan(y),low[x]=min(low[x],low[y]);
	}
	if (dfn[x]==low[x]){
		cnt++;
		while (d[d[0]]!=x) {
			int y=d[d[0]--];
			fr[y]=cnt,vis[y]=0,c[cnt]+=bz[y];
			if (bz0[y]) c0[cnt]=(y-1)%m+1;
		}	
		fr[x]=cnt,vis[x]=0,d[0]--,c[cnt]+=bz[x]; 
		if (bz0[x]) c0[cnt]=(x-1)%m+1;
	}
}

int f0[maxn],L[maxn],R[maxn],cntp;
struct arr{int l,r;} opr[maxn];
int cmp(arr a,arr b){return a.l<b.l;}
void tropu(){
	memset(vis,0,sizeof(vis));
	int t=0,w=0;
	for(i=1;i<=cnt;i++) if (!du[i]) d[++w]=i;
	int ans=0;
	while (t<w){
		int x=d[++t];  L[x]=m+1,R[x]=0;
		if (c0[x]&&!f0[x]) vis[c0[x]]=1,L[x]=R[x]=c0[x];
		f0[x]|=c0[x];
		for(i=Ls[x];i;i=Nx[i]){
			int y=E[i];
			f0[y]|=f0[x];
			if (!--du[y]) d[++w]=y;
		}
	}
	for(k=w;k>=1;k--){
		int x=d[k];
		for(i=Ls[x];i;i=Nx[i]) {
			int y=E[i];
			L[x]=min(L[x],L[y]),R[x]=max(R[x],R[y]);
		}
		if (c[x]&&L[x]<=R[x]) 			
			opr[++cntp]=(arr){L[x],R[x]};
	}
}

void Greedy(){
	sort(opr+1,opr+1+cntp,cmp);
	int R=0,ans=0;
	for(i=1,j=1;i<=m;i++) if (vis[i]){
		while (opr[j].l<=i&&j<=cntp) R=max(R,opr[j].r),j++;
		ans++,i=R;
	}
	printf("%d\n",ans);
}
 
int main(){
	scanf("%d%d",&n,&m),M=n*m;
	char ch=getchar();
	for(i=1;i<=n;i++){
		while (ch!='.'&&ch!='#') ch=getchar();
		for(j=1;j<=m;j++) bz[I(i,j)]=ch=='#',ch=getchar();
	}
	for(i=1;i<=m;i++) scanf("%d",&a[i]);
	for(j=1;j<=m;j++) if (a[j]){
		k=a[j];
		for(i=n;i>=1;i--) if (bz[I(i,j)]){
			k--;
			if (!k) {bz0[I(i,j)]=1;break;}
		}	
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if (A(i,j)){
		if (i>1) insert(I(i,j),I(i-1,j));
		if (j>1) insert(I(i,j),I(i,j-1)+M);
		if (j<m) insert(I(i,j),I(i,j+1)+M);
		if (i<n) insert(I(i,j),I(i+1,j)+M);
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
		insert(I(i,j)+M,I(i,j));
		if (i<n) insert(I(i,j)+M,I(i+1,j)+M);
	}
	for(i=1;i<=2*M;i++) if (!dfn[i]) tarjan(i);
	for(int x=1;x<=2*M;x++) for(i=ls[x];i;i=nx[i]) if (fr[x]!=fr[e[i]])
		Insert(fr[x],fr[e[i]]);
	tropu();
	Greedy();
}