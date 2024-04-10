#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int m = 1000000007;

int main()
{
	IO_OP;
	
	int n, x, y, tot = 0;
	cin >> n >> x >> y;
	vector<pi> v;
	int l, r;
	for(int i=0;i<n;i++) {
		cin >> l >> r;
		v.PB({l, r});
		tot += r - l;
		tot %= m;
	}
	sort(v.begin(), v.end());
	multiset<int> st;
	int ct = 0;
	for(int i=0;i<n;i++) {
		if(st.size()) {
			auto j = st.lower_bound(v[i].F);
			if (j != st.begin()) {
				--j;
				if(x <= 1LL * y*(v[i].F-*j)){
					ct++;
				} else {
					tot += v[i].F - *j;
					tot %= m;
					st.erase(j);
				}
			} else {
				ct++;
			}
		} else {
			ct++;
		}
		st.insert(v[i].S);
	}
	cout << (1LL * tot * y % m + 1LL * x * ct % m) % m << endl;
}