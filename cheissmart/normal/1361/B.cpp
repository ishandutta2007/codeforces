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
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e10, M = 1e9 + 7;

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b / 2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, p;
		cin >> n >> p;
		vi v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		if(p == 1) {
			cout << n%2 << endl;
			continue;
		}
		sort(ALL(v), greater<int>());
		int diff = 0, last = -1;
		bool too_big = false;
		for(int i:v) {
			if(last != -1 && diff != 0) {
				int mul = last - i;
				while(mul && !too_big) {
					diff *= p;
					mul--;
					if(diff >= INF) {
						diff %= M;
						too_big = true;
					}
				}
				if(too_big) diff %= M, diff = diff * qpow(p, mul) % M;
			}
			if(too_big || diff > 0) diff--;
			else diff++;
			last = i;
		}
		diff = (M + diff % M) % M;
		diff = diff * qpow(p, last) % M;
		cout << diff << endl;
	}
}