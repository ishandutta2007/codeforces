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
		int n, k;
		cin>>n>>k;
		int h[n];
		for(int i=0; i<n; i++){
			cin>>h[i];
		}
		int a=h[0];
		int b=h[0];
		bool che=1;
		for(int i=1; i<n; i++){
			int mini=h[i];
			int maxi=h[i]+k-1;
			mini=max(mini, a-k+1);
			maxi=min(maxi, b+k-1);
			a=mini;
			b=maxi;
			if(a>b){
				che=0;
			}
		}
		if(h[n-1]>=a && h[n-1]<=b && che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}