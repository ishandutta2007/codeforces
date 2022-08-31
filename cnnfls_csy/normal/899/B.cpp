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
int days[]={0,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31
,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int n,m,i,j,num[35];
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	for (i=1;i+n<=96;i++)
	{
		bool ok=1;
		for (j=1;j<=n;j++)
		{
			if (days[i+j]!=num[j])
			{
				ok=0;
				break;
			}
		}
		if (ok) {cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}