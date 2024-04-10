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
		int arr[3];
		int sum=0;
		for(int i=0; i<3; i++){
			cin>>arr[i];
			sum+=arr[i];
		}
		sort(arr, arr+3);
		if(sum%9!=0){
			cout<<"NO"<<endl;
			continue;
		}
		int tu=(sum/9);
		if(arr[0]<tu){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
	return 0;
}