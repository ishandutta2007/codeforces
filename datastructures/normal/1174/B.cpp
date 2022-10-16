#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,a[1000005],flag;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++){
		if (a[i]%2!=a[1]%2)flag=1;
	}
	if (flag==0){
		for (int i=1;i<=n;i++)printf("%I64d ",a[i]);
		return 0;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)printf("%I64d ",a[i]);
	return 0;
}