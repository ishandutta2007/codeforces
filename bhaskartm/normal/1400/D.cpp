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
		int ans=0;
		for(int i=1; i<n; i++){
			int cf[n+1];
			int cb[n+1];
			for(int i=0; i<=n; i++){
				cf[i]=0;
				cb[i]=0;
			}
			for(int j=i+1; j<n; j++){
				cf[arr[j]]++;
			}
			
			for(int j=1; j<i; j++){
				cb[arr[j-1]]++;
				ans+=(cb[arr[i]]*cf[arr[j]]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}