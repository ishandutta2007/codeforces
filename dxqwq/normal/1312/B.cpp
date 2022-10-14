#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int a[100003];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m;
		scanf("%d",&m);
		for(int i=1; i<=m; i++) scanf("%d",&a[i]);
		sort(a+1,a+m+1,cmp);
		for(int i=1; i<=m; i++) printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}