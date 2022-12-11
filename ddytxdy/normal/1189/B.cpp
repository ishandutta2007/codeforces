#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],ans[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	if(a[n]>=a[n-1]+a[n-2])puts("NO"),exit(0);
	puts("YES");
	ans[n]=a[n];
	for(int i=n-1;i>1;i--)ans[i]=a[i-1];
	ans[1]=a[n-1];
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}