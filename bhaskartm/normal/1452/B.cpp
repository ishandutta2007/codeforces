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
		sort(arr, arr+n);
		int cnt=0;
		for(int i=1; i<n; i++){
			cnt+=(arr[n-1]-arr[i]);
		}
		if(cnt>=arr[0]){
			cout<<cnt-arr[0]<<endl;
			continue;
		}
		
		arr[0]-=cnt;
		arr[0]=arr[0]%(n-1);
		if(arr[0]==0){
			cout<<0<<endl;
		}
		else{
			cout<<n-1-arr[0]<<endl;
		}
	}
	return 0;
}