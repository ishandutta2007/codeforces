#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

ll a2[52], s, ans;

ll cnt_1(ll x) {
	ll s = 0;
	for(; x; x /= 2) s += x & 1;
	return s;
}

ll f[2][105][2], o;

#define mem(a) memset(a, 0, sizeof a)

ll b[55], b0;

int main() {
	scanf("%I64d", &s);
	a2[0] = 1; fo(i, 1, 51) a2[i] = a2[i - 1] * 2;
	fo(h, 1, 50) {
		ll c = a2[h] - 1;
		if(c > s) break;
		ll x = s - (s / c) * c;
		fo(j, 0, 50) if(x >= j && !((x + j) & 1))
			ans += cnt_1(x + j) == j;
	}
	fo(h1, 1, 50) fo(h2, 1, 50) {
		ll c = a2[h1 + 1] + a2[h2 + 1] - 3;
		if(c > s) break;
		ll x = s - (a2[h2] - 1) - (s - (a2[h2] - 1)) / c * c;
		fo(t, 0, h1 + h2 - 2) {
			ll y = x + t; b0 = 0;
			if(y & 1) continue;
			for(y /= 2; y; y /= 2) b[++ b0] = y & 1;
			if(b0 > max(h1, h2) + 1) continue;
			mem(f[o]); f[o][0][0] = 1;
			fo(i, 1, b0) {
				mem(f[!o]);
				int c = b[i];
				fo(j, 0, t) fo(w, 0, 1) if(f[o][j][w]) {
					fo(w1, 0, i < h1) fo(w2, 0, i < h2) {
						int nj = j + w1 + w2;
						if(nj > t) continue;
						if((w + w1 + w2) % 2 != c) continue;
						int nw = (w + w1 + w2) / 2;
						f[!o][nj][nw] += f[o][j][w];
					}
				}
				o = !o;
			}
			ans += f[o][t][0];
		}
	}
	pp("%I64d", ans);
}