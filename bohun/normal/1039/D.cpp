#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int nax = 100005;
int n, a, b;
vector <int> v[nax];
int ans[nax];
int ile[nax];

int dfs(int node, int par, int k) {
	//cout << " " << node << " " << k << endl;
	int res = 0;
	int A = 0, B = 0;
	for(auto it: v[node]) {
		if(it != par) {
			res += dfs(it, node, k);
			int C = ile[it] + 1;
			if(C > B)
				swap(B, C);
			if(B > A)
				swap(A, B);
		}
	}
	if(A + B >= k - 1) {
		res++;
		ile[node] = -1000005;
	}
	else {
		ile[node] = A;
	}
	return res;
}

void makedp(int l, int r, int optl, int optr) {
	if(l > r)
		return;
	int mid = (l + r) / 2;
	if(optl == optr) {
		for(int i = l; i <= r; ++i) {
			ans[i] = optl;
		}
		return;
	}
	ans[mid] = dfs(1, -1, mid);
	makedp(l, mid - 1, ans[mid], optr);
	makedp(mid + 1, r, optl, ans[mid]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i < n; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	makedp(1, n, 0, n);
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << endl;
	}
	
	
				
	
	
	return 0;
}