#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int lo=1;
	int hi=n;
	int ans=1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		int arr2[n];
		int pre[n+1];
		int maxi[n+1];
		maxi[0]=0;
		pre[0]=0;
		bool che=0;
		for(int i=0; i<n; i++){
			if(arr[i]>=mid){
				arr2[i]=1;
				pre[i+1]=pre[i]+1;
			}
			else{
				arr2[i]=-1;
				pre[i+1]=pre[i]-1;
			}
			maxi[i+1]=min(maxi[i], pre[i+1]);
		}
		for(int i=k-1; i<n; i++){
			if(pre[i+1]>maxi[i-k+1]){
				che=1;
				break;
			}
		}
		if(che){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	cout<<ans;
	return 0;
}