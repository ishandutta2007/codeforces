#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int maxi=0;
	if(n==1){
		cout<<arr[0];
		return 0;
	}
	if(n==2){
		cout<<(arr[0] | arr[1]);
		return 0;
	}
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				int val1=(arr[i] | arr[j]);
				int val2=(val1 | arr[k]);
				maxi=max(maxi, val2);
			}
		}
	}
	cout<<maxi;
}