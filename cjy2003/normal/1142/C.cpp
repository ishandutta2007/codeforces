#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct point
{
	long long x,y;
	point(long long xx=0,long long yy=0){x=xx,y=yy;}
	friend bool operator < (point a,point b)
	{
		if(a.x!=b.x)return a.x<b.x;	
		return a.y<b.y;
	}
	friend long long operator ^ (point a,point b){return a.x*b.y-a.y*b.x;}
	friend point operator - (point a,point b){return point(a.x-b.x,a.y-b.y);}
}p[100010];
int n,st[100010],tp,ans,sta;
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	long long x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%I64d %I64d",&x,&y);
		y-=x*x;
		p[i]=point(x,y);	
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;++i)
	{
		while(tp>1&&((p[i]-p[st[tp-1]])^(p[st[tp]]-p[st[tp-1]]))<=0)--tp;
		st[++tp]=i;	
	}
//	printf("%d\n",tp);
	sta=1;
	while(p[st[sta]].x==p[st[sta+1]].x&&sta<tp)++sta;
	printf("%d",tp-sta);
	return 0;
}