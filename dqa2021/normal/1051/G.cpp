#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
void print(ll x)
{
	if (x>9) print(x/10); putchar(x%10+48);
}
void println(ll x)
{
	if (x<0) x=-x,putchar('-');
	print(x); putchar('\n');
}


int n; ll ans;
int fat[400010];
int find(int x)
{
	return x==fat[x]?x:fat[x]=find(fat[x]);
}
#define mid (l+r>>1)
struct Node{
	int lson,rson,siz; ll sum;
}node[200000*19+10];
int idtot,rt[400010];
void build(int &cur,int l,int r,int pos)
{
	node[cur=++idtot]=(Node){0,0,1,pos};
	if (l==r) return;
	if (pos<=mid) build(node[cur].lson,l,mid,pos);
	else build(node[cur].rson,mid+1,r,pos);
}
/*void pushup(int cur)
{
	node[cur].siz=node[node[cur].lson].siz+node[node[cur].rson].siz;
	node[cur].sum=node[node[cur].lson].sum+node[node[cur].rson].sum;
}*/
int mrg(int u,int v,int l,int r)  //u<-v
{
	if (!u||!v) return u|v;
	if (l^r)
	{
		ans+=node[node[u].lson].sum*node[node[v].rson].siz-node[node[v].rson].sum*node[node[u].lson].siz;
		node[u].siz+=node[v].siz; node[u].sum+=node[v].sum;
		node[u].lson=mrg(node[u].lson,node[v].lson,l,mid);
		node[u].rson=mrg(node[u].rson,node[v].rson,mid+1,r);
	}
	else node[u].siz+=node[v].siz,node[u].sum+=node[v].sum;
	return u;
}
/*ll query(int cur,int l,int r,int qr)
{
	if (l==r) return node[cur].sum;
	if (qr<=node[node[cur].lson].siz) return query(node[cur].lson,l,mid,qr);
	return node[node[cur].lson].sum+query(node[cur].rson,mid+1,r,qr-node[node[cur].lson].siz);
}*/
#undef mid
int main()
{
	n=read();
	for (int i=1,a,b;i<=n;println(ans),i++)
	{
		a=read(),b=read();
		if (fat[a])
		{
			find(a);
			int pos=fat[a]+node[rt[fat[a]]].siz;
			ans+=1LL*(pos-a)*b;
			a=pos;
		}
		fat[a]=a;
		build(rt[a],1,n,b);
		if (fat[a+1])
		{
			fat[a+1]=a;
			rt[a]=mrg(rt[a],rt[a+1],1,n);
		}
		if (fat[a-1])
		{
			fat[a]=a-1;
			find(a-1);
			rt[fat[a-1]]=mrg(rt[fat[a-1]],rt[a],1,n);
		}
	}
	return 0;
}