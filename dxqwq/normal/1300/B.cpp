#include<bits/stdc++.h>
using namespace std;
int a[1000003];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1; i<=2*n; i++) scanf("%d",&a[i]);
		sort(a+1,a+2*n+1);
		printf("%d\n",a[n+1]-a[n]);
	}
	return 0;
}