#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=2040;

int n,m,T;
struct node{
	int t,x,y;
	bool operator < (const node &rhs) const{
		return t<rhs.t;
	}
}a[N];

node calc(node p,node q)
{
	node ret;
	ret.x=max(p.x,q.x);
	ret.y=min(p.y,q.y);
	ret.t=q.t;
	return ret; 
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int bl=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
		sort(a+1,a+n+1);
		node now; now.x=m,now.y=m,now.t=0;
		for(int i=1;i<=n;i++)
		{
			now.x-=(a[i].t-now.t); now.y+=(a[i].t-now.t);
			now=calc(now,a[i]);
			if(now.x>now.y)
			{
				bl=0;
				break;
			}
		} 
		if(!bl) puts("NO");
		else puts("YES");
	}
	return 0;
}