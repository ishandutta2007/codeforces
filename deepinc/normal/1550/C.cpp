#include<bits/stdc++.h>
using namespace std;
int a[233333];
int main(){
	int t; cin>>t; while(t--){
		int n,ans;
		scanf("%d",&n); ans=n+n-1;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=2;i<n;++i)if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
			else ans+=(a[i]<a[i-1]&&a[i]<a[i+1]);
		for(int i=2;i<n-1;++i)if(a[i]>a[i-1]&&a[i]>a[i+2]&&a[i+1]<a[i-1]&&a[i+1]<a[i+2])ans++;
			else ans+=a[i]<a[i-1]&&a[i]<a[i+2]&&a[i+1]>a[i-1]&&a[i+1]>a[i+2];
		printf("%d\n",ans);
	}
}