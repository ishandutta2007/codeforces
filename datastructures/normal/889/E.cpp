#include <iostream>
#include <cstdio>
#include <map>
#define int long long
using namespace std;
map<int,int> dp;
int n,a[200005],ans;
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	dp[a[1]-1]=0;
	for (int i=2;i<=n;i++){
		map<int,int>::iterator it,_it;
		it=dp.lower_bound(a[i]);
		while(it!=dp.end()){
			int j=it->first,val=it->second;
			dp[j%a[i]]=max(dp[j%a[i]],val+(j-j%a[i])*(i-1));
			dp[a[i]-1]=max(dp[a[i]-1],val+(((j-(a[i]-1))/a[i])*a[i])*(i-1));
			_it=it;
			it++;
			dp.erase(_it);
		}
	}
	map<int,int>::iterator it;
	for (it=dp.begin();it!=dp.end();it++)ans=max(ans,n*(it->first)+(it->second));
	cout<<ans<<endl;
	return 0;
}