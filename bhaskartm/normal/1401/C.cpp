#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

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
		int arrc[n];
		
		int mini=1e18;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			arrc[i]=arr[i];
			mini=min(mini, arr[i]);
		}
		sort(arrc, arrc+n);
		bool che=1;
		for(int i=0; i<n; i++){
			if(arr[i]%mini==0){
				continue;
			}
			if(arrc[i]!=arr[i]){
				che=0;
			}
		}
		if(che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}