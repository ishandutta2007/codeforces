#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,k,ans;
signed main(){
	cin>>n>>k;
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		int a=n-mid,b=k+mid;
		if (a*(a+1)/2ll>=b)ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}