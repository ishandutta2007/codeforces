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
		vector<int>vec;
		int ans=(n*(n+1)*(n+2))/6;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			if(x==0){
				ans+=((i+1)*(n-i));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}