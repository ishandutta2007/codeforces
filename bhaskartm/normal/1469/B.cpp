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
		int pre[n+1];
		int maxi=0;
		pre[0]=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			pre[i+1]=pre[i]+arr[i];
			maxi=max(maxi, pre[i+1]);
		}
		int m;
		cin>>m;
		int arr2[m];
		int pre2[m+1];
		pre2[0]=0;
		int maxi2=0;
		for(int i=0; i<m; i++){
			cin>>arr2[i];
			pre2[i+1]=pre2[i]+arr2[i];
			maxi2=max(maxi2, pre2[i+1]);
		}
		cout<<maxi+maxi2<<endl;
	}
	return 0;
}