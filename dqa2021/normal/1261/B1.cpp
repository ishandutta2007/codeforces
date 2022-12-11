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
	if (flg) x=-x;
	return x;
}

int n,m,w[200010];
int tri[200010];
void add(int x)
{
	for (;x<=n;x+=x&-x) tri[x]++;
}
int query(int x)
{
	int res=0;
	for (;x;x-=x&-x) res+=tri[x];
	return res;
}
int getans(int x)
{
	int l=1,r=n,mid;
	while (l<r)
	{
		mid=l+r>>1;
		if (query(mid)>=x) r=mid;
		else l=mid+1;
	}
//	printf("getans %d = %d\n",x,l);
	return w[l];
}
struct Rec{
	int val,pos;
}rec[200010];
bool operator<(const Rec x,const Rec y)
{
	if (x.val^y.val) return x.val>y.val;
	return x.pos<y.pos;
}
int ans[200010];
struct Qry{
	int id,k,pos;
}qry[200010];
bool operator<(const Qry x,const Qry y)
{
	return x.k<y.k;
}
int main()
{
	n=read();
	for (int i=1;i<=n;i++) w[i]=rec[i].val=read(),rec[i].pos=i;
	sort(rec+1,rec+n+1);
	m=read();
	for (int i=1;i<=m;i++) qry[i].id=i,qry[i].k=read(),qry[i].pos=read();
	sort(qry+1,qry+m+1);
	for (int i=1,j=0;i<=n;i++)
	{
		add(rec[i].pos);
		//printf("add %d\n",rec[i].pos);
		while (j<m&&qry[j+1].k==i) j++,ans[qry[j].id]=getans(qry[j].pos);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}