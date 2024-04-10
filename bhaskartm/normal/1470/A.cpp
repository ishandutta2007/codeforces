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
		int n, m;
		cin>>n>>m;
		vector<int>v;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			x--;
			v.pb(x);
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		int c[m];
		int pre[m+1];
		pre[0]=0;
		for(int i=0; i<m; i++){
			cin>>c[i];
			pre[i+1]=pre[i]+c[i];
		}
		int ans=0;
		for(int i=0; i<n; i++){
			ans+=c[v[i]];
		}
		int sum=0;
		int mini=ans;
		for(int i=0; i<min(n, m); i++){
			sum+=c[i];
			sum-=c[v[i]];
			mini=min(mini, sum+ans);
		}
		cout<<mini<<endl;
	}
	return 0;
}