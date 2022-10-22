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

const int nax = 2e5 + 111;

int q;
int n;
int p[nax];
int x, y, A, B;
ll k;
multiset <pair<ll, pair<int, int>>> X;
multiset <pair<ll,  int>> secik;
bool bad[nax];
int one[2];

bool ok(int days) {
	ll xd = (ll) A * B / __gcd(A, B);
	int ile = days / xd;
	one[0] = days / A - ile;
	one[1] = days / B - ile;
	
	ll res = 0;
	FOR(i, 1, ile) {
		res += (ll) (x + y) * p[n - i + 1] / 100;
	}
	
	for(int i = n - ile; 1 <= i; --i) {
		if(x >= y) {
			if(one[0] > 0) {
				res += (ll) x * p[i] / 100;
				one[0] -= 1;
			}
			else if(one[1] > 0) {
				res += (ll) y * p[i] / 100;
				one[1] -= 1;
			}
		}
		else {
			if(one[1] > 0) {
				res += (ll) y * p[i] / 100;
				one[1] -= 1;
			}
			else if(one[0] > 0) {
				res += (ll) x * p[i] / 100;
				one[0] -= 1;
			}
			
		}
	}
			
	
	return res >= k;
}
			
		
		
	

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		FOR(i, 1, n)
			scanf("%d", &p[i]);
		sort(p + 1, p + n + 1);
		scanf("%d %d %d %d", &x, &A, &y, &B);
		scanf("%lld", &k);
		int l = 1;
		int r = n + 1;
		while(l < r) {
			int m = (l + r) / 2;
			if(ok(m) == 1)
				r = m;
			else
				l = m + 1;
		}
		if(l == n + 1)
			printf("-1\n");
		else
			printf("%d\n", l);	
	}
		
		
		
	
	
	return 0;
}