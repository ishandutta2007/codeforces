#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
void read(int &x)
{
	x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
}
typedef long long ll;

int n,m;
int w[200010];
ll tri[200010];
void modify(int x,int val)
{
	for (;x<=n;x+=(x&-x)) tri[x]+=val;
}
ll ask(int x)
{
	ll res=0;
	for (;x;x-=(x&-x)) res+=tri[x];
	return res;
}

#define mid (l+r>>1)
#define lson (cur<<1)
#define rson (cur<<1|1)
struct Node{
	int maxn;
}node[800010];
void build(int cur,int l,int r)
{
	if (l==r){node[cur].maxn=w[l];return;}
	build(lson,l,mid),build(rson,mid+1,r);
	node[cur].maxn=max(node[lson].maxn,node[rson].maxn);
}
void update(int cur,int l,int r,int pos)
{
//	printf("update %d %d %d %d\n",cur,l,r,pos);
	if (l==r){node[cur].maxn=w[l];return;}
	if (pos<=mid) update(lson,l,mid,pos);
	else update(rson,mid+1,r,pos);
	node[cur].maxn=max(node[lson].maxn,node[rson].maxn);
}
int dfs(int cur,int l,int r,ll val)
{
	if (l==r) return l;
	if (node[lson].maxn>=val) return dfs(lson,l,mid,val);
	return dfs(rson,mid+1,r,val);
}
int query(int cur,int l,int r,int ql,int qr,ll val)
{
//	printf("query %d %d %d %d %d\n",cur,l,r,ql,qr);
	if (l==ql&&r==qr)
	{
//		printf("query %d  %d  %d\n",l,node[cur].maxn,w[l]);
		if (node[cur].maxn>=val) return dfs(cur,l,r,val);
		return -1;
	}
	if (qr<=mid) return query(lson,l,mid,ql,qr,val);
	if (ql>mid) return query(rson,mid+1,r,ql,qr,val);
	int tmp=query(lson,l,mid,ql,mid,val);
	if (~tmp) return tmp;
	return query(rson,mid+1,r,mid+1,qr,val);
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=n;i++)
	{
		read(w[i]);
		tri[i]+=w[i];
		if (i+(i&-i)<=n) tri[i+(i&-i)]+=tri[i];
	}
	build(1,1,n);
	for (int i=1,x,y;i<=m;i++)
	{
		read(x);read(y);
		modify(x,-w[x]+y);
		w[x]=y;
		update(1,1,n,x);
		if (!w[1]){puts("1");continue;}
		ll sum=w[1]; int pos=2;
		bool flg=false;
		for (;pos<=n;)
		{
			int tmp=query(1,1,n,pos,n,sum);
//			printf("%d to %d %lld find %d\n",pos,n,sum,tmp);
			if (tmp==-1){break;}
			if (ask(tmp-1)==w[tmp])
			{
				printf("%d\n",tmp);
				flg=true;
				break;
			}
			sum=ask(tmp);
			pos=tmp+1;
		}
		if (!flg) puts("-1");
	}
	return 0;
}