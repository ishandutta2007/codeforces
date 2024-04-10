#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	string s;
	cin >> s;
	for(int i = 0; i < int(s.size()) - 2; i++) {
		int x = s[i] - 'A', y = s[i + 1] - 'A', z = s[i + 2] - 'A';
		if((x + y) % 26 != z) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}