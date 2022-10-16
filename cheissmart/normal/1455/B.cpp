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

	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		for(int i = 1; ; i++) {
			int cur = i * (i + 1) / 2;
			if(cur < x) continue;
			int need = cur - x;
			int sum = (2 + i + 1) * i / 2;
			if(need == 1 || need == sum - 1) continue;
			cout << i << '\n';
			break;
		}
	}

}