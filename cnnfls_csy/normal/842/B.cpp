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
double a,b,x,y,r,dis,dis2;
int n,m,i,j,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin>>a>>b;
	b=a-b;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x>>y>>r;
		dis=sqrt(sqr(x)+sqr(y)); 
		if (dis+r<=a&&dis-r>=b) ans++;
	}
	cout<<ans;
	return 0;
}