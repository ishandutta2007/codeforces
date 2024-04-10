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
long long n,m,i,j,k,a[1000005],s,t;
int main()
{
	cin>>n;
	for (i=1;i<=n;i++) scanf("%lld",&a[i]);
	i=j=1;
	while (j<=n)
	{
		 k=i=j;
		 while (a[i]==-1) i++;
		 j=i+1;
		 while (a[j]==-1) j++;
		 t=(a[j]-a[i])/(j-i);
		 if ((a[j]-a[i])%(j-i)||a[j]-(((a[j]-a[i])/(j-i))*(j-k))<1)
		 {
		 	s++;
		 	continue;
		 }
		 j++;
		 while (a[j]==-1||a[j]-a[j-1]==t)
		 {
		 	if (a[j]==-1) a[j]=a[j-1]+t;
		 	if (a[j]<1) {a[j]=-1;break;}
		 	j++;
		 }
		 s++;
	}
	cout<<s;
	return 0;
}