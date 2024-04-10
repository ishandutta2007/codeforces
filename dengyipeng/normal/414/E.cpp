#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define maxn 100005
#define maxm 200010
using namespace std;

int n,m,i,j,k,x,y,tmp[maxn],tp;
int em,e[maxm],nx[maxm],ls[maxn],fai[maxn];
int RT,tot,in[maxn],out[maxn],in0[maxm],out0[maxm];

int s[maxm][2],c[maxm],mins[maxm],maxs[maxm],sum[maxm],fa[maxm];

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
}

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void DFS(int x){ 
	in[x]=++tot,c[tot]=1,in0[tot]=x;
	for(int i=ls[x];i;i=nx[i]) DFS(e[i]),fai[e[i]]=x;
	out[x]=++tot,c[tot]=-1,out0[tot]=x;
}

void upd(int x){
	int l=s[x][0],r=s[x][1];
	sum[x]=c[x]+sum[l]+sum[r];
	mins[x]=min(mins[l],min(sum[l]+c[x],sum[l]+c[x]+mins[r]));
	maxs[x]=max(maxs[l],max(sum[l]+c[x],sum[l]+c[x]+maxs[r]));
}

int cnt=0;

int maketree(int l,int r){
	int mid=(l+r)>>1;
	if (l<mid) s[mid][0]=maketree(l,mid-1),fa[s[mid][0]]=mid;
	if (mid<r) s[mid][1]=maketree(mid+1,r),fa[s[mid][1]]=mid;
	upd(mid); cnt++;
	return mid;
}

int get(int x){return s[fa[x]][1]==x;}

void rotate(int x){
    int y=fa[x],c=get(x);
    s[y][c]=s[x][c^1],s[x][c^1]=y;
    if (s[y][c]) fa[s[y][c]]=y;
    if (y!=RT) s[fa[y]][get(y)]=x;
    fa[x]=fa[y],fa[y]=x;
    upd(y),upd(x);
}

void splay(int x,int y){
	while (fa[x]!=y){
		if (fa[fa[x]]!=y)
			if (get(x)==get(fa[x])) 
				rotate(fa[x]);
			else rotate(x);
		rotate(x);
	}
}

int pre(int x){splay(x,RT);for(x=s[x][0];x&&s[x][1];x=s[x][1]);return x;}
int nex(int x){splay(x,RT);for(x=s[x][1];x&&s[x][0];x=s[x][0]);return x;}

int dis(int x){
	splay(x,RT);
	return sum[s[x][0]];
}

void query(){
	read(x),read(y);
	if (x==y){printf("0\n");return;}
	x=in[x],y=in[y];
	int disx=dis(x); 
	int disy=dis(y);
	splay(x,RT),splay(y,x);
	int ans=min(disx,disy);
	if (s[x][0]==y) 
		ans=min(ans,sum[s[y][0]]+c[y]+mins[s[y][1]]-1);
	else 
		ans=min(ans,sum[s[x][0]]+c[x]+mins[s[y][0]]-1);
	ans=disx+disy-2*ans;
	printf("%d\n",ans);
}

int find(int x,int k){
	int l=s[x][0],r=s[x][1];
	if (sum[l]+c[x]+mins[r]<=k&&k<=sum[l]+c[x]+maxs[r])
		return find(r,k-sum[l]-c[x]);
	if (sum[l]+c[x]==k) return x;
	return find(l,k);
}

void change(){
	read(x),read(k);	
	int disx=dis(in[x]);
	splay(in[1],RT);
	splay(in[x],in[1]);
	if (disx==k) y=in[1];
	else y=find(s[in[x]][0],disx-k);
	
	int prex=pre(in[x]),nexx=nex(out[x]);
	splay(prex,RT),splay(nexx,prex);
	int p=s[nexx][0]; s[nexx][0]=0; upd(nexx),upd(prex);
	 
	if (out0[y]) y=out[fai[out0[y]]]; else y=out[in0[y]];
	int z=pre(y);
	splay(z,RT),splay(y,z);
	s[y][0]=p; fa[p]=y; upd(y),upd(z);
	
	fai[x]=out0[y];
}

void findk(){
	read(k);
	splay(in[1],RT),splay(tot,in[1]);
	x=find(s[tot][0],k);
	if (out0[x]) x=fai[out0[x]]; else x=in0[x];
	printf("%d\n",x);
}

int main(){
//	freopen("data4.in","r",stdin);
//	freopen("ceshi.out","w",stdout);
	read(n),read(m);
	for(i=1;i<=n;i++) {
		read(k);
		for(j=1;j<=k;j++) read(tmp[j]);
		for(j=k;j>=1;j--) insert(i,tmp[j]);
	}
	
	RT=0,mins[0]=maxn,maxs[0]=-maxn,c[0]=sum[0]=0;
	tot++,mins[tot]=maxn,maxs[tot]=-maxn,c[tot]=sum[tot]=0;
	DFS(1);
	tot++,mins[tot]=maxn,maxs[tot]=-maxn,c[tot]=sum[tot]=0;
	x=maketree(1,tot); s[RT][1]=x,fa[x]=RT;
	
	while (m--){
		read(tp);
		if (tp==1) query(); else 
		if (tp==2) change(); else
		if (tp==3) findk();
	}
}