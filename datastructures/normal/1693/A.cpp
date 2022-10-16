#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath> 
#define int long long
using namespace std;
int t,n,a[200005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
		int fg=1;
		for (int i=1;i<n;i++){
			if (a[i]==0){
				for (int j=i+1;j<=n;j++)
					if (a[j]!=0)fg=0;
				break;
			}
			if (a[i]<0)fg=0;
			a[i+1]+=a[i];
			a[i]=0;
		}
		if (a[n]!=0)fg=0;
		if (fg==1)puts("Yes");
		else puts("No");
	}
	return 0;
}