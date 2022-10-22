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

const int N = 210;
const ll INF = 2e18;

int n, m;
ll k;

int t[N];

int pi[N];
int automat[N][2];
int nxt[N][N]; // -> n-ty wyraz, gdzie jestem
ll cnt[N][N]; // zaczynam od tego i ile mam
// nxt[i][j] = nxt [i - 1] [ nxt[i - 2][j] ] 
// cnt[i][j] = cnt [i - 2][j] + cnt[i - 1][nxt[i - 2][j]]

void init(int len) {
	t[len + 1] = 2;
	pi[1] = 0;
	rep(i, 2, len) {
		int b = pi[i - 1];
		while (b > 0 && t[i] != t[b + 1])
			b = pi[b];
		if (t[i] == t[b + 1])
			b++;
		pi[i] = b;
	}
	
	rep(i, 0, len)
		rep(x, 0, 1) {
			if (t[i + 1] == x)
				automat[i][x] = i + 1;
			else
				automat[i][x] = (i == 0 ? 0 : automat[pi[i]][x]);
		}
		
	rep(j, 0, 1)
		rep(i, 0, len) {
			nxt[j][i] = automat[i][j];
			cnt[j][i] = automat[i][j] == len;
		}
	
	rep(j, 2, n) 
		rep(i, 0, len) {
			nxt[j][i] = nxt[j - 1][nxt[j - 2][i]];
			cnt[j][i] = cnt[j - 2][i] + cnt[j - 1][nxt[j - 2][i]];
			cnt[j][i] = min(cnt[j][i], INF);
		}
	
}

int main() {	
	scanf ("%d%lld%d", &n, &k, &m);
	rep(i, 1, m) {
		if (i > 1) {
			init(i - 1);
			if (nxt[n][0] == i - 1)
				k--;
			if (!k) break;
		}
		t[i] = 0;
		init(i);
		if (cnt[n][0] >= k) {
			t[i] = 0;
		}
		else {
			t[i] = 1;
			k -= cnt[n][0];
		}
		printf ("%d", t[i]);
	}
		
	return 0;
}