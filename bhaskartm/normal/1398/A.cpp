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
		if(arr[0]+arr[1]>arr[n-1]){
			cout<<-1<<endl;
			continue;
		}
		else{
			cout<<1<<" "<<2<<" "<<n<<endl;
			continue;
		}
	}
	
	return 0;
}