#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N];
int main()
{
	scanf("%d",&n);
	int l=1,r=n+1;
	for (int i=1;i<n;i++)
		if (i&1) a[l]=i,a[l+n-i]=i,l++;
		else a[r]=i,a[r+n-i]=i,r++;
	for (int i=1;i<=n*2;i++) printf("%d ",(a[i]?a[i]:n));
}