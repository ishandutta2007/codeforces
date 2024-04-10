#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,x,y;
vector<int>v1,v2;
void sol(){
	cin>>n;
	v1.clear(),v2.clear();
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v1.push_back(x),v2.push_back(y);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	ll ans=1e18,cnt1=0,cnt2=0;
	for(int i=0;i<n;i++){
		ll num=0;
		for(int j=i-1;j>=0;j--)num+=v1[i]-v1[j];
		for(int j=i+1;j<n;j++)num+=v1[j]-v1[i];
		ans=min(ans,num); 
	}
	for(int i=0;i<n;i++){
		ll num=0;
		for(int j=i-1;j>=0;j--)num+=v1[i]-v1[j];
		for(int j=i+1;j<n;j++)num+=v1[j]-v1[i];
		if(num==ans){
			if(i==0||v1[i]!=v1[i-1])cnt1++;
			if(i>0&&v1[i]-v1[i-1]>1&&i==n-i)cnt1+=v1[i]-v1[i-1]-1;
		}
	}
	ans=1e18;
	for(int i=0;i<n;i++){
		ll num=0;
		for(int j=i-1;j>=0;j--)num+=v2[i]-v2[j];
		for(int j=i+1;j<n;j++)num+=v2[j]-v2[i];
		ans=min(ans,num); 
	}
//	cout<<ans<<"\n"; 
	for(int i=0;i<n;i++){
		ll num=0;
		for(int j=i-1;j>=0;j--)num+=v2[i]-v2[j];
		for(int j=i+1;j<n;j++)num+=v2[j]-v2[i];
		if(num==ans){
			if(i==0||v2[i]!=v2[i-1])cnt2++;
			if(i>0&&v2[i]-v2[i-1]>1&&i==n-i)cnt2+=v2[i]-v2[i-1]-1;
		}
	}
//	cout<<cnt1<<" "<<cnt2<<"\n";
	cout<<(ll)cnt1*cnt2<<"\n"; 
}
int main(){
	cin>>T;
	while(T--)sol();
}