#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	int n;
	cin >> n;
	map<int, int> m;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		m[t]++;
	}
	multiset<int> s;
	for(auto p:m)
		s.insert(p.S);
	int ans = 0;
	for(int i=1;i<=*prev(s.end());i++) {
		vi v;
		int ct = 0;
		for(int j=i;;j*=2) {
			auto it = s.lower_bound(j);
			if(it != s.end()) {
				v.PB(*it);
				s.erase(it);
				ct += j;
			} else {
				break;
			}
		}
		for(int j:v)
			s.insert(j);
		ans = max(ans, ct);
	}
	cout << ans << endl;
}