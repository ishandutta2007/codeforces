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

int ask(vi a, vi b) {
	cout << "? " << a.size() << " " << b.size() << endl;
	for(int i:a) cout << i << " ";
	cout << endl;
	for(int i:b) cout << i << " ";
	cout << endl;
	string res;
	cin >> res;
	if(res == "FIRST") return 1;
	else if(res == "SECOND") return 2;
	else if(res == "EQUAL") return 0;
	else exit(0);
}

signed main()
{
	mt19937 rng(time(0));
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int cur = 1;
		for(int i = 0; i < 25; i++) {
			int nw;
			do {
				nw = rng() % n + 1;
			} while(nw == cur);
			int res = ask({cur}, {nw});
			if(res == 2) cur = nw;
		}
		vi v;
		v.PB(cur);
		for(int i = 1; i <= n; i++) if(i != cur) v.PB(i);
		int len = 1;
		while(len + len <= n) {
			vi a, b;
			for(int i = 0; i < len; i++) a.PB(v[i]);
			for(int i = len; i < len + len; i++) b.PB(v[i]);
			int res = ask(a, b);
			assert(res != 2);
			if(res == 1) break;
			len *= 2;
		}
		int rem = min(n - len, len);
		cur = 0;
		for(int i = 9; i >= 0; i--) {
			if(cur + (1 << i) <= rem) {
				int tmp = cur + (1 << i);
				vi a, b;
				for(int i = 0; i < tmp; i++) a.PB(v[i]), b.PB(v[i + len]);
				int res = ask(a, b);
				assert(res != 2);
				if(res == 0) cur = tmp;
			}
		}
		cout << "! " << v[len + cur] << endl;
	}		

}