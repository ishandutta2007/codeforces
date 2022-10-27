#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef ONPC
  mt19937 rng(228);
#else
  mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

signed main() {
#ifndef ONPC
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
	
	int t;
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		int n;
		cin>>n;
		vector<int> a(n);
		for (int i=0;i<n;i++){
			cin>>a[i];	
		}	
		if(n%2==1){
			cout<<"-1\n";
			continue;
		}
		assert(n%2==0);
		vector<pair<int,int>>s;
		for (int i=0;i<n;i+=2){
			if(a[i]!=a[i+1]){
				s.push_back({i,i});
				s.push_back({i+1,i+1});
			}	else{
				s.push_back({i,i+1});
			}
		}
		cout<<(int)s.size()<<"\n";
		for (auto &it:s){
			cout<<it.first+1<<" "<<it.second+1<<"\n";	
		}
	}
	return 0;
}

 
/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */