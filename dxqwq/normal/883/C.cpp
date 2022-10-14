#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
signed main()
{
	int f=read(),t=read(),t0=read();
	int a1=read(),t1=read(),p1=read();
	int a2=read(),t2=read(),p2=read();
	if(t0*f<=t)
	{
		puts("0");
		exit(0);
	}
	int ans=1000000000000000000ll;
	for(int i=0; ; i++)
	{
		if(min(i*a1,f)*t1>t) break;
		if(i*a1>=f)
		{
			ans=min(ans,i*p1);
			break;
		}
		else
		{
			int nowt=t-i*t1*a1,nowf=f-i*a1,nowc=p1*i;
			if(nowf*t0<=nowt) ans=min(ans,nowc);
			else if(t0>t2)
			{
				int mint=(nowf*t0-nowt-1)/(t0-t2)+1,minp=(mint-1)/a2+1;
				if(min(minp*a2,nowf)*t2+max(nowf-minp*a2,0ll)*t0<=nowt) 
				ans=min(ans,nowc+minp*p2); 
			}
		}
	}
	swap(t1,t2),swap(a1,a2),swap(p1,p2);
	for(int i=0; ; i++)
	{
		if(min(i*a1,f)*t1>t) break;
		if(i*a1>=f)
		{
			ans=min(ans,i*p1);
			break;
		}
		else
		{
			int nowt=t-i*t1*a1,nowf=f-i*a1,nowc=p1*i;
			if(nowf*t0<=nowt) ans=min(ans,nowc);
			else if(t0>t2)
			{
				int mint=(nowf*t0-nowt-1)/(t0-t2)+1,minp=(mint-1)/a2+1;
				if(min(minp*a2,nowf)*t2+max(nowf-minp*a2,0ll)*t0<=nowt) 
				ans=min(ans,nowc+minp*p2); 
			}
		}
	}
	if(ans==1000000000000000000ll) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}
/*
2 5 1000000
3 2 1
2 1 1000000
*/