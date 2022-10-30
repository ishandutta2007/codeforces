#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define left lef
#define right righ
#define rep(i,n) for(int i=1;i<=n;++i)
#define inf 998244353
#define maxn 2100000
using namespace std;
char s[maxn];
int ss[maxn];
int p[maxn];
int n;
int ans=0,ansp=0;
void manacher()
{
	ss[0]=-134527;
	for(int i=1;i<=n;i++)ss[i*2-1]=-1,ss[i*2]=s[i]-'a';
	ss[n*2+1]=-1; ss[n*2+2]=-3452;
	int mx=1,ansp=1; p[1]=1;
	for (int i=2;i<n*2+2;i++)
	{
		p[i]=(i>mx)?1:min(mx-i+1,p[ansp*2-i]);
		while (ss[i-p[i]]==ss[i+p[i]])p[i]++;
		if (i+p[i]-1>mx) mx=i+p[i]-1,ansp=i;
	}
}
void print()
{
	int half,l,r;
	if (ansp%2==0)half=p[(ansp/2)*2]/2; else half=p[(ansp/2)*2+1]/2;
	l=ansp/2-half+1;
	r=ansp/2+half-1;
	if (ansp%2)r++;
	if (l-1<=n-r)
	{
		for(int i=1;i<=l-1;i++)putchar(s[i]);
		for(int i=l;i<=r;i++)putchar(s[i]);
		for(int i=n-(l-1)+1;i<=n;i++)putchar(s[i]);
		puts("");
	}
	else
	{
		for(int i=1;i<=n-r;i++)putchar(s[i]);
		for(int i=l;i<=r;i++)putchar(s[i]);
		for(int i=n-(n-r)+1;i<=n;i++)putchar(s[i]);
		puts("");
	}
}
int match[maxn];
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		match[0]=1;
		for(int i=1;i<=n;i++)
		{
			match[i]=match[i-1];
			if (s[i]!=s[n-i+1])match[i]=0;
		}
		manacher();
		ans=0;
		ansp=0;
		int half,l,r;
		for(int i=1;i<=n;i++)
		{
			half=p[i*2]/2;
			l=i-half+1;
			r=i+half-1;
			if(l-1<=n-r)
			{
				if(match[l-1] && (l-1)*2+half*2-1>ans)
					ans=(l-1)*2+half*2-1,ansp=i*2;
			}
			else
			{
				if(match[n-r] && (n-r)*2+half*2-1>ans) 
					ans=(n-r)*2+half*2-1,ansp=i*2;
			}
		}
		for(int i=1;i<n;i++)
		{
			half=p[i*2+1]/2;
			l=i-half+1;
			r=i+half;
			if (l-1<=n-r)
			{
				if(match[l-1] && (l-1)*2+half*2>ans) 
					ans=(l-1)*2+half*2,ansp=i*2+1;
			}
			else
			{
				if(match[n-r] && (n-r)*2+half*2>ans) 
					ans=(n-r)*2+half*2,ansp=i*2+1;
			}
		}
		print();
	}
}