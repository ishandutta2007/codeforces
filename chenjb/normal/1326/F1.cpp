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
#define maxn 310000
#define bit(i) __builtin_popcount(i)
using namespace std;

unordered_map<int,long long> f[20000][15];

long long ans[maxn];
int flip[maxn],n,half;
char s[110][110];
long long fuck(int x)
{
	return flip[x]<<half;
}
int main()
{
	cin>>n;
	half=n/2;
	int full=(1<<n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)f[1<<(i-1)][i][0]=1;

	for(int i=1;i<(1<<(n-half-1));i++)
	{
		flip[i]=(flip[i>>1]>>1);
		if (i&1)flip[i]|=(1<<(n-half-2));
	} 
	for(int i=1;i<full;i++)
		if(bit(i)>1 && bit(i)<=max(n-half,half))
		{
			for(int j=1;j<=n;j++)
			if((1<<(j-1))&i)
			{
				int mask=i^(1<<(j-1));
				for(int k=1;k<=n;k++) 
				if ((1<<(k-1))&mask)
					for(auto p:f[mask][k])
					{
						int tmask=p.first;
						if (s[k][j]=='1')tmask+=(1<<(bit(i)-2));
						f[i][j][tmask]+=p.second;
					}
			}
		}

	

	for(int i=1;i<full;i++)
		if(bit(i)==half)
		{
			int mask=(full-1)^i;
			for(int j=1;j<=n;j++) 
				if ((1<<(j-1))&i)
					for(int k=1;k<=n;k++) 
						if ((1<<(k-1))&mask)
							for(auto p:f[i][j])
								for(auto q:f[mask][k])
								{
									int tmask=p.first+fuck(q.first);
									if (s[j][k]=='1')tmask+=(1<<(half-1));
									ans[tmask]+=p.second*q.second;
								}
		}

	for (int i=0;i<(1<<(n-1));i++)printf("%lld ",ans[i]);
	puts("");
	return 0;
}