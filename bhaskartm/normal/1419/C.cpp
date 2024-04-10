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
		int n, x;
		cin>>n>>x;
		bool che=1;
		int arr[n];
		int sum=0;
		bool che2=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(arr[i]!=x){
				che=0;
			}
			if(arr[i]==x){
				che2=1;
			}
			sum+=arr[i];
		}
		if(che){
			cout<<0<<endl;
			continue;
		}
		if(sum==x*n || che2){
			cout<<1<<endl;
			continue;
		}
		cout<<2<<endl;
	}
	return 0;
}