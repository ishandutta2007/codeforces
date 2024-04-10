#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5 + 100;

int n;
int p[N];
vector <int> v;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) p[i] = i;
	rep(i, 2, n) {
		if (p[i] == i)
			for (int j = i; j <= n; j += i)
				p[j] = min(p[j], i);
		v.pb(i / p[i]);
	}
	sort(all(v));
	for (auto it : v) printf ("%d ", it);
	
    return 0;
}