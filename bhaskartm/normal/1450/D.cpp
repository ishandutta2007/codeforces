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
		int arr[n];
		vector<vector<int>>vec;
		vec.resize(n+1);
		for(int i=0; i<n; i++){
			cin>>arr[i];
			vec[arr[i]].pb(i);
		}
		int l[n];
		int r[n];
		stack<pair<int, int>>st;
		
		l[0]=-1;
		int val[n+1];
		for(int i=0; i<=n; i++){
			val[i]=0;
		}
		for(int i=0; i<n; i++){
			while(!st.empty() && st.top().f>=arr[i]){
				st.pop();
			}
			if(st.empty()){
				l[i]=-1;
				st.push({arr[i], i});
				continue;
			}
			l[i]=st.top().s;
			st.push({arr[i], i});
		}
		while(!st.empty()){
			st.pop();
		}
		for(int i=n-1; i>=0; i--){
			while(!st.empty() && st.top().f>=arr[i]){
				st.pop();
			}
			if(st.empty()){
				r[i]=n;
				st.push({arr[i], i});
				continue;
			}
			r[i]=st.top().s;
			st.push({arr[i], i});
		}
		for(int i=0; i<n; i++){
			int ran=r[i]-l[i]-1;
			val[arr[i]]=max(val[arr[i]], ran);
		}
		int mini=1e9;
		vector<int>ans;
		for(int i=1; i<=n; i++){
			mini=min(mini, val[i]);
			if(mini>=n-i+1){
				ans.pb(1);
			}
			else{
				ans.pb(0);
			}
		}
		reverse(ans.begin(), ans.end());
		for(auto u:ans){
			cout<<u;
		}
		cout<<endl;
	}
	return 0;
}