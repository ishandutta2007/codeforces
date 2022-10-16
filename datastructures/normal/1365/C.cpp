#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[200005],b[200005],pos[200005],cnt[200005],ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]),pos[b[i]]=i;
	for (int i=1;i<=n;i++){
		int j=pos[a[i]];
		if (j>=i)cnt[j-i]++;
		else cnt[j+n-i]++;
	}
	int ans=0;
	for (int i=0;i<n;i++)
		ans=max(ans,cnt[i]);
	cout<<ans<<endl;
	return 0;
}