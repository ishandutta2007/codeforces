#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 2e5 + 10;

int b[N], n, in[N];
ll a[N];
vector <int> g[N];

int main() {
	int T;
	//scanf ("%d", &T);
	T = 1;
	while (T--) {
		scanf ("%d", &n);
		rep(i, 1, n) scanf ("%lld", a + i);
		rep(i, 1, n) g[i].clear(), in[i] = 0;
		rep(i, 1, n) {
			scanf ("%d", b + i);
			if (b[i] != -1) in[b[i]]++;
		}
		ll res = 0;
		vector <int> st, en;
		queue <int> Q;
		rep(i, 1, n)
			if (!in[i]) Q.push(i);
		while (!Q.empty()) {
			int x = Q.front();
			Q.pop();
			res += a[x];
			if (b[x] != -1) {
				in[b[x]]--;
				if (!in[b[x]])
					Q.push(b[x]);
				if (a[x] > 0) {
					st.pb(x);
					a[b[x]] += a[x];
				}
				else {
					en.pb(x);
				}
			}
			else {
				st.pb(x);
			}
		}
		printf ("%lld\n", res);	
		for (auto u : st)
			printf ("%d ", u);
		reverse(all(en));
		for (auto u : en)
			printf ("%d ", u);
		printf ("\n");
	}
	return 0;
}