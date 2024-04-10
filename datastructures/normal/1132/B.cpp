#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,m,a[300005],b[300005],sum;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]),sum+=a[i];
	sort(a+1,a+1+n);
	cin>>m;
	for (int i=1;i<=m;i++)scanf("%I64d",&b[i]);
	for (int i=1;i<=m;i++){
		printf("%I64d\n",sum-a[n-b[i]+1]);
	}
	return 0;
}