#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0);
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

const int INF = 1e9 + 7, N = 32768;

int d[N];

vi G[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0; i < N; i++) {
		G[(i + 1) % N].PB(i), G[i * 2 % N].PB(i);
		d[i] = -1;
	}
		
	queue<int> q({0}); d[0] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int v:G[u]) if(d[v] == -1) {
			d[v] = d[u] + 1;
			q.push(v);
		}
	}	
	for(int i = 0; i < n; i++) { int x; cin >> x; cout << d[x] << ' '; }	
}