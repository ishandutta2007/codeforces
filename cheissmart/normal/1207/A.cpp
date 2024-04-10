#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int b, p, f, h, c, ans = 0;
		cin >> b >> p >> f >> h >> c;
		if(h >= c) {
			int s = min(p, b/2);
			b -= s*2;
			ans += s * h;
			int s2 = min(f, b/2);
			ans += s2 * c;
		} else {
			int s = min(f, b/2);
			b -= s*2;
			ans += s * c;
			int s2 = min(p, b/2);
			ans += s2 * h;
		}
		cout << ans << endl;
	}	
	
}