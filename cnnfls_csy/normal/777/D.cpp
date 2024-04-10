#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
string a[500005];
int n,m,i,j;
int main()
{
	cin>>n;
	getline(cin,a[0]);
	for (i=1;i<=n;i++) getline(cin,a[i]);
	for (i=n;i>1;i--)
	{
		if (a[i]<a[i-1])
		{
			for (j=0;j<a[i-1].length();j++) 
			{
				if (j==a[i].length()||a[i][j]!=a[i-1][j])
				{
					a[i-1]=a[i-1].substr(0,j);
					break;
				}
			}
		}
	}
	for (i=1;i<=n;i++) cout<<a[i]<<endl;
	return 0;
}