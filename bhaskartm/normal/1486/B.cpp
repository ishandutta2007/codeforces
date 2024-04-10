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
		int x[n];
		int y[n];
		vector<int>v1;
		vector<int>v2;
		for(int i=0; i<n; i++){
			cin>>x[i]>>y[i];
			v1.pb(x[i]);
			v2.pb(y[i]);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		if(n%2==1){
			cout<<1<<endl;
			continue;
		}
		cout<<(v1[(n/2)]-v1[(n-1)/2]+1)*(v2[(n/2)]-v2[(n-1)/2]+1)<<endl;
	}
	return 0;
}