#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll c[100004],a[100004],b[100004];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>c[i];
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)cin>>b[i];
		for(int i=1;i<n;i++)if(a[i]>b[i])swap(a[i],b[i]);
		ll ans=0,cur=0;
		for(int i=1;i<n;i++){
			cur=max((a[i]<b[i]&&i>1)?cur+a[i]+c[i-1]-b[i]+1:0,b[i]-a[i]+1);
			ans=max(ans,cur+c[i]);
		}
		cout<<ans<<"\n";
	}
}