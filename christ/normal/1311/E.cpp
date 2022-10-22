#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 5e3+2, MOD = 1e9+7, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
int p[MN]; int c[MN], dep[MN];
void solve () {
	int n,d;
	scanf ("%d %d",&n,&d);
	int sum = 0;
	for (int i = 0; i < n; i++) sum += i, p[i+1] = dep[i+1] = i, c[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i-2; j++) if (c[j] < 2 && dep[j] + 1 < dep[i] && sum - (dep[i] - (dep[j]+1))*(n-i+1) >= d){
			++c[j];
			--c[p[i]];
			p[i] = j;
			sum -= (dep[i] - (dep[j]+1))*(n-i+1);
			for (int k = i; k <= n; k++) dep[k] = dep[j]+1+k-i;
			break;
		}
	}
	if (sum != d) return (void) printf ("NO\n");
	printf ("YES\n");
	for (int i = 2; i <= n; i++) printf ("%d%c",p[i]," \n"[i==n]);
}
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) solve();
    return 0;
}