#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 3e5 + 10;
const int MEM = N * 60;

int n, a;
int go[MEM][2], cnt[MEM], fre;
ll qq[30][2];
 
int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", &a);
		int v = 0;
		per(j, 0, 29) {
			int gdzie = (a >> j) & 1;
			if (go[v][!gdzie]) {
				qq[j][gdzie] += cnt[go[v][!gdzie]];
			}
			if (!go[v][gdzie])
				go[v][gdzie] = ++fre;
			v = go[v][gdzie];
			cnt[v]++;
		}	
		//~ cat(qq[0][0]);cat(qq[0][1]);
	}
	ll inv = 0, x = 0, two = 1;
	rep(i, 0, 29) {
		//~ cat(qq[i][0]);cat(qq[i][1]);
		if (qq[i][0] > qq[i][1]) {
			x += two;
		}
		inv += min(qq[i][0], qq[i][1]);
		two <<= 1;
	}
	printf ("%lld %lld\n", inv, x);
		
	
	
	return 0;
}