#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define cnt(a,b) __builtin_popcount(c[a]&c[b])
using namespace std;
const int c[] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};

const int maxn = 200009;
int base, s, n, t;
char a[maxn];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s", a + 1);
	n = strlen(a + 1) / 2;
	rep (i, 1, 2 * n) a[i] -= '0';
	per (i, 2 * n, 1) {
		t = (i > n ? i - n : i + n);
		rep (j, a[i] + 1, 9) 
			if (base + cnt(a[t], j) - cnt(a[t], a[i]) > 0) {
				s = base + cnt(a[t], j) - cnt(a[t], a[i]); a[i] = j; 
				rep (k, i + 1, 2 * n) {
					t = (k > n ? k - n : k + n);
					rep (l, 0, 9)
						if (s - cnt(a[t], a[k]) + cnt(a[t], l) > 0) {
							s += - cnt(a[t], a[k]) + cnt(a[t], l);
							a[k] = l; break;
						}
				}
				rep (k, 1, 2 * n) putchar(a[k] + '0');
				return 0;
			}
		base += cnt(a[t], 8) - cnt(a[t], a[i]);
		a[i] = 8;
	}
	puts("-1");
	return 0;
}