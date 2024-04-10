#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		int n;cin>>n;int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);int ans=100000007;
		for(int i=1;i<n;i++)ans=min(ans,a[i]-a[i-1]);
		cout<<ans<<endl;
	}
}