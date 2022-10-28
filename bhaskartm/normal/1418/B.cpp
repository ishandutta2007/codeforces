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
		int a[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int b[n];
		for(int i=0; i<n; i++){
			cin>>b[i];
		}
		vector<int>v;
		for(int i=0; i<n; i++){
			if(b[i]==0){
				v.pb(a[i]);
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int ans[n];
		int pt=0;
		for(int i=0; i<n; i++){
			if(b[i]==1){
				ans[i]=a[i];
			}
			else{
				ans[i]=v[pt];
				pt++;
			}
		}
		for(int i=0; i<n; i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}