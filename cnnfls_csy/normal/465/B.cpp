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
int n,i,x,ans,last;
int main()
{
	cin>>n>>last;
	ans=last*2;
	for (i=2;i<=n;i++)
	{
		cin>>x;
		if (x) ans+=2-last;
		last=x;
	}
	cout<<max(ans-1,0);
	return 0;
}