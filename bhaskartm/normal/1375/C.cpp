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
		}
		set<int>l;
		set<int>r;
		for(int i=0; i<n; i++){
			r.insert(arr[i]);
		}
		bool b=1;
		for(int i=0; i<n-1; i++){
			l.insert(arr[i]);
			r.erase(arr[i]);
			int mini=(*(l.begin()));
			auto it=r.end();
			it--;
			int maxi=(*it);
			if(mini>maxi){
				b=0;
			}
		}
		if(arr[0]>arr[n-1]){
			b=0;
		}
		if(b==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}