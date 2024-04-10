#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define f first
#define s second
#define endl '\n'
int n, p;
int cnt[100005];
int pre[100005];

bool f(int val){
	bool che=1;
	int cnter=pre[val];
	
	while(val<100004){
		if(cnter>=p){
			che=0;
			break;
		}
		cnter--;
		val++;
		cnter+=cnt[val];
	}
	return che;
}
main() {
	
	cin>>n>>p;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	int maxi=arr[n-1]-1;
	int mini=0;
	for(int i=0; i<n; i++){
		mini=max(mini, arr[i]-i);
	}
	if(mini>maxi){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		if(arr[i]<mini){
			arr[i]=mini;
		}
	}
	for(int i=0; i<n; i++){
		arr[i]-=mini;
	}
	for(int i=0; i<n; i++){
		cnt[arr[i]]++;
	}
	pre[0]=cnt[0];
	for(int i=1; i<=100002; i++){
		pre[i]=pre[i-1]+cnt[i];
	}
	maxi-=mini;
	int lo=0;
	int hi=maxi;
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(f(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	if(ans==-1){
		cout<<0<<endl;
		return 0;
	}
	cout<<(ans+1)<<endl;
	for(int i=mini; i<=mini+ans; i++){
		cout<<i<<" ";
	}
	return 0;
}