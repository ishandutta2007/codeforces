#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 1005;

int t, n, m;
string s[MM];
array<int, 3> def = {INT_MAX, -1, -1};
array<int, 2> rs[MM];

array<int, 3> go(int x){
	if(x < 0 or x >= n) return def;
	auto ret = def;
	int lmax = -1e9;
	
	for(int j = 0; j < m; j++){
		int maxval = -1e9;
		for(int i = 0; i < n; i++){
			if(s[i][j] != 'B') continue;
			maxval = max(maxval, abs(x-i));
		}
		rs[j] = {maxval+j, j};
	}
	sort(rs, rs+m, greater<>());
	int ptr = 0;

	for(int j = 0; j < m; j++){
		for(int i = 0; i < n; i++){
			if(s[i][j] != 'B') continue;
			int val = abs(x-i);
			lmax = max(lmax, val-j);
		}
		while(rs[ptr][1] < j){
			ptr++;
			assert(ptr < m);
		}

		int most = max(j+lmax, rs[ptr][0]-j);
		ret = min(ret, {most, x, j});
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i = 0; i < n; i++){
			cin>>s[i];
		}
		int l = 0, r = n-1;
		auto ans = def;
		while(l <= r){
			int mid = l+r>>1;
			auto r1 = go(mid), r2 = go(mid+1);
			ans = min(ans, min(r1, r2));
			if(r1 < r2){
				r = mid-1;
			}
			else{
				l = mid+1;
			}
		}
		cout<<ans[1]+1<<' '<<ans[2]+1<<'\n';
		// pr(ans[0], ans[1], ans[2]);
		// pr("_________");
	}
}