// IOI 2021
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
 
////////////////////////////////////////////////////////////////////
 
const int N = 2e5 + 5;
 
int A[N], S[N], cnt;
vector<int> G[N];
 
int DFS(int m, int v, int p = 0) {
	int dp = 1, mx1 = 0, mx2 = 0; S[v] = 1;
	for (int u : G[v]) if (u != p) {
		int dpC = DFS(m, u, v);
		if (dpC == S[u]) dp += dpC;
		else if (mx1 < dpC) mx2 = mx1, mx1 = dpC;
		else if (mx2 < dpC) mx2 = dpC;
		S[v] += S[u];
	}
	if (A[v] < m) return 0;
	cnt = max(cnt, dp + mx1 + mx2);
	return dp + mx1;
}
 
int main() {
 
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	int r = 1;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 2; i <= n; i++) {
		int v, u; cin >> v >> u;
		G[v].push_back(u);
		G[u].push_back(v);
		if (A[i] < A[r]) r = i;
	}
	int dw = 0, up = INF;
	while (up - dw > 1) {
		int md = (dw + up) >> 1; cnt = 0;
		DFS(md, r);
		if (cnt >= k) dw = md;
		else up = md;
	}
	cout << dw << endl;
 
	return 0;
}