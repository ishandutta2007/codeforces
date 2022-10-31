#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <iostream>
using namespace std;
int main()
{
	int a[3000];
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=k;i++)ans+=a[i];
	printf("%d\n",ans);
}