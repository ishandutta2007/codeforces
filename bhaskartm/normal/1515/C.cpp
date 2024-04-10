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
		int n, m, x;
		cin>>n>>m>>x;
		int arr[n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		int h[m+1];
		for(int i=0; i<=m; i++){
			h[i]=0;
		}
		set<pair<int, int>>se;
		for(int i=1; i<=m; i++){
			se.insert({0, i});
		}
		cout<<"YES"<<endl;
		for(int i=0; i<n; i++){
			auto it=se.begin();
			int ind=(*it).s;
			cout<<ind<<" ";
			se.erase(it);
			h[ind]+=arr[i];
			se.insert({h[ind], ind});
		}
		cout<<endl;
	}
	return 0;
}