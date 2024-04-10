#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,a[200005],book[200005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<n;i++)scanf("%lld",&a[i]);
		for (int i=0;i<n;i++)
			book[(i+a[i]%n+n)%n]++;
		int fg=1;
		for (int i=0;i<n;i++){
			if (book[i]>1)fg=0;
			book[i]=0;
		}
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}
// x+a[x%n]==y+a[y%n]