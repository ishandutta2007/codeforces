#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,a[1000005],k=1e18;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++){
		if (n-i!=0)k=min(k,a[i]/(n-i));
		if (i-1!=0)k=min(k,a[i]/(i-1));
	}
	cout<<k<<endl;
	return 0;
}