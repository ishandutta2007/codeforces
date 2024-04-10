#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,i,j,a[200005],b[200005],c[200005],s;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for (i=1;i<=n;i++)
	scanf("%d",&b[i]);
	for (i=1;i<=n;i++)
	c[i]=a[i]-b[i];
	for (i=1;i<=n;i++) s+=b[i];
	sort(c+1,c+n+1);
	for (i=1;i<=m;i++) s+=c[i];
	while (c[i]<0&&i<=n) {s+=c[i];i++;}
	cout<<s;
	return 0;
}