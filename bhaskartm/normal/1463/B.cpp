#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9;
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
		int ans[n];
		int num=1;
		for(int i=0; i<n; i++){
			while(2*num<=arr[i]){
				num=num*2;
			}
			while(num>arr[i]){
				num=num/2;
			}
			if(2*num-arr[i]<=arr[i]-num){
				num=2*num;
			}
			if(num>N){
				num=num/2;
			}
			ans[i]=num;
		}
		for(int i=0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}