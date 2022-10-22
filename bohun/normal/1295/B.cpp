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

char s[100111];

int n;
int x;

void solve() {
	scanf ("%d%d", &n, &x);
	scanf ("%s", s + 1);
	
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') sum++;
		else sum--;
	}
	LL ans = 0;
	if (x == 0) ans++;
	int e = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '0') e++;
		else e--;
		
		if (sum == 0 && e == x) {
			printf ("-1\n");
			return;
		}
		
		if (sum != 0 && (x - e) % abs(sum) == 0) {
			if ((x - e) / sum >= 0)
				ans++;
		}
	}
	printf ("%lld\n", ans);
}
		
		

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) {
		solve();
	}
		
	
	return 0;
}