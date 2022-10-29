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
		int arr[n];
		vector<int>po;
		vector<int>neg;
		vector<int>ze;
		int sum=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			sum+=arr[i];
			if(arr[i]>0){
				po.pb(arr[i]);
			}
			else if(arr[i]<0){
				neg.pb(arr[i]);
			}
			else{
				ze.pb(arr[i]);
			}
		}
		if(sum==0){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		if(sum>0){
			for(auto u:po){
				cout<<u<<" ";
			}
			for(auto u:neg){
				cout<<u<<" ";
			}
			for(auto u:ze){
				cout<<u<<" ";
			}
			cout<<endl;
			continue;
		}
		if(sum<0){
			for(auto u:neg){
				cout<<u<<" ";
			}
			for(auto u:po){
				cout<<u<<" ";
			}
			for(auto u:ze){
				cout<<u<<" ";
			}
			cout<<endl;
			continue;
		}
	}
	return 0;
}