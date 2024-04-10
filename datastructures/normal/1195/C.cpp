#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,a[100005][2],f[100005][2];
signed main(){
	cin>>n;
	for (int j=0;j<2;j++)
		for (int i=1;i<=n;i++)
			scanf("%I64d",&a[i][j]);
	for (int i=1;i<=n;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]+a[i][0]);
		f[i][1]=max(f[i-1][1],f[i-1][0]+a[i][1]);
	}
	cout<<max(f[n][0],f[n][1])<<endl;
	return 0;
}