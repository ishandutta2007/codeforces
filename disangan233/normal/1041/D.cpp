#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
ll n,m;
struct data{
	long long l;long long r;
	friend bool operator < (const data &a,const data &b) {
		return a.l < b.l ;
	}
}kkksc[200010];
inline ll read()
{
	ll f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
ll num[200010],now[200010];
ll minn,ans;
int main() {
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) 
	{
		scanf("%lld%lld",&kkksc[i].l,&kkksc[i].r);
		num[i]=kkksc[i].l-kkksc[i-1].r;
		
		now[i]=now[i-1]+num[i];
	} 
	sort(kkksc+1,kkksc+n+1);
	if(m==0) 
	{
		
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		while(now[i]-now[minn]>=m) minn++;
		ans=max(ans,kkksc[i].r-kkksc[minn].l+(m-now[i]+now[minn]));
	}
	printf("%lld",ans);
	return 0; 
}