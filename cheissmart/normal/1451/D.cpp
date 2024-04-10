#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl

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
		ll d, k;
		cin >> d >> k;
		int i = 0;
		while(true) {
			i++;
			ll x = (ll) i / 2 * k, y = (ll) (i - i / 2) * k;
			if(x * x + y * y > d * d) break;
		}
		if(i & 1) cout << "Utkarsh" << endl;
		else {
			i = 0;
			while(true) {
				i++;
				ll x = (ll) i / 2 * k, y = (ll) (i - i / 2) * k;
				if(x == y) x--, y++;
				if(x * x + y * y > d * d) break;
			}
			if(i & 1) cout << "Utkarsh" << endl;
			else cout << "Ashish" << endl;
		}
	}

}