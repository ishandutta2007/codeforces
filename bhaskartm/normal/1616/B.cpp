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
		string st;
		cin>>st;
		vector<pair<int, int>>vec;
		for(int i=0; i<n; i++){
			if(vec.empty() || vec.back().f!=(st[i]-'a')){
				vec.pb({st[i]-'a', 1});
			}
			else{
				int ba=vec.back().s;
				vec.pop_back();
				vec.pb({st[i]-'a', ba+1});
			}
		}
		
		if(vec[0].s>1){
			cout<<char(vec[0].f+'a')<<char(vec[0].f+'a')<<endl;
			continue;
		}
		string ans="";
		for(int i=0; i<vec[0].s; i++){
			ans+=char(vec[0].f+'a');
		}
		for(int i=1; i<vec.size(); i++){
			if(vec[i].f<vec[i-1].f){
				for(int j=0; j<vec[i].s; j++){
					ans+=char(vec[i].f+'a');
				}
			}
			else{
				break;
			}
		}
		string ans2=ans;
		reverse(ans2.begin(), ans2.end());
		ans+=ans2;
		cout<<ans<<endl;
		
	}
	
	return 0;
}