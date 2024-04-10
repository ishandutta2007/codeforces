#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<queue>
#include<stack>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
#define ls(p) tree[p].ls
#define rs(p) tree[p].rs
const int N=2e6+7;
const int INF=1e9+7;
int n,m,k,cnt=0;
struct seg{int x,id;}s[N];
bool cmp(seg a,seg b){return a.x<b.x;}
int lo[N],ro[N],o[N],rt[N],w[N];
struct Tree{int lz,mi,ls,rs;}tree[22260817];
int real(int p){return p?max(tree[p].mi,tree[p].lz):INF;}
void update(int p){tree[p].mi=min(real(ls(p)),real(rs(p)));}
void add(int p,int x,int y,int l,int r){
	if(l==r){
		tree[p].mi=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid){
		if(!ls(p)){
			tree[++cnt]=(Tree){0,0,0,0};
			ls(p)=cnt;
		}
		add(ls(p),x,y,l,mid);
	}
	else{
		if(!rs(p)){
			tree[++cnt]=(Tree){0,0,0,0};
			rs(p)=cnt;
		}
		add(rs(p),x,y,mid+1,r);
	}
	update(p);
}
int mer(int a,int b,int &al,int &bl,int ya,int yb){
//	if(cnt>N*8-10)return 0;
	if(!a){
		if(!b)return 0;
		tree[++cnt]=tree[b];
		tree[cnt].lz=max(tree[cnt].lz,yb);
		al=min(al,real(cnt));
		tree[cnt].lz=max(tree[cnt].lz,bl);
		return cnt;
	}
	if(!b){
		tree[++cnt]=tree[a];
		tree[cnt].lz=max(tree[cnt].lz,ya);
		bl=min(bl,real(cnt));
		tree[cnt].lz=max(tree[cnt].lz,al);
		return cnt;
	}
	ya=max(ya,tree[a].lz);
	yb=max(yb,tree[b].lz);
	tree[++cnt]=(Tree){0,0,0,0};
	int o=cnt;
	rs(o)=mer(rs(a),rs(b),al,bl,ya,yb);
	ls(o)=mer(ls(a),ls(b),al,bl,ya,yb);
	update(o);
	return o;
}
int check(int p,int L,int R,int l,int r){
	if(L<=l&&R>=r)return real(p);
	int mid=(l+r)>>1,ans=INF;
	if(L<=mid)if(ls(p))ans=min(ans,check(ls(p),L,R,l,mid));
	if(R>mid)if(rs(p))ans=min(ans,check(rs(p),L,R,mid+1,r));
	ans=max(ans,tree[p].lz);
	return ans;
}
struct Tr{int l,r,rt;}t[N*4];
void build(int l,int r,int p){
	t[p]=(Tr){l,r,0};
	if(l==r){
		t[p].rt=rt[l];
		return;
	}
	int mid=(l+r)>>1,q1=INF,q2=INF;
	build(l,mid,p*2);
	build(mid+1,r,p*2+1);
	t[p].rt=mer(t[p*2].rt,t[p*2+1].rt,q1,q2,0,0); 
}
int query(int p,int L,int R,int x){
	int l=t[p].l,r=t[p].r;
	if(L<=l&&R>=r)return check(t[p].rt,x,k,1,k);
	int mid=(l+r)>>1,ans=0;
	if(L<=mid)ans=max(ans,query(p*2,L,R,x));
	if(R>mid)ans=max(ans,query(p*2+1,L,R,x));
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,n)w[i]=1;
	rep(i,k){
		scanf("%d%d%d",&s[i].x,&ro[i],&o[i]);
		w[o[i]]=0;
		s[i].id=i;
	}
	rep(i,n)w[i]+=w[i-1];
	sort(s+1,s+k+1,cmp);
	rep(i,k)lo[s[i].id]=i;
	rep(i,n){
		tree[++cnt]=(Tree){0,0,0,0};
		rt[i]=cnt;
	}
	rep(i,k)add(rt[o[i]],lo[i],ro[i],1,k);
	build(1,n,1);
	while(m--){
		int l,r,x,y; scanf("%d%d%d%d",&l,&r,&x,&y);
		if(x>s[k].x){puts("no"); fflush(stdout); continue;}
		int L=1,R=k,d;
		while(L<R-1){
			int mid=(L+R)>>1;
			if(s[mid].x>=x)R=mid;
			else L=mid;
		}
		d=(s[L].x>=x)?L:R;
		int ans=query(1,l,r,d);
		if(ans<=y)puts("yes");
		else puts("no");
		fflush(stdout);
	}
	return 0;
}