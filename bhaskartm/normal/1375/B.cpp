#include <bits/stdc++.h>
using namespace std;
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
		int n, m;
		cin>>n>>m;
		int arr[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin>>arr[i][j];
			}
		}
		int arr2[n][m];
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				arr2[i][j]=4;
			}
		}
		for(int i=0; i<n; i++){
			arr2[i][0]=3;
			arr2[i][m-1]=3;
		}
		for(int i=0; i<m; i++){
			arr2[0][i]=3;
			arr2[n-1][i]=3;
		}
		arr2[0][0]=2;
		arr2[n-1][0]=2;
		arr2[0][m-1]=2;
		arr2[n-1][m-1]=2;
		bool b=1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]>arr2[i][j]){
					b=0;
				}
			}
		}
		if(b==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++){
					cout<<arr2[i][j]<<" ";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}