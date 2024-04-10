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
int n,m,i,j,sum,ans,x;
int main()
{
	cin>>n>>m;
	ans=n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		sum+=x;
	}
	while (int(double(sum)/double(ans)+0.500000001)<m)
	{
		sum+=m;
		ans++;
	}
	cout<<ans-n;
	return 0;
}