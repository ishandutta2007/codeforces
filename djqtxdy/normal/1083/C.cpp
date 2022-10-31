#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
#define _ 0
using namespace std;
#ifndef MY
	#define putchar IO::_putchar
	#define getchar IO::_getchar
#endif
namespace IO
{
    const int sz=1<<15;
    char inbuf[sz],outbuf[sz];
    char *pinbuf=inbuf+sz;
    char *poutbuf=outbuf;
    inline char _getchar()
    {
        if (pinbuf==inbuf+sz)fread(inbuf,1,sz,stdin),pinbuf=inbuf;
        return *(pinbuf++);
    }
    inline void _putchar(char x)
    {
        if (poutbuf==outbuf+sz)fwrite(outbuf,1,sz,stdout),poutbuf=outbuf;
        *(poutbuf++)=x;
    }
    inline void flush()
    {
        if (poutbuf!=outbuf)fwrite(outbuf,1,poutbuf-outbuf,stdout),poutbuf=outbuf;
    }
}
inline int read()
{
    int x=0,p=1;
	char c=getchar();
    while (c<'0' || c>'9'){
    	if (c=='-') p=-1;
    	c=getchar();
	}
    while (c>='0' && c<='9') x=x*10+c-48,c=getchar();
    return x*p;
}
const int Maxn=200005;
int n,q,p[Maxn],pos[Maxn];
int par[Maxn][20],st[Maxn],ed[Maxn],ks;
vector<int> G[Maxn];
void dfs(int x){
	st[x]=++ks;
	for (auto v:G[x]){
		dfs(v);
	}
	ed[x]=ks;
}
bool isanc(int u,int v){
	return u==-1 || (st[u]<=st[v] && ed[v]<=ed[u]);
}
int lca(int u,int v){
	if (isanc(u,v)) return u;
	for (int i=19;i>=0;i--){
		if (!isanc(par[u][i],v)) u=par[u][i];
	}
	return par[u][0];
}
struct node{
	int f;
	int u,v,luv;
	void debug(){
		cout<<"Type"<<' '<<f<<';'<<' '<<u<<' '<<v<<endl; 
	}
	node(){
		;
	}
	node(int _f,int _x,int _y){
		f=_f,u=_x,v=_y;
		luv=lca(u,v);
	}
}tree[Maxn*4];
node Merge(node l,node r){
	if (l.f==-2) return r;
	if (r.f==-2) return l;
	if (l.f==-1 || r.f==-1){
		return node(-1,0,0);
	}
	if (l.f==0 && r.f==0){
		if (l.luv!=r.luv) return node(-1,0,0);
		if ((isanc(l.u,r.u) || isanc(r.u,l.u)) && (isanc(l.v,r.v) || isanc(r.v,l.v))){
			return node(0,isanc(l.u,r.u)?r.u:l.u,isanc(l.v,r.v)?r.v:l.v);
		}
		if ((isanc(l.u,r.v) || isanc(r.v,l.u)) && (isanc(l.v,r.u) || isanc(r.u,l.v))){
			return node(0,isanc(l.u,r.v)?r.v:l.u,isanc(l.v,r.u)?r.u:l.v);
		}
		return node(-1,0,0);
	}
	if (l.f==1 && r.f==1){
		if ((isanc(l.u,r.u)||isanc(r.u,l.u)) && (isanc(l.v,r.v)||isanc(r.v,l.v))){
			return node(1,isanc(l.u,r.u)?l.u:r.u,isanc(l.v,r.v)?r.v:l.v);
		}
		if (l.u==r.u || (!isanc(l.u,r.u) && !isanc(r.u,l.u))){
			return node(0,l.v,r.v);
		}
		if (isanc(l.u,r.u) && !isanc(r.u,l.v) && lca(r.u,l.v)==l.u){
			return node(0,r.v,l.v);
		}
		if (isanc(r.u,l.u) && !isanc(l.u,r.v) && lca(l.u,r.v)==r.u){
			return node(0,r.v,l.v);
		}
		return node(-1,0,0);
	}
	if (l.f==1) swap(l,r);
	if (!isanc(l.luv,r.u)) return node(-1,0,0);
	if (isanc(l.u,r.v) || isanc(r.v,l.u)){
		return node(0,isanc(l.u,r.v)?r.v:l.u,l.v);
	}
	if (isanc(l.v,r.v) || isanc(r.v,l.v)){
		return node(0,l.u,isanc(l.v,r.v)?r.v:l.v);
	}
	return node(-1,0,0);
}
void build(int p,int l,int r){
	if (l==r){
		tree[p]=node(1,pos[l],pos[l]);
		return;
	}
	int mid=l+r>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	tree[p]=Merge(tree[p*2],tree[p*2+1]);
	//cout<<l<<' '<<r<<' '<<endl;
	//tree[p].debug();
}
void modify(int p,int l,int r,int po){
	if (l==r){
		tree[p]=node(1,pos[l],pos[l]);
		return;
	}
	int mid=l+r>>1;
	if (po<=mid){
		modify(p*2,l,mid,po);
	}
	else{
		modify(p*2+1,mid+1,r,po);
	}
	//cout<<' '<<l<<' '<<r<<endl;
	tree[p]=Merge(tree[p*2],tree[p*2+1]);
//	tree[p*2].debug();
//	tree[p*2+1].debug();
//	tree[p].debug();
}
int query(int p,int l,int r,node now){
	if (l==r){
		node tmp=Merge(now,tree[p]);
		if (tmp.f!=-1){
			return l;
		}
		return l-1;
	}
	int mid=l+r>>1;
	node tmp=Merge(now,tree[p*2]);
	if (tmp.f!=-1){
		return query(p*2+1,mid+1,r,tmp);
	} 
	return query(p*2,l,mid,now);
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		p[i]=read();
		p[i]++;
		pos[p[i]]=i;
	}
	for (int i=2;i<=n;i++){
		par[i][0]=read();
		G[par[i][0]].pb(i);
	}
	dfs(1);
	par[1][0]=-1;
	for (int i=1;i<20;i++){
		for (int j=1;j<=n;j++){
			if (par[j][i-1]==-1) par[j][i]=-1;
			else par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	build(1,1,n);
	int q=read();
	while (q--){
		int tp=read();
		if (tp==2){
			printf("%d\n",query(1,1,n,node(-2,0,0)));
		}
		else{
			int x,y;
			x=read();y=read();
			swap(pos[p[x]],pos[p[y]]);
			swap(p[x],p[y]);
			
			modify(1,1,n,p[x]);
			modify(1,1,n,p[y]);
		}
	//	for (int i=1;i<=n;i++) assert(pos[p[i]]==i);
	}
	return ~~(0^_^0);
}