#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
set<pair<int, int>>se[2];
vector<pair<int, pair<int, int>>>v;
int main() {
	int n;
	cin>>n;
	int l[n], r[n], t[n];
	for(int i=0; i<n; i++){
		cin>>l[i]>>r[i]>>t[i];
		t[i]--;
		v.pb({l[i], {0, i}});
		v.pb({r[i], {1, i}});
	}
	sort(v.begin(), v.end());
	int ans=0;
	for(auto u:v){
		int ind=u.s.s;
		int ty=t[u.s.s];
		if(u.s.f){
			if(se[ty].count({r[ind], ind}) && !se[1-ty].empty()){
				se[1-ty].erase(se[1-ty].begin());
				ans++;
			}
			if(se[ty].count({r[ind], ind})){
				se[ty].erase({r[ind], ind});
			}
		}
		else{
			se[ty].insert({r[ind], ind});
		}
	}
	cout<<n-ans<<endl;
	return 0;
}