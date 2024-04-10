#include<bits/stdc++.h>
using namespace std;
int t,a[150003],n;
int main(){
	cin>>t;
	while(t--){
		cin>>n; 
		for(int i=0;i<n;i++)cin>>a[i];
		int minn=2999900,ans=0;
		for(int i=n-1;i>=0;i--)
			if(minn<a[i])
				ans++;
			else
				minn=a[i];
		cout<<ans<<endl;
	}
}