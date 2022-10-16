#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, N = 1e5 + 7;

vi d[N];
bool ok[8][8][8];

signed main()
{
	IO_OP;
	
	for(int a = 0; a < 8; a++)
		for(int b = 0; b < 8; b++)
			for(int c = 0; c < 8; c++) {
				int x[] = {a, b, c};
				vi p({0, 1, 2});
				do {
					bool yes = 1;
					for(int i = 0; i < 3; i++)
						yes &= x[p[i]] >> i & 1;
					if(yes) {
						ok[a][b][c] = 1;
						break;
					}
				} while(next_permutation(ALL(p)));
			}

	for(int i = 1; i < N; i++) {
		for(int j = i; j < N; j += i)
			d[j].PB(i);
	}
	int t;
	cin >> t;
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		vi tt, ttt;
		merge(ALL(d[a]), ALL(d[b]), back_inserter(tt));
		merge(ALL(tt), ALL(d[c]), back_inserter(ttt));
		swap(tt, ttt);
		tt.resize(unique(ALL(tt)) - tt.begin());
		int ans = 0;
		int cntl[8] = {}, cntr[8] = {};
		for(int& i:tt) {
			int mask = 0;
			if(a % i == 0) mask |= 1;
			if(b % i == 0) mask |= 2;
			if(c % i == 0) mask |= 4;
			i = mask;
			cntr[mask]++;
		}
		for(int m:tt) {
			cntl[m]++;
			for(int m1 = 0; m1 < 8; m1++)
				for(int m2 = 0; m2 < 8; m2++)
					if(ok[m][m1][m2])
						ans += cntl[m1] * cntr[m2];
			cntr[m]--;
		}
		cout << ans << '\n';
	}


}