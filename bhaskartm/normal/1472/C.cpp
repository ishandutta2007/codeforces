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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int ans[n];
		ans[n-1]=arr[n-1];
		int maxi=ans[n-1];
		for(int i=n-2; i>=0; i--){
			if(i+arr[i]<n){
				ans[i]=arr[i]+ans[i+arr[i]];
			}
			else{
				ans[i]=arr[i];
			}
			maxi=max(maxi, ans[i]);
		}
		cout<<maxi<<endl;
	}
	return 0;
}