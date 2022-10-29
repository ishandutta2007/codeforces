#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#define mcpy(a,b) memcpy(a,b,sizeof(a))
#define maxn 100005
#define maxm 200005
#define maxp 18
#define inf 1e9
using namespace std;

int n,i,j,k,x,y;
int em,e[maxm],nx[maxm],ls[maxn];
int dep[maxn],fa[maxn][maxp],f[maxn][maxp],g[maxn][maxp];
int mx[maxn],mx0[maxn][2],mx1[maxn][2],mx2[maxn][2]; 
vector<int> a;

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

void upd(int x,int y,int dep){
	if (dep>=mx0[x][0]) {
		mcpy(mx2[x],mx1[x]);
		mcpy(mx1[x],mx0[x]);
		mx0[x][0]=dep,mx0[x][1]=y;
	} else 
	if (dep>=mx1[x][0]) {
		mcpy(mx2[x],mx1[x]);
		mx1[x][0]=dep,mx1[x][1]=y;
	} else
	if (dep>=mx2[x][0]) {
		mx2[x][0]=dep,mx2[x][1]=y;
	}
}

void DFS(int x,int p){
	dep[x]=dep[p]+1;
	mx[x]=0;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		DFS(e[i],x),mx[x]=max(mx[x],mx[e[i]]+1);
		upd(x,e[i],mx[e[i]]+1);
	}
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p) 
		a.push_back(e[i]);
	int mxnow=0;
	for(int i=0;i<a.size();i++) {
		f[a[i]][0]=max(f[a[i]][0],mxnow);
		g[a[i]][0]=max(g[a[i]][0],mxnow+1);
		mxnow=max(mxnow,mx[a[i]]+1);
	}
	mxnow=0;
	for(int i=a.size()-1;i>=0;i--) {
		f[a[i]][0]=max(f[a[i]][0],mxnow);
		g[a[i]][0]=max(g[a[i]][0],mxnow+1);
		mxnow=max(mxnow,mx[a[i]]+1);
	}
	a.clear();
	fa[x][0]=p;
}

int pre[maxn];
void DFS2(int x,int p){
	pre[x]=g[x][0];
	if (p) pre[x]=max(pre[x],pre[p]+1);
	for(int i=1;i<maxp;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		if (fa[x][i]){
			f[x][i]=max(f[fa[x][i-1]][i-1],f[x][i-1]+(1<<i-1));
			g[x][i]=max(g[fa[x][i-1]][i-1]+(1<<i-1),g[x][i-1]);
		} else break;
	}
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
		DFS2(e[i],x);
}

int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for(int i=maxp-1;i>=0;i--) if (dep[fa[x][i]]>=dep[y])
		x=fa[x][i];
	if (x==y) return x;
	for(int i=maxp-1;i>=0;i--) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int jumpdown(int st,int len,int &p){
	int mx=0,x=st;
	for(int m=len,i=maxp-1;i>=0;i--) if (m>=(1<<i)){
		mx=max(mx,g[x][i]+len-m);
		x=fa[x][i];
		m-=1<<i;
	}
	p=x;
	return mx;
}

int jumpup(int st,int len){
	int mx=-1e9;
	for(int m=len,i=maxp-1,x=st;i>=0;i--) if (m>=(1<<i)){
		mx=max(mx+(1<<i),f[x][i]);
		x=fa[x][i];
		m-=1<<i;
	}
	return mx;
}

int up(int x,int k){
	for(int i=maxp-1;i>=0;i--) if (k>=(1<<i))
		x=fa[x][i],k-=1<<i;
	return x;
}

int fromLCA(int x,int p1,int p2){
	int mx=pre[x];
	if (p1!=mx0[x][1]&&p2!=mx0[x][1]) mx=max(mx,mx0[x][0]);
	if (p1!=mx1[x][1]&&p2!=mx1[x][1]) mx=max(mx,mx1[x][0]);
	if (p1!=mx2[x][1]&&p2!=mx2[x][1]) mx=max(mx,mx2[x][0]);
	return mx;
}

int main(){
//	freopen("data0.in","r",stdin);
//	freopen("ceshi.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		insert(x,y);
	}
	DFS(1,0);
	DFS2(1,0);
	int m,ans;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if (dep[y]>dep[x]) swap(x,y);
		int z=lca(x,y);
		int len=(dep[x]-dep[z]+dep[y]-dep[z])/2;
		int p,xx=up(x,dep[x]-dep[z]-1),yy=up(y,dep[y]-dep[z]-1);
		
		if (dep[x]==dep[y]) {
			ans=jumpdown(x,dep[x]-dep[z]-1,p);
			ans=max(ans,mx[x]);
			ans=max(ans,jumpdown(y,dep[y]-dep[z]-1,p));
			ans=max(ans,mx[y]);
			ans=max(ans,fromLCA(z,xx,yy)+dep[x]-dep[z]);
		} else{
			ans=jumpdown(x,len,p);
			ans=max(ans,mx[x]);
			if (fa[p][0]==z) 
				k=-1; 
			else {
				k=jumpup(p,dep[p]-dep[z]-1);
			}
			k=max(k+1,fromLCA(z,xx,yy));
			if (y!=z) {
				ans=max(ans,jumpdown(y,dep[y]-dep[z]-1,p));
				ans=max(ans,mx[y]);
			}
			ans=max(ans,k+dep[y]-dep[z]);
		}
		printf("%d\n",ans);
	}
}