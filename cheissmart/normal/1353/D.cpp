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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		set<array<int, 3>> s;
		vi v(n + 1);
		s.insert({n, -1, n});
		for(int i = 1 ; i <= n; i++) {
			auto p = *s.rbegin();
			s.erase(p);
			int l = -p[1], r = p[2];
			int mid = (l + r) / 2;
			v[mid] = i;
			if(mid - 1 >= l) s.insert({mid - 1 - l + 1, -l, mid - 1});
			if(mid + 1 <= r) s.insert({r - (mid + 1) + 1, -(mid + 1), r});
		}
		for(int i = 1; i <= n; i++) cout << v[i] << " ";
		cout << endl;
	}	
	
}