#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const ll mod = int(1e9) + 7;
const int ma = 1024 * 1024;

int n, seg[2 * ma];
int cntt;

void ask_(int nu, int x) {
	cntt++;
	if (cntt > 1) re;
	
	while (nu < ma) {
		int k = 0;
		if (seg[2 * nu] % x) {
			k++;
		}
		if (seg[2 * nu + 1] % x) {
			k++;
		}
		if (k == 2) {
			cntt = 2;
			break;
		}
		if (seg[2 * nu] % x) nu = 2 * nu;
		else
		   nu = 2 * nu + 1; 
	}
}
void get_cntq(int l, int r, int x) {
	if (l > r) re;
	if (cntt > 1) re;
	if (l % 2) {
		if (seg[l] % x) {
			ask_(l, x);
		}
		get_cntq(l + 1, r, x);
		re;
	} 
	if (r % 2 == 0) {
		if (seg[r] % x) {
			ask_(r, x);
		}
		get_cntq(l, r - 1, x);
		re;
	}
	get_cntq(l / 2, r / 2, x);
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	scanf("%d", &n);
	forn (i, n) {
		int a;
		scanf("%d", &a);
		seg[ma + i] = a;
	}
	for (int i = ma - 1; i; i--)
		seg[i] = __gcd(seg[2 * i], seg[2 * i + 1]);
	int q;
	scanf("%d", &q);
	forn (i, q) {
		int t, l, r, x;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &l, &r, &x);
			l--;
			r--;
			cntt = 0;
			get_cntq(l + ma, r + ma, x);
			if (cntt <= 1) {
				printf("YES\n");
			} else
				printf("NO\n");
			continue;
		}
		if (t == 2) {
			scanf("%d%d", &l, &r);
			l--;
			l += ma;
			seg[l] = r;
			while (l / 2) {
				l /= 2;
				seg[l] = __gcd(seg[2 * l], seg[2 * l + 1]);
			}
		}
	}
}