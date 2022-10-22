#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;		

const int nax = 1e5 + 111;

int T;
char s[nax];
char t[nax];

int a[nax][26];
int b[26];

void solve() {
	int n, m;
	scanf ("%s", s + 1);
	scanf ("%s", t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);
	
	FOR(i, 0, 25) b[i] = n + 1;
	
	for (int i = n; 0 <= i; --i) {
		FOR(j, 0, 25) a[i][j] = b[j];
		if (i)
			b[s[i] - 'a'] = i;
	}
	
	int ans = 0;
	int wsk = 1;
	while (true) {
		ans++;
		int pos = 0;
		int W = wsk;
		while (pos <= n) {
			if (m < wsk) break;
			int c = t[wsk] - 'a';
			if (a[pos][c] <= n) {
				wsk++;
			}
			pos = a[pos][c];
		}
		if (W == wsk) {
			printf ("-1\n");
			return;
		}
		if (m < wsk) break;
	}
	printf ("%d\n", ans);
}
		
	

int main() {	
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}