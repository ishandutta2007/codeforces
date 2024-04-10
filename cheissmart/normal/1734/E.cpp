#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
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

const int INF = 1e9 + 7, N = 360;

int a[N][N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			a[i][j] = i * j % n;
		int diff; cin >> diff;
		diff = (diff - a[i][i] + n) % n;
		for(int j = 0; j < n; j++) {
			a[i][j] = (a[i][j] + diff) % n;
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	
}