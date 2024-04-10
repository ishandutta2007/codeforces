#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

int T, a, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> a >> b;
		int res = b - a;
		rep(c, 0, b - a) {
			int x = a + c;
			int y = b;
			int flag = 0;
			int cur = c + 1;
			per(bit, 0, 20) {
				int X = (x >> bit & 1);
				int Y = (y >> bit & 1);
				if (X && !Y) {
					cur += 1 << bit;
					flag = 1;
				}
				if (Y && !X && flag)
					cur -= 1 << bit;
			}
			res = min(res, cur);
		}
		cout << res << endl;
	}

	return 0;
}