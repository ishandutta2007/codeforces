#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) cout << ([&] {
		int n, m;
		cin >> n >> m;
		V<pi> aux;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				char c;
				cin >> c;
				if(c == 'R') {
					aux.EB(i, j);
				}
			}
		sort(ALL(aux));
		for(auto[i, j]:aux) 
			if(i < aux[0].F || j < aux[0].S)
				return false;
		return true;

	}() ? "YES\n" : "NO\n");
}