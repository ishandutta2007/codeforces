#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

const int nax = 1e5 + 111;

int n, q;
int a[nax];
int b[nax];

stack <pair<int,int>> stos;
int L[nax];
int R[nax];
			
int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for(int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d %d", &l, &r);
		ll ans = 0;
		for(int i = l; i < r; ++i)
			b[i] = abs(a[i + 1] - a[i]);
		b[l - 1] = 1e9;
		b[r] = 1e9;
		
		for(int i = l; i <= r; ++i) {
			while(!stos.empty() && stos.top().fi <= b[i]) {
				R[stos.top().se] = i;
				stos.pop();
			}
			if(i != r) stos.push(mp(b[i], i));
		}
		assert(stos.empty());
		
		for(int i = r - 1; l - 1 <= i; --i) {
			while(!stos.empty() && stos.top().fi < b[i]) {
				L[stos.top().se] = i + 1;
				stos.pop();
			}
			if(i != l - 1) stos.push(mp(b[i], i));
		}
		assert(stos.empty());
		for(int i = l; i < r; ++i) {
			//printf("%d %d %d\n", i, L[i], R[i]);
			ans += 1ll * b[i] * (i - L[i] + 1) * (R[i] - (i + 1) + 1);
		}
		printf("%lld\n", ans);
	}
	
	
	
	return 0;
}