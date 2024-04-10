#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath> 
#define int long long
using namespace std;
int t,n,k,a[200005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for (int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=i;
		sort(a+1,a+1+n);
		int ans=1e18,sum=0;
		for (int i=0;i<=n;i++){
			sum+=a[i];
			if (n-i<=k)ans=min(ans,sum-i*(i+1)/2);
		}
		cout<<ans<<endl;
	}
	return 0; 
}