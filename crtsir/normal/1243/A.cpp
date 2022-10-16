#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a[1003],ans;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=n-1;i>=0;i--)
			ans=max(ans,min(n-i,a[i]));
		cout<<ans<<endl;
	}
}