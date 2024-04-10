#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int n,m,a[N],blo[N],L[N],R[N],block;
int fa[N],val[N],size[N];

int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int merge(int x,int y,int v){
	if (!x||!y){x+=y;val[x]=v;return x;}
	fa[x]=y;val[y]=v;val[x]=0;
	size[y]+=size[x];
	return y;
}
int pos[350][N],mx[350],tag[350];
void down(int x){
	for (int i=L[x];i<=R[x];i++) a[i]=val[find(i)]-tag[x];
}

void reset(int x){
	int *p=pos[x];
	for (int i=L[x];i<=R[x];i++) p[val[i]]=0,fa[i]=i,size[i]=1;
	mx[x]=tag[x]=0;
	for (int i=L[x];i<=R[x];i++){
		mx[x]=max(mx[x],val[i]=a[i]);
		p[val[i]]=merge(p[val[i]],i,val[i]);
	}
}

void dec(int x,int v){
	if (mx[x]<=v) return;
	if (mx[x]>v*2){
		tag[x]+=v;mx[x]-=v;
		int *p=pos[x]+tag[x];
		for (int i=1;i<=v;i++) p[i]=merge(p[i],p[i-v],i+tag[x]),p[i-v]=0;
	}
	else{
		int *p=pos[x]+tag[x];
		for (int i=1;i<=mx[x]-v;i++) p[i]=merge(p[i],p[i+v],i+tag[x]),p[i+v]=0;
		mx[x]=v;
	}
}

void dec(int l,int r,int v){
	down(blo[l]);
	for (int i=l;i<=r;i++) a[i]>v?a[i]-=v:0;
	reset(blo[l]);
}

int query(int l,int r,int v){
	int ans=0;
	down(blo[l]);
	for (int i=l;i<=r;i++) ans+=(a[i]==v);
	return ans;
}

int query(int x,int v){
	return tag[x]+v<N?size[pos[x][tag[x]+v]]:0;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	block=sqrt(n);
	for (int i=1;i<=n;i++) blo[i]=i/block;
	for (int i=0;i<=blo[n];i++) L[i]=i*block,R[i]=(i+1)*block-1;
	L[0]=1;R[blo[n]]=n;
	for (int i=0;i<=blo[n];i++) reset(i);
	while (m--){
		int tp,l,r,x;
		scanf("%d%d%d%d",&tp,&l,&r,&x);
		if (tp==1){
			if (blo[l]==blo[r]) dec(l,r,x);
			else dec(l,R[blo[l]],x),dec(L[blo[r]],r,x);
			for (int i=blo[l]+1;i<blo[r];i++) dec(i,x);
		}
		else{
			int ans=0;
			if (blo[l]==blo[r]) ans=query(l,r,x);
			else ans=query(l,R[blo[l]],x)+query(L[blo[r]],r,x);
			for (int i=blo[l]+1;i<blo[r];i++) ans+=query(i,x);
			printf("%d\n",ans);
		}
	}
	return 0;
}