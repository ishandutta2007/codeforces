#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

int n, m, k, t;
int a[200001];
pair<int, pair<int, int>> v[200001];

vector <pair<int, int>> trap;

bool ok(int x) {
	trap.clear();
	for(int i = 1; i <= k; ++i) 
		if(x < v[i].fi)
			trap.pb({v[i].se.fi, v[i].se.se});
	
	sort(trap.begin(), trap.end());
	int czas = m + 1;
	for(int i = 0; i < ss(trap);) {
		int j = i;
		int R = trap[i].se;
		while(j < ss(trap) && trap[j].fi <= R) {
			R = max(R, trap[j].se);
			j += 1;
		}
		czas += 2 * (R - trap[i].fi + 1);
		i = j;
	}
	return czas <= t;
}
	

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &t);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for(int i = 1; i <= k; ++i) 
		scanf("%d %d %d", &v[i].se.fi, &v[i].se.se, &v[i].fi);
	sort(v + 1, v + k + 1);
	sort(a + 1, a + n + 1);
	
	int L = 0;
	int R = n;
	while(L < R) {
		int M = (L + R + 1) / 2;
		if(ok(a[n - M + 1]))
			L = M;
		else
			R = M - 1;
	}
	printf("%d", L);
	
		
					
	
	return 0;
}