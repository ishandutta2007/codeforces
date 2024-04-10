#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];	
	set<pair<int, pi>> s1;
	set<pair<pi, int>> s2;
	for(int i = 0; i < n;) {
		int j = i;
		while(i < n && a[i] == a[j]) i++;
		s1.insert({a[j], {j, i - 1}});
		s2.insert({{j, i - 1}, a[j]});
	}
	while(s1.size() > 1) {
		auto p = *s1.begin(); s1.erase(s1.begin());
		int l = p.S.F, r = p.S.S, val = p.F;
		if((r-l+1) & 1) {
			cout << "NO" << endl;
			return 0;
		}
		auto pos = s2.lower_bound({{l, r}, val});
		int l_v = INF, r_v = INF, l_l, l_r, r_l, r_r;
		if(pos != s2.begin()) {
			l_v = prev(pos)->S;
			l_l = prev(pos)->F.F;
			l_r = prev(pos)->F.S;
		} 
		if(next(pos) != s2.end()) {
			r_v = next(pos)->S;
			r_l = next(pos)->F.F;
			r_r = next(pos)->F.S;
		}
		s2.erase(pos);
		if(l_v < r_v) {
			int new_val = l_v, new_l = l_l, new_r = r;
			s1.erase({l_v, {l_l, l_r}});
			s2.erase({{l_l, l_r}, l_v});
			s1.insert({new_val, {new_l, new_r}});
			s2.insert({{new_l, new_r}, new_val});
		} else if(l_v > r_v) {
			int new_val = r_v, new_l = l, new_r = r_r;
			s1.erase({r_v, {r_l, r_r}});
			s2.erase({{r_l, r_r}, r_v});
			s1.insert({new_val, {new_l, new_r}});
			s2.insert({{new_l, new_r}, new_val});
		} else {
			int new_val = r_v, new_l = l_l, new_r = r_r;
			s1.erase({l_v, {l_l, l_r}});
			s2.erase({{l_l, l_r}, l_v});
			s1.erase({r_v, {r_l, r_r}});
			s2.erase({{r_l, r_r}, r_v});
			s1.insert({new_val, {new_l, new_r}});
			s2.insert({{new_l, new_r}, new_val});
		}

	}
	cout << "YES" << endl;
}