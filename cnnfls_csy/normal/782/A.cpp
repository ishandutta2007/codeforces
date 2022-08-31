#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
bool a[100005];
int n,m,i,j,s,ma; 
int main()
{
	cin>>n; 
	for (i=1;i<=n*2;i++)
	{
		cin>>m;
		if (a[m]) s--;
		else s++;
		a[m]=!a[m];
		ma=max(ma,s);
	}
	cout<<ma;
	return 0;
}