#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

 
 
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
		for(int i=0; i<2*n; i++){
			int x, y;
			cin>>x>>y;
			x=abs(x);
			y=abs(y);
			if(x>0){
				v1.pb(x);
			}
			else{
				v2.pb(y);
			}
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		T ans=0;
		for(int i=0; i<n; i++){
			ans+=sqrt(v1[i]*v1[i]+v2[i]*v2[i]);
		}
		cout<<setprecision(20)<<ans<<endl;
	}
	return 0;
}