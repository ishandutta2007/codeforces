#include <iostream>
#include <cstdio>
using namespace std;
int t,n,a[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		for (int i=1;i<=n;i++){
			if (a[i]==0)continue;
			int j=i;
			while(j<=n&&a[j]!=0)j++;
			ans++;
			i=j;
		}
		ans=min(ans,2);
		cout<<ans<<endl;
	}
	return 0;
}