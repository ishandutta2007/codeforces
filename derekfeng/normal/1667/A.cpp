#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5003];
ll ans=1e18;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		ll ret=0,cur;
		cur=0;
		for(int j=i-1;j;j--){
			ll tmp=(cur+a[j])/a[j];
			ret+=tmp,cur=tmp*a[j];
		}
		cur=0;
		for(int j=i+1;j<=n;j++){
			ll tmp=(cur+a[j])/a[j];
			ret+=tmp,cur=tmp*a[j];
		}
		ans=min(ans,ret);
	}
	printf("%lld",ans);
}