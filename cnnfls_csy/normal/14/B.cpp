#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a[105],b[105],n,m,i,j,mi=2147480000,x;
bool ch(int x)
{
	for (int i=1;i<=n;i++)
	if (a[i]>x||b[i]<x) return 0;
	return 1;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) {cin>>a[i]>>b[i];if (a[i]>b[i]) swap(a[i],b[i]);}
	for (i=0;i<=1000;i++)
	if (ch(i)) mi=min(mi,abs(i-m));
	if (mi==2147480000) cout<<-1; else cout<<mi;
	return 0;
}