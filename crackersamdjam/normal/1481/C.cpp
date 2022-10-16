#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int t, n, m, a[MM], b[MM], c[MM], ans[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		map<int, vector<int>> mp, done;
		set<int> st;

		for(int i = 0; i < n; i++){
			cin>>b[i];
			if(a[i] == b[i]){
				done[b[i]].emplace_back(i);
			}
			else{
				mp[b[i]].emplace_back(i);
				st.insert(i);
			}
		}
		set<int> add;
		for(int i = 0; i < m; i++){
			cin>>c[i];
			if(size(mp[c[i]]) or size(done[c[i]])){
				add.insert(i);
			}
		}

		int bad = 0;

		for(int i = 0; i < m; i++){
			if(size(add) and *add.begin() == i)
				add.erase(i);
			
			if(size(mp[c[i]])){
				ans[i] = mp[c[i]].back();
				assert(st.count(ans[i]));
				st.erase(ans[i]);
				mp[c[i]].pop_back();
				done[c[i]].emplace_back(ans[i]);
			}
			else if(size(done[c[i]])){
				ans[i] = done[c[i]].back();
			}
			else{
				//draw on top of another
				if(size(st)){
					//overwrite not done one
					ans[i] = *st.begin();
				}
				else{
					//overwrite a good one
					if(size(add)){
						auto j = *add.begin();
						int v = c[j];
						assert(size(done[v]));
						int rm = done[v].back();
						done[v].pop_back();
						mp[v].emplace_back(rm);
						st.insert(rm);
						ans[i] = rm;
					}
					else{
						bad = 1;
					}
				}
			}
		}
		if(bad or size(st)){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
			for(int i = 0; i < m; i++)
				cout<<ans[i]+1<<' ';
			cout<<'\n';
		}
	}
}