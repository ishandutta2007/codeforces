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
int n,m,i,j,x,mi=2147480000,s;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x>0) s+=x;
		if (x&1) mi=min(mi,abs(x));
	}
	if (s&1) cout<<s;
	else cout<<s-mi;
	return 0;
}