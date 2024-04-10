#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n,m;
char mp[105][105];
int a[105][105];
int main()
{
	int i,j,k,l,op,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%s",mp[i]+1);
		for(j=1;j<=m;j++)
			if(mp[i][j]=='B')
				a[i][j]=1;
			else a[i][j]=-1;
	}
	for(i=n;i;i--)
		for(j=m;j;j--)
		{
			if(a[i][j]!=0)
			{
				ans++;
				op=-a[i][j];
				for(k=1;k<=i;k++)
					for(l=1;l<=j;l++)
						a[k][l]+=op;
			}
		}
	cout<<ans<<endl;
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);