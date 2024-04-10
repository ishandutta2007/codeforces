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
		int n, k;
		cin>>n>>k;
		set<int>se;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			se.insert(x);
		}
		int sz=se.size();
		if(k==1 && sz==1){
			cout<<1<<endl;
			continue;
		}
		if(k==1 && sz>1){
			cout<<-1<<endl;
			continue;
		}
		int ans=0;
		while(1){
			if(sz<=k){
				ans++;
				break;
			}
			ans++;
			sz-=k;
			sz+=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}