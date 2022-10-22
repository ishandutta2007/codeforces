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

const int N = 1e5 + 101;

int n;
int a[N];

bool in(int a, int b, int c) {
	if (a > c) swap(a, c);
	return a <= b && b <= c;
}

int main() {
	int T;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		vector <int> ans;
		rep(i, 1, n) 
			scanf ("%d", a + i);
		rep(i, 1, n) {
			while (ss(ans) >= 2 && in(a[ans[ss(ans) - 2]], a[ans.back()], a[i]))
				ans.pop_back();
			ans.pb(i);
		}
		printf ("%d\n", ss(ans));
		for (auto it : ans)
			printf ("%d ", a[it]);
		printf ("\n");
			
	}
		
	return 0;
}