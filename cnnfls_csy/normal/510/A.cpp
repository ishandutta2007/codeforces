#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a[105][105],n,m,i,j;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		if (i%2==1)
		for (j=1;j<=m;j++) cout<<'#';
		else if (i%4==0)
		{
			cout<<'#';
			for (j=2;j<=m;j++) cout<<'.';
		}
		else
		{
			for (j=1;j<m;j++) cout<<'.';
			cout<<'#';
		}
		cout<<endl;
	}
	return 0;
}