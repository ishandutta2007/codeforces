#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int nax = 2e5 + 111;
const int pod = (1 << 18);

int T;
int n, m;
int mon[nax];
pair <int, int> her[nax];
int maks[nax];

int t[2 * pod];

void add(int x, int c) {
	x += pod;
	t[x] = c;
	x /= 2;
	while(x) {
		t[x] = max(t[2 * x], t[2 * x + 1]);
		x /= 2;
	}
}

int query(int l, int r) {
	r += 1;
	int res = 0;
	for(l += pod, r += pod; l < r; l /= 2, r /= 2) {
		if(l & 1) 
			res = max(res, t[l++]);
		if(r & 1)
			res = max(res, t[--r]);
	}
	return res;
}

bool ok(int L, int R) {
	int big = query(L, R);
	int pos = lower_bound(her + 1, her + m + 1, mp(big, -1)) - her;
	return R - L + 1 <= maks[pos];
}
 
int main() {	
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		FOR(i,  n) {
			scanf("%d", mon + i);
			add(i, mon[i]);
		}
		scanf("%d", &m);
		FOR(i, m) {
			scanf("%d %d", &her[i].fi, &her[i].se);
		}
		
		sort(her + 1, her + m + 1);
		
		if(query(1, n) > her[m].fi) {
			printf("-1\n");
			continue;
		}
		
		maks[m + 1] = 0;
		for(int i = m; 1 <= i; --i) 
			maks[i] = max(maks[i + 1], her[i].se);
		int ans = 0;
		for(int i = 1; i <= n;) {
			int lewo = 0;
			int prawo = n - i;
			while(prawo > lewo) {
				int mid = (lewo + prawo + 1) / 2;
				if(ok(i, i + mid))
					lewo = mid;
				else
					prawo = mid - 1;
			}
			ans += 1;
			i = i + lewo + 1;
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}