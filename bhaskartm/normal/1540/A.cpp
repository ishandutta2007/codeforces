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
		int d[n];
		int pre[n];
		for(int i=0; i<n; i++){
			cin>>d[i];
		}
		if(n<=2){
			cout<<0<<endl;
			continue;
		}
		sort(d, d+n);
		pre[0]=0;
		for(int i=1; i<n; i++){
			pre[i]=pre[i-1]+d[i];
		}
		int ans=0;
		for(int i=2; i<n; i++){
			ans+=(d[i]*(i-1)-pre[i-2]);
		}
		cout<<-ans<<endl;
	}
	return 0;
}