#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
 
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int,int> mp;
		for (int i = 1; i <= n; ++i) {
			int c; cin >> c;
			++mp[c];
		}
		set<int> s;
		for(auto i: mp)
			s.insert(i.second);

		int limit = *s.begin()+1;
		int most_frequent = *s.rbegin();
		int best = 0;

		for(int i=1;i<=limit;++i){
			for(int mul=1, last = 0;last<most_frequent;++mul){
				int r = i*mul, l = i*mul - mul;
				if(*s.lower_bound(last+1)<l) goto end;
				last = r;
			}
			best = i;
			end:;
		}
		int ans = 0;
		for(auto i:mp){
			ans += (i.second+best-1)/best;
		}
		cout << ans << '\n';
	}
}