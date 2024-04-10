#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	int t;
	cin>>t;
	while(t--){
		int n , m , ans = 0;
		cin>>n>>m;
		vector<pair<int , int>> in(m);
		vector<int> add(m);
		for(int i = 0 ; i < m ; i++) cin>>in[i].first>>in[i].second;
		sort(in.begin() , in.end());
		vector<int> aa;
		for(auto i : in) aa.push_back(i.first);
		add[0] = in[0].first;
		for(int i = 1 ; i < m ; i++) add[i] = add[i - 1] + in[i].first;
		for(int i = 0 ; i < m ; i++){
			int mm = m , as = 0;
			auto it = lower_bound(aa.begin() , aa.end() , in[i].second) - aa.begin();
			// if(i > it) mm-- , as += in[i].first;
			// if(abs(it - i) > mm && i < mm) as += add[mm];
			// else if(abs(it - i) > mm && i >= mm) as += add[mm - 1] + in[i].first;
			// else if(i > it) as += add[it - 1] + in[i].first + in[i].second * (mm - it);
			// else as += add[it] + in[i].second * (mm - it);
			int cnt = m - it;
			if(cnt >= n) {
				as = add[m-1]-(m-n-1 >= 0 ? add[m-n-1] : 0);
			} else {
				as += add[m-1]-(it-1 >= 0 ? add[it-1] : 0);
				int need = n - cnt;
				if(i < it && !need);
				else {
					if(i < it) as += aa[i], need--;
					as += need * in[i].second;
				}
			}
			ans = max(ans , as);
		}
		cout<<ans<<endl;
	}
}