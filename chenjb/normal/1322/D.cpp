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
using namespace std;
const int N=5010;
int n,m;
int l[N],s[N],c[N];
long long f[N][N],cnt[N];
void update(long long &x,long long y)
{
	x=max(x,y);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=n+m;i++)scanf("%d",&c[i]);
	for(int i=0;i<=m+n;i++)
		for(int j=0;j<=m+n;j++)
			f[i][j]=-2147483647;
	for(int i=1;i<=m+n;i++)f[i][0]=0;
	for(int i=n;i>=1;i--)
	{
		for(int k=cnt[l[i]];k>=0;k--)
		{
			long long w=f[l[i]][k]-s[i]+c[l[i]];
			//printf("%lld\n",w);
			update(f[l[i]][k+1],w);
		}
		cnt[l[i]]++;
		for(int j=0;j<=n+m;j++)
			for(int k=cnt[j];k>=0;k--)
				if (f[j][k]!=-2147483647)
				{
					long long w=f[j][k]+c[j+1]*(k>>1);
					//printf("%lld\n",w);
					update(f[j+1][k>>1],w);
					if(k/2>cnt[j+1])cnt[j+1]=(k>>1);
				}
	}
	cout<<f[n+m][0]<<endl;
	return 0;
}