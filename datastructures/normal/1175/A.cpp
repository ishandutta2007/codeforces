#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t,n,k,ans;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k;
        ans=0;
		while(n){
			ans+=n%k;
			n-=n%k;
			if (n==0)break;
			ans++;
			n/=k;
		}
		cout<<ans<<endl;
	}
	return 0;
}