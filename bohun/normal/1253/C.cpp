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

const int nax = 400005;
const int p = 300;

int n, m;
int a[nax];
ll out[nax];
ll add[p + 1];

int main() {
	scanf("%d %d", &n, &m);
	FOR(i, n) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	if(m >= 300) {
		for(int i = 1; i <= n; ++i) {
			int j = i;
			while(j <= n) {
				out[j] += a[i];
				j += m;
			}
		}
		for(int i = 1; i <= n; ++i) {
			out[i] += out[i - 1];
			printf("%lld ", out[i]);
		}
	}
	else {
		ll ja = 0;
		for(int i = 1; i <= n; ++i) {
			ja += a[i];
			ja += add[i % m];
			add[(i + m) % m] += a[i];
			printf("%lld ", ja);
		}
		
	}
	
	
	
	return 0;
}