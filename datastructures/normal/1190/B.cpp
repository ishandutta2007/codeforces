#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,a[100005],samenum,sum;
signed main(){
	cin>>n;
	for (register int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for (register int i=2;i<=n;i++){
		if (a[i]==a[i-1]){
			if ((a[i-2]==a[i]-1&&i!=2)||a[i]==0)samenum=114514;
			else samenum++;
		}
	}
	if (samenum>1){
		puts("cslnb");
		return 0;
	}
	for (register int i=1;i<=n;i++)sum+=a[i]-(i-1);
	if (sum%2==0)puts("cslnb");
	else puts("sjfnb");
	return 0;
}