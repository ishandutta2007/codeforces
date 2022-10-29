#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 500005
using namespace std;

int n,q,i,j,k,mxl[maxn],g[maxn],a[maxn][2];
int em,e[maxn*2],nx[maxn*2],ls[maxn],ec[maxn*2];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void insert(int x,int y,int z){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em; ec[em]=z;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em; ec[em]=z;
}

struct Tree{
	int rt,v[maxn],dfn[maxn],sz[maxn],tot,dep[maxn],Idfn[maxn];
	void dfs(int x,int p){
		dfn[x]=++tot,Idfn[tot]=x,sz[x]=1,dep[x]=dep[p]+1;
		for(int i=ls[x];i;i=nx[i]) if (e[i]!=p)
			v[e[i]]=v[x]^ec[i],dfs(e[i],x),sz[x]+=sz[e[i]];
	}
	int t[maxn*4][2],tag[maxn*4];
	void maketree(int x,int l,int r){
		if (l==r) {
			t[x][v[Idfn[l]]]=dep[Idfn[l]];
			return;
		}
		int mid=(l+r)>>1;
		maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
		t[x][0]=max(t[x<<1][0],t[x<<1^1][0]);
		t[x][1]=max(t[x<<1][1],t[x<<1^1][1]);
	}
	void downtag(int x,int l,int r){
		swap(t[x][0],t[x][1]);
		if (l<r) tag[x<<1]^=tag[x],tag[x<<1^1]^=tag[x];
		tag[x]=0;
	}
	void change(int x,int l,int r,int L,int R){
		if (tag[x]) downtag(x,l,r);
		if (l>R||r<L) return;
		if (L<=l&&r<=R) {tag[x]^=1,downtag(x,l,r);return;}
		int mid=(l+r)>>1;
		change(x<<1,l,mid,L,R),change(x<<1^1,mid+1,r,L,R);
		t[x][0]=max(t[x<<1][0],t[x<<1^1][0]);
		t[x][1]=max(t[x<<1][1],t[x<<1^1][1]);
	}
	int find(int x,int l,int r,int L,int R){
		if (tag[x]) downtag(x,l,r);
		if (l>R||r<L) return 0;
		if (L<=l&&r<=R) return t[x][0];
		int mid=(l+r)>>1;
		return max(find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R));
	}
	void prepare(){dfs(rt,0),maketree(1,1,n);}
	void rev(int i){
		int x=a[i][0],y=a[i][1];
		if (dfn[x]>dfn[y]) swap(x,y);
		change(1,1,n,dfn[y],dfn[y]+sz[y]-1);
	}
	int get(){return t[1][0]-1;}
} t1,t2;

int mx;
void dfs(int x,int p){
	mxl[x]=0,g[x]=x;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		dfs(e[i],x);
		if (mxl[x]+mxl[e[i]]+1>mx) 
			mx=mxl[x]+mxl[e[i]]+1,t1.rt=g[x],t2.rt=g[e[i]];
		if (mxl[e[i]]+1>mxl[x]) 
			mxl[x]=mxl[e[i]]+1,g[x]=g[e[i]];
	}
}


int main(){
	read(n);
	for(i=1;i<n;i++){
		int x,y,z; read(x),read(y),read(z);
		insert(x,y,z),a[i][0]=x,a[i][1]=y;
	}
	dfs(1,0);
	t1.prepare(),t2.prepare();
	read(q);
	while (q--){
		read(k);
		t1.rev(k),t2.rev(k);
		printf("%d\n",max(t1.get(),t2.get()));
	}
}