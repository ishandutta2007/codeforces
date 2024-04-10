#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")
 
#define pb push_back
#define f first
#define s second
#define endl '\n'
#define int long long int


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k, z;
		cin>>n>>k>>z;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int maxi=0;
		int pre[n];
		pre[0]=arr[0];
		for(int i=1; i<n; i++){
			pre[i]=pre[i-1]+arr[i];
		}
		for(int i=0; i<=k; i++){
			maxi+=arr[i];
		}
		for(int i=1; i<n; i++){
			for(int j=1; j<=z; j++){
				int steps=i+1+2*(j-1);
				if(steps>k){
					continue;
				}
				int val= pre[i]+arr[i-1]+(j-1)*(arr[i]+arr[i-1])+pre[i-1+k-steps]-pre[i-1];
				maxi=max(maxi, val);
			}
		}
		cout<<maxi<<endl;
	}
	return 0;
}