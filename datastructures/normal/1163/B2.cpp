#include <iostream>
#include <cstdio>
using namespace std;
int n,a[100005],cnt[100005],cntcnt[100005],mx,ans;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cntcnt[cnt[a[i]]]--;
		cnt[a[i]]++;
		cntcnt[cnt[a[i]]]++;
		mx=max(mx,cnt[a[i]]);
		if (mx==1||cntcnt[mx]*mx==i-1||(cntcnt[mx-1]+1)*(mx-1)==i-1)ans=i;
	}
	cout<<ans<<endl;
	return 0;
}