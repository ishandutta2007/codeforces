/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n;
int a[N+1];
int cnt[20];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		for(int j=0;j<20;j++)if(a[i]&1ll<<j)cnt[j]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=0;j<20;j++)if(cnt[j])cnt[j]--,now|=1ll<<j;
		ans+=now*now;
	}
	cout<<ans;
	return 0;
}