#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,a[105],i,s,ma;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) {cin>>a[i];ma=max(ma,a[i]);}
	for (i=1;i<=n;i++) s+=ma-a[i];
	cout<<s;
	return 0;
}