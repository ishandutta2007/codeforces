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
		char arr[n+1][n+1];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				cin>>arr[i][j];
			}
		}
		if(arr[1][2]==arr[2][1] && arr[n-1][n]==arr[n][n-1] && arr[1][2]!=arr[n-1][n]){
			cout<<0<<endl;
			continue;
		}
		if(arr[1][2]==arr[2][1] && arr[n-1][n]==arr[n][n-1] && arr[1][2]==arr[n-1][n]){
			cout<<2<<endl;
			cout<<n-1<<" "<<n<<endl;
			cout<<n<<" "<<n-1<<endl;
			continue;
		}
		if(arr[1][2]==arr[2][1] && arr[n-1][n]!=arr[n][n-1]){
			cout<<1<<endl;
			if(arr[n-1][n]==arr[1][2]){
				cout<<n-1<<" "<<n<<endl;
				continue;
			}
			else{
				cout<<n<<" "<<n-1<<endl;
				continue;
			}
		}
		if(arr[n-1][n]==arr[n][n-1] && arr[1][2]!=arr[2][1]){
			cout<<1<<endl;
			if(arr[1][2]==arr[n-1][n]){
				cout<<1<<" "<<2<<endl;
				continue;
			}
			else{
				cout<<2<<" "<<1<<endl;
				continue;
			}
		}
		if(arr[1][2]!=arr[2][1] && arr[n-1][n]!=arr[n][n-1]){
			cout<<2<<endl;
			if(arr[1][2]==arr[n-1][n]){
				cout<<n-1<<" "<<n<<endl;
				cout<<2<<" "<<1<<endl;
			}
			else{
				cout<<n<<" "<<n-1<<endl;
				cout<<2<<" "<<1<<endl;
				continue;
			}
		}
	}
	return 0;
}