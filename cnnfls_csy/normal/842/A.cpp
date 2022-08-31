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
long long l,r,x,y,k,i;
int main()
{
	cin>>l>>r>>x>>y>>k;
	for (i=x;i<=y;i++)
	{
		if (i*k>=l&&i*k<=r)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}