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

const int N = 1010;

int n;
int a[N];
vector <pair<int, int>> ans;		
 
int main() {
	scanf ("%d", &n);
	vector <pair<int, int>>vals;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		vals.pb(mp(a[i], i));
	}
	sort(all(vals));
	rep(i, 0, n - 1)
		a[vals[i].se] = i + 1;
	per(i, 1, n) {
		vector <pair<int, int>> q;
		rep(j, 1, i)
			if (a[i] < a[j] && a[j] <= i) 
				q.pb({a[j], j});
		sort(all(q));
		for (auto it : q) {
			ans.pb({it.se, i});
			swap(a[it.se], a[i]);
		}
	}
	printf ("%d\n", ss(ans));
	for (auto it : ans)
		printf ("%d %d\n", it.fi, it.se);
	
	return 0;
}