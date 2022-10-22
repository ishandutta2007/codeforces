#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;	

int n, a;
deque <int> q;
pair<int, int> mini[400005][19];
int ans = 0;
int lo[200005];

int fun(int L, int R) {
	if(L > R)
		return 0;
	if(L == R)
		return 1;
	int d = lo[R - L + 1];
	int pos = min(mini[L][d], mini[R - (1 << d) + 1][d]).se;
	assert(L <= pos && pos <= R);
	return 1 + max(fun(L, pos - 1), fun(pos + 1, R));
}
	

int main() {	
	FOR(i, 2, 200000)
		lo[i] = lo[i / 2] + 1;
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &a);
		q.push_back(a);
	}
	
	if(n <= 2) {
		printf("%d 0\n", n);
		return 0;
	}
	
	while(q.front() != 1) {
		ans += 1;
		int x = q.front();
		q.pop_front();
		q.push_back(x);
	}
	FOR(i, 1, n - 1) {
		mini[i][0] = mp(q[i], i);
	}
	FOR(j, 1, 18)
		FOR(i, 1, n - 1) {
			mini[i][j] = mini[i][j - 1];
			if(i + (1 << (j - 1)) <= n - 1)
				mini[i][j] = min(mini[i][j], mini[i + (1 << (j - 1))][j - 1]);
		}
	int l = 1;
	int r = n - 1;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(fun(1, m) <= fun(m + 1, n - 1))
			l = m;
		else
			r = m - 1;
	}
	
	pair<int, int> best = mp(n + 10, 0);
	best = min(best, mp(max(fun(1, r), fun(r + 1, n - 1)), ans + r + 1));
	r += 1;
	if(r <= n - 1)
		best = min(best, mp(max(fun(1, r), fun(r + 1, n - 1)), ans + r + 1));
	best.se %= n;
	best.fi += 1;
	cout << best.fi << " " << best.se << endl; 
	
	
	
			
		
	
	
	return 0;
}