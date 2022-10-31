#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int a[5100];
int f[5001][5001];
int ans[5001][5001];
int q;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)f[i][1]=a[i];
	for(int j=2;j<=n;j++)
		for(int i=1;i<=n-j+1;i++)
			f[i][j]=f[i][j-1]^f[i+1][j-1];

	for(int i=1;i<=n;i++)ans[i][1]=f[i][1];

	for(int j=2;j<=n;j++)
		for(int i=1;i<=n-j+1;i++)
			ans[i][j]=max(f[i][j],max(ans[i][j-1],ans[i+1][j-1]));


	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[l][r-l+1]);
	}
	return 0;
}