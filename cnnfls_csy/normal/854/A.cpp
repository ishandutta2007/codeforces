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
int n,m,i,j;
string st;
int main()
{
	cin>>n;
	for (i=n;i;i--)
	{
		j=n-i;
		if (i>=j) continue;
		if (__gcd(i,j)==1)
		{
			cout<<i<<' '<<j;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}