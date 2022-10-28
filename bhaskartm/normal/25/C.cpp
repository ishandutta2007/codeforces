#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int n;
	cin>>n;
	int arr[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	int k;
	cin>>k;
	while(k--){
		int u, v, w;
		cin>>u>>v>>w;
		u--;
		v--;
		int arr2[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				arr2[i][j]=arr[i][j];
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(i==j){
					continue;
				}
				int val=pow(10, 18);
				val=min(arr[i][j], w+arr[i][u]+arr[j][v]);
				val=min(val, w+arr[i][v]+arr[j][u]);
				arr2[i][j]=val;
			}
		}
		int ans=0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				arr[i][j]=arr2[i][j];
				ans+=arr[i][j];
			}
		}
		cout<<ans/2<<" ";
	}
	return 0;
}