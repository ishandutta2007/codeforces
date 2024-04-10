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
		vector<int>vec;
		
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			vec.pb(x);
		}
		
		int gc=0;
		for(int i=0; i<m; i++){
			int x;
			cin>>x;
			gc=__gcd(gc, x);
		}
		if(gc==1){
			int ans=0;
			for(auto u:vec){
				ans+=abs(u);
			}
			cout<<ans<<endl;
			continue;
		}
		vector<vector<int>>fin;
		for(int i=0; i<gc; i++){
			vector<int>temp;
			for(int j=i; j<n; j+=gc){
				temp.pb(vec[j]);
			}
			fin.pb(temp);
		}
		
		int ans=0;
		for(int i=0; i<fin.size(); i++){
			sort(fin[i].begin(), fin[i].end());
			for(int j=0; j+1<fin[i].size(); j+=2){
				ans+=abs(fin[i][j]+fin[i][j+1]);
			}
			int sz=fin[i].size();
			if(sz%2==1){
				ans+=fin[i].back();
			}
		}
		int ans2=0;
		for(int i=0; i<gc; i++){
			vec[i]=-vec[i];
		}
		fin.clear();
		for(int i=0; i<gc; i++){
			vector<int>temp;
			for(int j=i; j<n; j+=gc){
				temp.pb(vec[j]);
			}
			fin.pb(temp);
		}
		for(int i=0; i<fin.size(); i++){
			sort(fin[i].begin(), fin[i].end());
			for(int j=0; j+1<fin[i].size(); j+=2){
				ans2+=abs(fin[i][j]+fin[i][j+1]);
			}
			int sz=fin[i].size();
			if(sz%2==1){
				ans2+=fin[i].back();
			}
		}
		
		cout<<max(ans, ans2)<<endl;
	}
	return 0;
}