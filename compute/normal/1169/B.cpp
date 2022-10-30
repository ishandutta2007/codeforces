#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=3e5+7;
int a[maxn],b[maxn];
int n,m;
bool check(int x,int y)
{
	for(int i=0;i<m;i++)
		if(a[i]!=x&&a[i]!=y&&b[i]!=x&&b[i]!=y) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d",&a[i],&b[i]);
	int x=a[0],y=-1,pos=-1;
	bool ok=1;
	for(int i=1;i<m;i++)
	{
		if(a[i]!=x&&b[i]!=x)
		{
			pos=i;break;
		}
	}
	if(pos==-1) puts("YES");
	else{
		if(check(x,a[pos])||check(x,b[pos]))
			puts("YES");
		else{
			x=b[0];
			pos=-1;
			for(int i=1;i<m;i++)
			{
				if(a[i]!=x&&b[i]!=x)
				{
					pos=i;break;
				}
			}
			if(pos==-1) puts("YES");
			else {
				if(check(x,a[pos])||check(x,b[pos]))
					puts("YES");
				else puts("NO");
			}
		}
	}
}