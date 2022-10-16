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

const int INF = 1e9 + 7, N = 1e6 + 7;

vi G[1 << 13];
int pos[1 << 13];

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i = 0; i < (1 << 13); i++)
		pos[i] = n + 1;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		G[x].PB(i);
	}
	pos[0] = 0;
	for(int i = 0; i < (1 << 13); i++) if(G[i].size()) {
		V<pi> aux;
		for(int j = 0; j < (1 << 13); j++) if(pos[j] < n + 1)
			aux.EB(pos[j], j);
		sort(ALL(aux));
		int j = 0;
		for(auto&[position, val]:aux) {
			while(j < int(G[i].size()) && G[i][j] <= position)
				j++;
			if(j >= int(G[i].size()))
				break;
			pos[val ^ i] = min(pos[val ^ i], G[i][j]);
		}
	}
	int cnt = 0;
	for(int i = 0; i < (1 << 13); i++)
		if(pos[i] < n + 1)
			cnt++;
	cout << cnt << '\n';
	for(int i = 0; i < (1 << 13); i++)
		if(pos[i] < n + 1)
			cout << i << ' ';
	cout << '\n';

}