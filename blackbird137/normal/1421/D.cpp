#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

int t,x,y,C1,C2,C3,C4,C5,C6;

signed main()
{
	t=read();
	while(t--)
	{
		x=read();y=read();
		C1=read();C2=read();C3=read();
		C4=read();C5=read();C6=read();
		int ans=1e19;
		if(x==0&&y==0) ans=0;
		else if(x<=0&&y<=0)
		{
			x=-x,y=-y;
			ans=min(ans,x*C3+y*C5);
			if(x>=y) ans=min(ans,y*C4+(x-y)*C3);
			else ans=min(ans,x*C4+(y-x)*C5);
			if(x>=y) ans=min(ans,x*C4+(x-y)*C2);
			else ans=min(ans,y*C4+(y-x)*C6);
		}
		else if(x<=0&&y>=0)
		{
			x=-x;
			ans=min(ans,x*C3+y*C2);
			ans=min(ans,x*C4+(x+y)*C2);
			ans=min(ans,y*C1+(x+y)*C3);
		}
		else if(x>=0&&y<=0)
		{
			y=-y;
			ans=min(ans,x*C6+y*C5);
			ans=min(ans,x*C1+(x+y)*C5);
			ans=min(ans,y*C4+(x+y)*C6);
		}
		else
		{
			ans=min(ans,x*C6+y*C2);
			if(x>=y) ans=min(ans,y*C1+(x-y)*C6);
			else ans=min(ans,x*C1+(y-x)*C2);
			if(x>=y) ans=min(ans,x*C1+(x-y)*C5);
			else ans=min(ans,y*C1+(y-x)*C3);
		}
		printf("%lld\n",ans);
	}
	return 0;
}