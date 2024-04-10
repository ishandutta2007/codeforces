#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int a[6],b[6],c[6],n,m,i,j,x,y,s;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++)
	{
	cin>>x;
	a[x]++;c[x]++;
	}
	for (i=1;i<=n;i++)
	{
	cin>>x;
	b[x]++;c[x]++;
	}
	for (i=1;i<=5;i++) if (c[i]%2) {cout<<-1;return 0;}
	for (i=1;i<=5;i++) s+=abs(c[i]/2-a[i]);
	cout<<s/2;
	return 0;
}