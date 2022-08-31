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
int n,m,i,j,num[200005],mx[200005],mi[200005];
string st;
char ss[200005];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&num[i]);
	scanf("%s",ss);
	st=ss;st=" "+st;
	for (i=1;i<=n;i++) mx[i]=max(mx[i-1],num[i]);
	mi[n+1]=1e9;
	for (i=n;i;i--) mi[i]=min(mi[i+1],num[i]);
	for (i=1;i<n;i++)
	{
		if (st[i]=='0')
		{
			if (mx[i]>mi[i+1])
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}