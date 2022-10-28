
#include <bits/stdc++.h>
using namespace std;
#define int long long int
 main() {
	int n, k;
	cin>>n>>k;
	int arr[n];
	map<int, int>ml;
	map<int, int>mr;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		
	}
	sort(arr, arr+n);
	int arr2[n+1];
	arr2[0]=0;
	for(int i=1; i<=n; i++){
		arr2[i]=arr[i-1];
	}
	for(int i=1; i<=n; i++){
		mr[arr2[i]]=i;
		if(ml[arr2[i]]==0){
			ml[arr2[i]]=i;
		}
	}
	int pre[n+1];
	pre[0]=0;
	for(int i=1; i<=n; i++){
		pre[i]=pre[i-1]+arr2[i];
	}
	int mini=1e18;
	for(int i=1; i<=n; i++){
		int l=ml[arr2[i]];
		int r=mr[arr2[i]];
		if(r-l+1>=k){
			cout<<0;
			return 0;
		}
		int f=1e18;
		if(n-l+1>=k){
			f=pre[n]-pre[r]-(n-r)*(1+arr2[i])+(k-(r-l+1));
		}
		int b=1e18;
		if(r>=k){
			b=(l-1)*(arr2[i]-1)-(pre[l-1])+(k-(r-l+1));
		}
		int both=1e18;
		both=pre[n]-pre[r]-(n-r)*(1+arr2[i])+(l-1)*(arr2[i]-1)-pre[l-1]+(k-(r-l+1));
		mini=min(mini, f);
		mini=min(mini, b);
		mini=min(mini, both);
	}
	cout<<mini;
	return 0;
}