#include<bits/stdc++.h>
using namespace std;
int t,n,a[100004];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		long long sum=0,cur=0,ans=0;
		for(int i=3;i<=n;i++){
			sum+=a[i-2],cur++;
			if(i>2)ans+=sum-cur*a[i];
		}
		printf("%I64d\n",ans);
	}
}