#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=1;i<n;i++)sum+=a[i];
	if(sum<1ll*a[n])return puts("NO"),0;
	puts(sum+a[n]&1?"NO":"YES");
	return 0;
}