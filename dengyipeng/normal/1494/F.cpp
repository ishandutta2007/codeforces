#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 3005
using namespace std;

int n,m,i,j,k,a[maxn][2],du[maxn],cnt;
int em,e[maxn*2],nx[maxn*2],ls[maxn],used[maxn*2],bz[maxn][maxn];
int fa[maxn],g[maxn],ans[maxn*2],d[maxn];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}
void link(int x,int y){
	x=father(x),y=father(y);
	if (x!=y) g[y]+=g[x],fa[x]=y;
}

void write(){
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	exit(0);
}

void dfs(int x){
	while (ls[x]){
		while (used[ls[x]]&&ls[x]) ls[x]=nx[ls[x]];
		if (ls[x]){
			used[ls[x]]=used[ls[x]^1]=1;
			dfs(e[ls[x]]);
		}
	}
	ans[++ans[0]]=x;
}

void doit(int S){
	dfs(S);
	for(i=1;i<=ans[0]/2;i++) swap(ans[i],ans[ans[0]-i+1]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&a[i][0],&a[i][1]);
		du[a[i][0]]++,du[a[i][1]]++;
		bz[a[i][0]][a[i][1]]=bz[a[i][1]][a[i][0]]=1;
	}
	for(i=1;i<=n;i++) cnt+=du[i]&1;
	if (cnt==0) {
		for(em=1,i=1;i<=m;i++) insert(a[i][0],a[i][1]);
		doit(1),write();
	} else 
	if (cnt==2){
		for(i=1;i<=n;i++) if (du[i]&1) k=i;
		for(em=1,i=1;i<=m;i++) insert(a[i][0],a[i][1]);
		doit(k),write();
	} else {
		for(int x=1;x<=n;x++){
			int c1=0,c2=0;
			for(int y=1;y<=n;y++) if ((du[y]&1)&&x!=y)
				if (bz[x][y]) c1++,d[c1]=y; else c2++;
			if (c2>1) continue;
			for(i=1;i<=n;i++) fa[i]=i,g[i]=1;
			for(i=1;i<=m;i++) if (a[i][0]!=x&&a[i][1]!=x) link(a[i][0],a[i][1]);
			else {
				int y=(a[i][0]==x)?a[i][1]:a[i][0];
				if (du[y]&1^1) link(x,y);
			}
			if (c2==1){
				int tp=1;
				for(i=1;i<=c1;i++) if (father(x)!=father(d[i])&&g[father(d[i])]>1) tp=0;
				if (!tp) continue;
				memset(ls,0,sizeof(int)*(n+1));
				for(em=1,i=1;i<=m;i++) if (a[i][0]!=x&&a[i][1]!=x) insert(a[i][0],a[i][1]);
				else {
					int y=(a[i][0]==x)?a[i][1]:a[i][0];
					if (du[y]&1^1) 
						insert(x,y);
				}
				for(int y=1;y<=n;y++) if ((du[y]&1)&&x!=y&&!bz[x][y])
					doit(y);
				ans[++ans[0]]=-1;
				for(int y=1;y<=n;y++) if ((du[y]&1)&&x!=y&&bz[x][y])
					ans[++ans[0]]=y,ans[++ans[0]]=x;
				write();
			} else {
				int tp=1;
				for(i=1;i<=c1;i++) if (father(x)!=father(d[i])&&g[father(d[i])]>1) tp=0;
				if (tp){
					memset(ls,0,sizeof(int)*(n+1));
					for(em=1,i=1;i<=m;i++) if (a[i][0]!=x&&a[i][1]!=x) insert(a[i][0],a[i][1]);
					else {
						int y=(a[i][0]==x)?a[i][1]:a[i][0];
						if (du[y]&1^1) insert(x,y);
					}
					doit(x);
					ans[++ans[0]]=-1;
					for(i=1;i<=c1;i++) ans[++ans[0]]=d[i],ans[++ans[0]]=x;
					write();
				}
				int res=n,id=0; tp=0;
				for(i=1;i<=c1;i++){
					int y=d[i];
					if (father(x)!=father(y)){
						if (g[father(y)]>1) {
							if (id&&father(y)!=father(id)) tp=1;
							id=y;
						} 
					}
				}
				if (tp||!c1) continue;
				if (!id) id=d[1];
				memset(ls,0,sizeof(int)*(n+1));
				for(em=1,i=1;i<=m;i++) if (a[i][0]!=x&&a[i][1]!=x) insert(a[i][0],a[i][1]);
				else {
					int y=(a[i][0]==x)?a[i][1]:a[i][0];
					if ((du[y]&1^1)||y==id) insert(x,y);
				}
				doit(id);
				ans[++ans[0]]=-1;
				for(i=1;i<=c1;i++) if (d[i]!=id) ans[++ans[0]]=d[i],ans[++ans[0]]=x;
				write();
			}
		}
	}
	printf("0");
}