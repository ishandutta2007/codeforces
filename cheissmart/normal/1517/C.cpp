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

const int INF = 1e9 + 7, N = 505;

int a[N][N];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i][i];

	for(int d = 0; d < n - 1; d++) {
		bool seen = false;
		for(int i = d; i < n; i++) {
			int j = i - d;
			if(a[i][j] - d == 1) 
				seen = true;
			else {
				if(!seen) a[i + 1][j] = a[i][j];
				else a[i][j - 1] = a[i][j];
			}
		}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j <= i; j++)
			cout << a[i][j] << " \n"[i == j];

}