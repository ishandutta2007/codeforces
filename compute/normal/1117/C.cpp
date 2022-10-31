#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=1e5+7;
char str[maxn];
int len;
int x1,y1;
int x2,y2;
long long dx=0,dy=0;
bool check(long long cur)
{
	long long lp=cur/len;
	long long remain=cur%len;
	long long ddx=lp*dx;
	long long ddy=lp*dy;
	for(int i=0;i<remain;i++)
	{
		if(str[i]=='U') ddy++;
		else if(str[i]=='D') ddy--;
		else if(str[i]=='L') ddx--;
		else ddx++;
	}
	long long dist=abs(x2-(x1+ddx))+abs(y2-(y1+ddy));
	dbg(cur);dbg(dist);
	return dist<=cur;
}
int main()
{
	scanf("%d%d",&x1,&y1);
	scanf("%d%d",&x2,&y2);
	scanf("%d",&len);
	scanf("%s",str);
	for(int i=0;i<len;i++)
	{
		if(str[i]=='U') dy++;
		else if(str[i]=='D') dy--;
		else if(str[i]=='L') dx--;
		else dx++;
	}
	long long l=0,r=1e14+7,ans=-1;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(check(mid)) r=mid,ans=mid;
		else l=mid+1;
	}
	printf("%lld\n",ans);
}