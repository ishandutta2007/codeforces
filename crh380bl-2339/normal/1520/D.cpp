#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int T,n,i,j,s;
	long long ans=0;
	scanf("%d",&T);while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			a[i]-=i;
		}
		sort(a+1,a+1+n);
		s=0;ans=0;
		for(i=1;i<=n;++i){
			if(i==1||a[i]!=a[i-1]){
				ans=ans+1LL*s*(s-1)/2LL;
				s=1;
			}
			else ++s;
		}
		ans=ans+1LL*s*(s-1)/2LL;
		printf("%lld\n",ans);
	}
	return 0;
}