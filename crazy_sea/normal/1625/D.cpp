#include<cstdio>
#include<algorithm>
#define M 10000010
#define N 3000010
using namespace std;
int cnt=1,f[N],lst[N],tr[M][2],t[M];
void getmax(int&a,int b)
{
	if(f[a]<f[b]) a=b;
}
const int B=30;
void insert(int x,int id)
{
	int now=1;
	for(int i=B;i>=0;i--)
	{
		bool y=(x&(1<<i));
		if(!tr[now][y]) tr[now][y]=++cnt;
		now=tr[now][y];
		getmax(t[now],id);
	}
}
int n,k;
struct node{
	int x,y;
}a[N];
bool cmp(node a,node b){return a.x<b.x;}
int query(int x)
{
	int ans=0,now=1;
	for(int i=B;i>=0;i--)
	{
		bool y=(x&(1<<i)),z=(k&(1<<i));
		if(z)
		{
			if(!tr[now][y^1]) return ans;
			now=tr[now][y^1];
		}
		else
		{
			getmax(ans,t[tr[now][y^1]]);
			now=tr[now][y];
		}
	}
	getmax(ans,t[now]);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].y=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		lst[i]=query(a[i].x),f[i]=f[lst[i]]+1,insert(a[i].x,i);
	int w=0;
	for(int i=1;i<=n;i++) getmax(w,i);
	if(f[w]==1){printf("-1");return 0;}
	printf("%d\n",f[w]);
	for(int i=w;i;i=lst[i]) printf("%d ",a[i].y);
}