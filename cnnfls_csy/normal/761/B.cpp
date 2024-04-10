#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
int n,m,i,j,k,l,a[55],b[55],c[55];
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	for (i=1;i<=n;i++) cin>>b[i];
	for (i=0;i<m;i++)
	for (l=1;l<=n;l++)
	{
		bool bo=1;
		for (j=1;j<=n;j++) c[j]=b[(j+l)%n+1]+i;
		int x=c[1]%m-a[1]%m;
		while (x<0) x+=m;
		for (k=2;k<=n;k++)
		{
			int y=c[k]%m-a[k]%m;
			while (y<0) y+=m;
			if (y!=x) {bo=0;break;}
		}
		if (bo) {cout<<"YES";return 0;}
	}
	cout<<"NO";
	return 0;
}