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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
			if(i%2==0){
				arr[i]=abs(arr[i]);
			}
			else{
				arr[i]=-abs(arr[i]);
			}
		}
		for(int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}