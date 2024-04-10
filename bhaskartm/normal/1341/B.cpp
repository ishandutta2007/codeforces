#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n, k;
		cin>>n>>k;
		int arr[n+1];
		arr[0]=0;
		for(int i=1; i<=n; i++){
			cin>>arr[i];
		}
		int ans=0;
		for(int i=2; i<k; i++){
			if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
				ans++;
			}
		}
		int index=1;
		int maxi=ans;
		
		for(int i=2; i<=n-k+1; i++){
			ans=ans-(arr[i]>arr[i-1] && arr[i]>arr[i+1]);
			
			ans=ans+(arr[i+k-2]>arr[i+k-3] && arr[i+k-2]>arr[i+k-1]);
			
			
			if(ans>maxi){
				index=i;
				maxi=ans;
			}
		}
		cout<<maxi+1<<" "<<index<<endl;
	}
	return 0;
}