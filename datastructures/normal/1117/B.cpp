#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,a[1000005],m,k;
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	if (k>=m)cout<<a[n]*m<<endl;
	else{
		int cnt=m/(k+1);
		cout<<a[n-1]*cnt+a[n]*(m-cnt)<<endl;
		return 0;
	}
	return 0;
}