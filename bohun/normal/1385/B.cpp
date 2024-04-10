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

const int N = 111;

int n;
int a[N];

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		n += n;
		rep(i, 1, n) 
			scanf ("%d", a + i);
		vector <int> ans;
		int j = 0;
		rep(i, 1, n) {
			if (j < ss(ans) && ans[j] == a[i]) {
				j++;
				continue;
			}
			ans.pb(a[i]);
		}
		for (auto it : ans) printf ("%d ", it);
		printf ("\n");
	}
	return 0;
}