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
#define cint const int&
 
using namespace std;	

const int mod = 1e9 + 7;
const int nax = 2e5 + 101;

int T;
int n;
int a[nax];
int b[nax];

int main() {	
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		rep(i, 0, n-1) {
			scanf ("%d", a + i);
			b[i] = (i + a[i] % n + n) % n;
		}
		sort(b, b+n);
		bool ok = true;
		rep(i, 1, n - 1)
			ok &= b[i] != b[i-1];
		printf (ok == true ? "YES\n" : "NO\n");
	}
			
	
	return 0;
}