#include<cstdio>
#include<algorithm>
#include<cctype>
#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int n,q;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

struct Node{
	int mn,tg; ll S;
}node[1<<19];

inline void pushdown(int x,int l,int r){
	Node &A=node[x],&B=node[ls],&C=node[rs];
	if (!~A.tg) return;
	B.mn=B.tg=A.tg,B.S=1LL*A.tg*(mid-l+1);
	C.mn=C.tg=A.tg,C.S=1LL*A.tg*(r-mid);
	A.tg=-1;
}
inline void pushup(int x){
	node[x].mn=min(node[ls].mn,node[rs].mn);
	node[x].S=node[ls].S+node[rs].S;
}
void build(int x,int l,int r){
	node[x].tg=-1;
	if (l==r){
		node[x].mn=node[x].S=read();
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}

void modify(int x,int l,int r,int ql,int qr,int v){
	if (ql<=l&&r<=qr){
		node[x].tg=node[x].mn=v; node[x].S=1LL*v*(r-l+1);
		return;
	}
	pushdown(x,l,r);
	if (ql<=mid) modify(ls,l,mid,ql,qr,v);
	if (mid<qr) modify(rs,mid+1,r,ql,qr,v);
	pushup(x);
}
ll query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return node[x].S;
	pushdown(x,l,r);
	ll res=0;
	if (ql<=mid) res=query(ls,l,mid,ql,qr);
	if (mid<qr) res+=query(rs,mid+1,r,ql,qr);
	return res;
}

int pos;
void findfirst(int x,int l,int r,int v){
//	printf("findfirst %d %d %d  %d\n",x,l,r,v);
	if (l==r){
		if (node[x].mn<=v) pos=l;
		return;
	}
	pushdown(x,l,r);
	if (node[ls].mn<=v) findfirst(ls,l,mid,v);
	else findfirst(rs,mid+1,r,v);
}

void findsum(int x,int l,int r,ll S,ll T){  //base require
	if (l==r){
		if (S+node[x].S<=T) pos=l;
		return;
	}
	pushdown(x,l,r);
	if (S+node[ls].S<=T) pos=mid,findsum(rs,mid+1,r,S+node[ls].S,T);
	else findsum(ls,l,mid,S,T);
}

int main()
{
	n=read(),q=read();
	build(1,1,n);
	while (q--){
		int o=read(),x=read(),y=read();
		if (o==1){
			pos=-1; findfirst(1,1,n,y);
			if (pos==-1||pos>x) continue;
			modify(1,1,n,pos,x,y);
			continue;
		}
		int res=0;
		while (x<=n){
//			printf("check %d %d\n",x,y);
			pos=-1; findfirst(1,1,n,y);
			if (pos==-1) break;
			pos=max(pos,x); x=pos;
//			printf("find first pos %d\n",pos);
			ll S=y;
			if (pos>1) S+=query(1,1,n,1,pos-1);
			pos=-1; findsum(1,1,n,0,S);
//			printf("find last pos %d\n",pos);
			assert(~pos&&pos>=x);
			res+=pos-x+1; y-=query(1,1,n,x,pos);
			x=pos+1;
		}
		printf("%d\n",res);
	}
	return 0;
}