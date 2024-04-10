#include<cstdio>
#include<queue>
#include<algorithm>
#define N 1000010
using namespace std;
priority_queue<int>L;
priority_queue<int,vector<int>,greater<int> >R;
struct node{
	int x,y;
	void read(){scanf("%d%d",&x,&y);}
}p[N];
bool cmp(node a,node b){return a.x+a.y<b.x+b.y;}
int n,t,x,l,r;
long long ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) p[i].read();
	sort(p+1,p+n+1,cmp);
	L.push(p[1].x),R.push(p[1].x);
	for(int i=2;i<=n;i++)
	{
		t+=p[i].x+p[i].y-p[i-1].x-p[i-1].y;
		x=p[i].x;
		l=L.top(),r=R.top()+t;
		if(x<l) L.pop(),L.push(x),R.push(l-t),L.push(x),ans+=l-x;
		if(x>r) R.pop(),R.push(x-t),R.push(x-t),L.push(r),ans+=x-r;
		if(l<=x&&x<=r) L.push(x),R.push(x-t);
	}
	printf("%lld",ans);
}