#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
const int INF=1e9;

int n,p[300010],q[300010],ip[300010];
#define ls (cur<<1)
#define rs (cur<<1|1)
#define mid (l+r>>1)
struct Node{
	int mx,tag;
}node[1048576];
void add(int &x,int y){
	if (x^(-INF)) x+=y;
}
void pushdown(int cur,int l,int r){
	if (!node[cur].tag) return;
	add(node[ls].mx,node[cur].tag); add(node[rs].mx,node[cur].tag);
	node[ls].tag+=node[cur].tag; node[rs].tag+=node[cur].tag;
	node[cur].tag=0;
}
void pushup(int cur){
	node[cur].mx=max(node[ls].mx,node[rs].mx);
}
void build(int cur,int l,int r){
	node[cur]=(Node){-INF,0};
	if (l==r) return;
	build(ls,l,mid); build(rs,mid+1,r);
}
void update(int cur,int l,int r,int ql,int qr,int val){
	if (ql<=l&&r<=qr){
		add(node[cur].mx,val); node[cur].tag+=val;
		return;
	}
	pushdown(cur,l,r);
	if (ql<=mid) update(ls,l,mid,ql,qr,val);
	if (mid<qr) update(rs,mid+1,r,ql,qr,val);
	pushup(cur);
}
void modify(int cur,int l,int r,int pos){
	if (l==r) return node[cur].mx=node[cur].tag,void();
	pushdown(cur,l,r);
	if (pos<=mid) modify(ls,l,mid,pos);
	else modify(rs,mid+1,r,pos);
	pushup(cur);
}
#undef ls
#undef rs
#undef mid
int main()
{
	n=read();
	for (int i=1;i<=n;i++) p[i]=read(),ip[p[i]]=i;
	for (int i=1;i<=n;i++) q[i]=read();
	build(1,1,n); update(1,1,n,1,ip[n],1); modify(1,1,n,ip[n]);
	for (int i=1,j=n;i<=n;i++){
		for (;j>1&&node[1].mx<=0;j--,update(1,1,n,1,ip[j],1),modify(1,1,n,ip[j]));
		printf("%d ",j);
		update(1,1,n,1,q[i],-1);
	}
	puts("");
	return 0;
}