#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a[200005],n,m,i,j;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n/2;i+=2)
	swap(a[i],a[n-i+1]);
	for (i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}