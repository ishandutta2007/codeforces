#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
 
 
int main() {
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
		if(n<=2){
			cout<<0<<endl;
			continue;
		}
		int ans=2;
		for(int i=0; i<n; i++){
			for(int j=0; j<i; j++){
				int cn=0;
				for(int k=0; k<n; k++){
					if((arr[j]-arr[i])*(k-j)==(arr[k]-arr[j])*(j-i)){
						cn++;
					}
				}
				ans=max(ans, cn);
			}
		}
		cout<<n-ans<<endl;
	}
	
	return 0;
}