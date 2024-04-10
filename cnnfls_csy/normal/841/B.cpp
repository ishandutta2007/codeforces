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
int n,m,i,j,x;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>x;
		if (x&1)
		{
			cout<<"First";
			return 0;
		}
	}
	cout<<"Second";
	return 0;
}