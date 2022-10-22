#include <bits/stdc++.h>
#define ll long long
#define ld long double
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

const int N = 2e5 + 101;

int n;
char s[N];

void solve() {
	scanf ("%s", s + 1);
	n = strlen(s + 1);
	printf ("%c", s[1]);
	for (int i = 2; i < n; i += 2)
		printf ("%c", s[i]);
	printf ("%c", s[n]);
	printf ("\n");
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) solve();	
	return 0;
}