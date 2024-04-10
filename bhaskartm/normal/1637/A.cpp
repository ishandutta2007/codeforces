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
		vector<int>v1;
		vector<int>v2;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v1.pb(x);
			v2.pb(x);
		}
		sort(v2.begin(), v2.end());
		bool b=1;
		for(int i=0; i<n; i++){
			if(v1[i]!=v2[i]){
				b=0;
			}
		}
		if(b){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}