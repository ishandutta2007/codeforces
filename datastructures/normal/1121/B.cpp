#include <iostream>
#include <cstdio>
using namespace std;
int n,a[1005],cnt[200005];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)cnt[a[i]+a[j]]++;
	int ans=0;
	for (int i=1;i<=200000;i++)ans=max(ans,cnt[i]);
	cout<<ans<<endl;
	return 0;
}