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
		set<int>se;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			se.insert(x);
		}
		if(se.size()==n){
			cout<<"NO"<<endl;
			
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}