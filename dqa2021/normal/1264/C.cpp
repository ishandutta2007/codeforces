#include<cstdio>
#include<algorithm>
#include<cctype>
#include<set>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
const int Mod=998244353;
typedef long long ll;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,m,w[200010]; int inv100;
bool mrk[200010];
#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	int a,b,c;
	int x,y;
}node[800010];
Node merge(Node x,Node y)
{
	Node res;
	res.a=1LL*x.a*y.a%Mod;
	res.b=(x.b+1LL*x.a*y.b)%Mod;
	res.c=(x.c+1LL*x.a*y.c)%Mod;
	
	res.x=(x.x+1LL*y.x*x.y)%Mod;
	res.y=1LL*x.y*y.y%Mod;
	return res;
}
void build(int cur,int l,int r)
{
	if (l==r)
	{
		node[cur]=(Node){w[l],(1-w[l])%Mod,1,0,1};
		return;
	}
	build(lson,l,mid); build(rson,mid+1,r);
	node[cur]=merge(node[lson],node[rson]);
}
void update(int cur,int l,int r,int pos,int x,int y)
{
	if (l==r) return node[cur].x=x,node[cur].y=y,void();
	if (pos<=mid) update(lson,l,mid,pos,x,y);
	else update(rson,mid+1,r,pos,x,y);
	node[cur]=merge(node[lson],node[rson]);
}
Node query(int cur,int l,int r,int ql,int qr)
{
	if (l==ql&&r==qr) return node[cur];
	if (qr<=mid) return query(lson,l,mid,ql,qr);
	if (ql>mid) return query(rson,mid+1,r,ql,qr);
	Node x=query(lson,l,mid,ql,mid),y=query(rson,mid+1,r,mid+1,qr);
	return merge(x,y);
}
set<int> st;
typedef set<int>::iterator It;
int main()
{
	inv100=qpow(100,Mod-2);
	
	n=read(),m=read();
	st.insert(n+1); st.insert(1); mrk[n+1]=1; mrk[1]=1;
	for (int i=1;i<=n;i++) w[i]=1LL*read()*inv100%Mod;
	build(1,1,n); Node tmp=query(1,1,n,1,n);
	update(1,1,n,1,1LL*tmp.c*qpow(1-tmp.b,Mod-2)%Mod,1LL*tmp.a*qpow(1-tmp.b,Mod-2)%Mod);
	It pre,suf;
	while (m--)
	{
		int x=read();
		if (mrk[x])
		{
			mrk[x]=0;
			st.erase(x);
			pre=suf=st.upper_bound(x);
			--pre;
			int u=*pre,v=(*suf)-1;
			
			update(1,1,n,x,0,1);
			tmp=query(1,1,n,u,v);
			update(1,1,n,u,1LL*tmp.c*qpow(1-tmp.b,Mod-2)%Mod,1LL*tmp.a*qpow(1-tmp.b,Mod-2)%Mod);
			
			tmp=query(1,1,n,1,n); printf("%d\n",(tmp.x+Mod)%Mod);
			continue;
		}
		mrk[x]=1;
		pre=suf=st.upper_bound(x); --pre;
		int u=*pre,v=(*suf)-1;
		
		tmp=query(1,1,n,u,x-1);
		//printf("tmp %d %d %d\n",tmp.a,tmp.b,tmp.c);
		update(1,1,n,u,1LL*tmp.c*qpow(1-tmp.b,Mod-2)%Mod,1LL*tmp.a*qpow(1-tmp.b,Mod-2)%Mod);
		tmp=query(1,1,n,x,v);
		update(1,1,n,x,1LL*tmp.c*qpow(1-tmp.b,Mod-2)%Mod,1LL*tmp.a*qpow(1-tmp.b,Mod-2)%Mod);
		//printf("tmp %d %d %d\n",tmp.a,tmp.b,tmp.c);
		
		st.insert(x);
		tmp=query(1,1,n,1,n); printf("%d\n",(tmp.x+Mod)%Mod);
	}
	return 0;
}