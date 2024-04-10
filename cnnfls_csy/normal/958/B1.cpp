#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,cnt[1005],x,y,ans;
int main()
{
	cin>>n;
	for (i=1;i<n;i++)
	{
		cin>>x>>y;
		cnt[x]++;
		cnt[y]++;
	}
	for (i=1;i<=n;i++) if (cnt[i]==1) ans++;
	cout<<ans;
	return 0;
}