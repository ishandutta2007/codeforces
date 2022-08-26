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
int n,m,a[105],i,j,t;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=m;i<=n;i++) if (a[i]<a[m]) break;
	t=i-1;
	while (a[t]==0&&t>0) t--;
	cout<<t;
	return 0;
}