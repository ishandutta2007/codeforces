//Author:dead_X
#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int num=0;
    char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) num*=10,num+=ch-48,ch=getchar();
    return num;
}
long long a[1000003];
int n=read(),m=read();
bool check(long long x)
{
	int now=n; 
	long long t,tmp=a[now];
	for(int i=1; i<=m; i++)
	{
		t=x-now;
		while(tmp==0 && now) t-=tmp,tmp=a[--now];
		if(!now) return 1;
		while(t>=tmp && now) t-=tmp,tmp=a[--now];
		tmp-=t;
		if(!now) return 1;
	}
	return 0;
}
int main()
{	
	for(int i=1; i<=n; i++) a[i]=read();
	while(!a[n] && n) --n;
	if(!n) puts("0"),exit(0);
	// 
	long long l=1,r=1e18,ans=1e18;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1; else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}