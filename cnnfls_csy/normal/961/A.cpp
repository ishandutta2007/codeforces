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
int n,m,i,j,cnt[1005],ans,x; 
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		cin>>x;
		cnt[x]++;
	}
	ans=1<<25;
	for (i=1;i<=n;i++) ans=min(ans,cnt[i]);
	cout<<ans;
	return 0;
}