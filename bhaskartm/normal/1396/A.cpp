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
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<1<<" "<<1<<endl;
		cout<<-arr[0]<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		cout<<1<<" "<<1<<endl;
		cout<<0<<endl;
		return 0;
	}
	cout<<1<<" "<<n-1<<endl;
	vector<int>ans;
	for(int i=0; i<n-1; i++){
		int rem=((arr[i]%(n))+(n))%(n);
		ans.pb(rem*(n-1));
	}
	for(auto u:ans){
		cout<<u<<" ";
	}
	
	cout<<endl;
	for(int i=0; i<n-1; i++){
		arr[i]+=ans[i];
	}
	cout<<1<<" "<<n<<endl;
	for(int i=0; i<n-1; i++){
		cout<<-arr[i]<<" ";
	}
	cout<<0;
	cout<<endl;
	cout<<n<<" "<<n<<endl;
	cout<<-arr[n-1];
	return 0;
}