#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int g=0; g<t; g++){
		int n;
		cin>>n;
		long long int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int flag=0;
		if(arr[0]>0){
			flag=1;
		}
		long long int maxi=arr[0];
		long long int ans=0;
		for(int i=0; i<n; i++){
		
			
			if(flag==1 && arr[i]>0){
				maxi=max(arr[i], maxi);
				continue;
			}
			if(flag==0 && arr[i]<0){
				maxi=max(maxi, arr[i]);
				continue;
			}
			if(flag==1 && arr[i]<0){
				ans=ans+maxi;
				flag=0;
				maxi=arr[i];
				continue;
			}
			if(flag==0 && arr[i]>0){
				ans=ans+maxi;
				flag=1;
				maxi=arr[i];
				continue;
			}
		}
		ans=ans+maxi;
		cout<<ans<<endl;
	}
	return 0;
}