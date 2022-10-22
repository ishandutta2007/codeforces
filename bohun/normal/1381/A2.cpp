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

const int N = 1e5 + 101;

int T, n, a[N], b[N];
char s[N], t[N];

void solve() {
	scanf ("%d", &n);
	scanf ("%s %s", s + 1, t + 1);
	rep(i, 1, n) {
		a[i] = s[i] - '0';
		b[i] = t[i] - '0';
	}
	vector <int> ans;
	int cnt = 0;
	int p = 1, k = n;
	rep(i, 1, n) {
		int A = a[k] ^ cnt;
		int B = b[n - i + 1];
		
		if (A == B) {
			if (p < k) k--;
			else k++;
		}
		else {
			A = a[p] ^ cnt;
			if (A == B) 
				ans.pb(1);
			ans.pb(abs(k - p) + 1);
			//cat(abs(k - p) + 1);
			cnt ^= 1;
			if (p < k) {
				p++;
				swap(p, k);
			}
			else {
				p--;
				swap(p, k);
			}
		}
	}
	printf ("%d\n", ss(ans));
	for (auto u : ans)
		printf ("%d ", u);
	printf ("\n");
}			
			

int main() {	
	scanf ("%d", &T);
	while (T--)
		solve();
	
	return 0;
}