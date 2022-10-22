#include<cstdio>
#include<algorithm>
#define N 1000010
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
using namespace std;
int n,b[N];
void work(int*a)
{
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+m+1,a[i])-b;
}
struct node{
	int x,y,type,id;
}k[N],ANS;
struct node1{
	int x,s;
};
bool cmp(node a,node b)
{
	if(a.x==b.x) return a.type<b.type;
	else return a.x<b.x;
}
bool cmp1(node a,node b)
{
	if(a.x==b.x) return a.type<b.type;
	else return a.x>b.x;
}
struct seg{
	int t1[N<<2],t2[N<<2];
	node1 work(int l,int r,int s1,int s2,int now)
	{
		if(l==r)
		{
			if(min(s1,s2+t2[now])>=min(s1+t1[now],s2)) return (node1){l-1,min(s1,s2+t2[now])};
			else return (node1){l,min(s1+t1[now],s2)};
		}
		if(s1+t1[ls]>s2+t2[rs]) return work(l,mid,s1,s2+t2[rs],ls);
		else return work(mid+1,r,s1+t1[ls],s2,rs);
	}
	void modify(int l,int r,int now,int w,int a)
	{
		if(a==1) t1[now]++; else t2[now]++;
		if(l==r) return;
		if(w<=mid) modify(l,mid,ls,w,a);
		else modify(mid+1,r,rs,w,a);
	}
	void build(int l,int r,int now)
	{
		t1[now]=t2[now]=0;
		if(l==r) return;
		build(l,mid,ls);
		build(mid+1,r,rs);
	}
}t;
int ans;
namespace solver
{
	int sum,len,tt[5],x,y;
	void check(node1 xx,int s,int Y)
	{
		if(min(xx.s,s)>ans) ans=min(xx.s,s);
	}
	void solve1()
	{
		t.build(1,n,1);
		sort(k+1,k+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(k[i].type==3) sum--;
			else t.modify(1,n,1,k[i].x,k[i].type);
			if(k[i].x!=k[i+1].x) check(t.work(1,n,0,0,1),sum,k[i].x);
		}
	}
	void solve2()
	{
		t.build(1,n,1);
		sort(k+1,k+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(k[i].type==3) sum--;
			else t.modify(1,n,1,k[i].y,k[i].type);
			if(k[i].x!=k[i+1].x) check(t.work(1,n,0,0,1),sum,k[i].x);
		}
	}
	void solve3()
	{
		t.build(1,n,1);
		sort(k+1,k+n+1,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(k[i].type==3) sum--;
			else t.modify(1,n,1,k[i].y,k[i].type);
			if(k[i].x!=k[i+1].x) check(t.work(1,n,0,0,1),sum,k[i].x);
		}
	}
	void main()
	{
		sum=n/3,solve1();
		sum=n/3,solve2();
		sum=n/3,solve3();
	}
}
int a[7][4]={{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
int x[N],y[N],c[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
	work(x),work(y);
	for(int j=0;j<6;j++)
	{
		for(int i=1;i<=n;i++) k[i]=(node){x[i],y[i],a[j][c[i]-1],i};
		solver::main();
		for(int i=1;i<=n;i++) k[i]=(node){y[i],x[i],a[j][c[i]-1],i};
		solver::main();
	}
	printf("%d\n",ans*3);
}