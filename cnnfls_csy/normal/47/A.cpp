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
int n,m,i,j,t;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		t+=i;
		if (t==n) 
		{
		   cout<<"YES";
		   return 0;
        }
	}
	cout<<"NO";
	return 0;
}