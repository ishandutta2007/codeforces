#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[103];
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1); 
	for(int i=1; i<=n; i+=2) printf("%d ",a[i]);
	if(n%2==1) n--;
	for(int i=n; i>=2; i-=2) printf("%d ",a[i]);
	return 0;
}