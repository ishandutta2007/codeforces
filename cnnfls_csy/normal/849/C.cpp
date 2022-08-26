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
int n,m,i,j,sum;
string st;
int main()
{
	cin>>n;
	for (i=1;i<=26;i++)
	{
		st+=(i+'a'-1);
		for (j=1;sum+j<=n;j++)
		{
			sum+=j;
			st+=(i+'a'-1);
		}
	}
	cout<<st;
	return 0;
}