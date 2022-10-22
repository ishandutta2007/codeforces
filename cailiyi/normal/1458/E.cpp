#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define N 100000
using namespace std;
int n,m,y[N+5],t[N+5],cnt;
bool ans[N+5],vis[N+5];
struct node
{
	int x,y,id;
	inline bool operator<(const node &_b) const
	{
		return x<_b.x || (x==_b.x && (y<_b.y || (y==_b.y && id<_b.id)));
	}
}a[N*2+5];
int main()
{
	auto add=[&](int x,int val)->void{for(;x<=cnt;x+=x&-x) t[x]+=val;};
	auto query=[&](int x)->int{int ret=0;for(;x;x-=x&-x) ret+=t[x];return ret;};
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d %d",&a[i].x,y+i),a[i].y=y[i];
	for(int i=1;i<=m;++i) scanf("%d %d",&a[i+n].x,&a[i+n].y),a[i+n].id=i;
	sort(a+1,a+1+n+m),sort(y+1,y+1+n),cnt=unique(y+1,y+1+n)-y-1;
	for(int i=1,lastx=-1,cntx=0;i<=n+m;++i)
		if(a[i].id)
		{
			if(a[i-1].x==a[i].x && a[i-1].y==a[i].y && (!a[i-1].id || ans[a[i-1].id])) ans[a[i].id]=1;
			else if(a[i].x!=lastx)
			{
				int p=upper_bound(y+1,y+1+cnt,a[i].y)-y-1;
				if((a[i].y!=y[p] || !vis[p]) && a[i].x-cntx==a[i].y-query(p)) ans[a[i].id]=1;
			}
		}
		else
		{
			int p=lower_bound(y+1,y+1+cnt,a[i].y)-y,_x=a[i].x-cntx,_y=a[i].y-query(p);
			if(_x<_y && !vis[p]) vis[p]=1,add(p,1);else if(_x>_y && lastx!=a[i].x) lastx=a[i].x,++cntx;
		}
	for(int i=1;i<=m;++i) puts(ans[i]?"LOSE":"WIN");
	return 0;
}