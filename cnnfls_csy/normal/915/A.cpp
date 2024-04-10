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
int n,m,i,j,ans=1<<30,x;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (m%x==0) ans=min(ans,m/x);
	}
	cout<<ans;
	return 0;
}