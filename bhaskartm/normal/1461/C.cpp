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
		int n, k;
		cin>>n>>k;
		int arr[n];
		int maxi=-1;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]!=(i+1)){
				maxi=i;
			}
		}
		bool che=0;
		if(maxi==-1){
			che=1;
		}
		T ans=1;
		while(k--){
			int r;
			T p;
			cin>>r>>p;
			r--;
			if(r>=maxi){
				ans=ans*(1-p);
			}
		}
		if(che){
			cout<<1<<endl;
		}
		else{
			cout<<setprecision(20)<<1-ans<<endl;
		}
	}
	
	return 0;
}