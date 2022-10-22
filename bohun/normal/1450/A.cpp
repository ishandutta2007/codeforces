#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
#define mp make_pair

using ll = long long;
using namespace std;

int t, n;
char s[205];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%s", &n, s + 1);
		sort(s + 1, s + n + 1);
		printf("%s\n", s + 1);
	}
	return 0;
}