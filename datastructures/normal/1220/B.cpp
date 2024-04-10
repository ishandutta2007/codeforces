#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int n,a[1005][1005],ans[1005];
int qwq(int x){
	int l=1,r=1000000000,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (mid*mid>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
signed main(){
    cin>>n;
    for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	ans[1]=qwq(a[1][2]*a[1][3]/a[2][3]);
	for (int i=2;i<=n;i++)ans[i]=a[1][i]/ans[1];
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
    return 0;
}