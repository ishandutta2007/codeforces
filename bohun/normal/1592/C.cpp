#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (b); i >= (a); i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 2e5;
int n, k, a[N], res;
vector<int> e[N];

void dfs(int u, int p) {
    for (auto v : e[u])
	if (v != p) {
	    dfs(v, u);
	    a[u] ^= a[v];
	}
}

bool go(int u, int p) {
    int cnt = 0;
    for (auto v : e[u])
	if (v != p) {
	    cnt += go(v, u);
	}
    if (cnt >= 2)
	res = 1;
    if (cnt == 1 && a[u] == 0)
	res = 1;
    cnt = max(cnt, int(a[u] == a[1]));
    return !!cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--) {
	cin >> n >> k;
	rep(i, 1, n) {
	    cin >> a[i];
	    e[i].clear();
	}
	rep(i, 1, n - 1) {
	    int a, b;
	    cin >> a >> b;
	    e[a].push_back(b);
	    e[b].push_back(a);
	}
	dfs(1, 0);
	if (a[1] == 0) {
	    cout << "YES\n";
	    continue;
	}
	res = 0;
	go(1, 0);
	if (k == 2)
	    res = 0;
	cout << (res ? "YES\n" : "NO\n");
    }

    return 0;
}