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
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		if(n==1){
			cout<<"T"<<endl;
			continue;
		}
		sort(arr, arr+n);
		int s1=0;
		for(int i=0; i<n-1; i++){
			s1+=arr[i];
		}
		if(arr[n-1]>s1){
			cout<<"T"<<endl;
			continue;
		}
		s1+=arr[n-1];
		s1=s1%2;
		if(s1){
			cout<<"T"<<endl;
		}
		else{
			cout<<"HL"<<endl;
		}
	}
	return 0;
}