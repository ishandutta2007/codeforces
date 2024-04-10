#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int cnt[2000005][2],ans;
int n,a[1000005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]^=a[i-1];
	for (int i=1;i<=n;i++){
		ans+=cnt[a[i]][i%2];
		cnt[a[i-1]][(i-1)%2]++;
	}
	cout<<ans<<endl;
	return 0;
}
// s[mid]^s[l-1]=s[r]^s[mid]
// s[l-1]=s[r],2|(r-(l-1))