#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define pb push_back
#define f first
#define s second
#define int long long int

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
		int b[n];
		int m1=1e10;
		int m2=1e10;
		for(int i=0; i<n; i++){
			cin>>a[i];
			m1=min(m1, a[i]);
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
			m2=min(m2, b[i]);
		}
		int ans=0;
		for(int i=0; i<n; i++){
			int d1=a[i]-m1;
			int d2=b[i]-m2;
			ans+=d1+d2-min(d1, d2);
		}
		cout<<ans<<endl;
	}
	return 0;
}