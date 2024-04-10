#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define f first
#define s second
#define pb push_back

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>f;
		int val=-1;
		for(int i=1; i*i<=n; i++){
			if(n%i==0){
				f.pb(i);
				f.pb(n/i);
			}
		}
		sort(f.begin(), f.end());
		for(int i=0; i<f.size(); i++){
			if(f[i]<=(n/2)){
				val=f[i];
			}
		}
		cout<<val<<" "<<n-val<<endl;
	}
	return 0;
}