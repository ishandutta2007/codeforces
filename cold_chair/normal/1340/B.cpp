#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2005;

int a2[8];

string num[10] = {
	 "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};

int id[10];

int n, k;

char s[N][10];

int c1[1 << 7];

int a[N];

int f[N][N];

int b[N];

int main() {
	a2[0] = 1; fo(i, 1, 7) a2[i] = a2[i - 1] * 2;
	ff(i, 0, 1 << 7) {
		fo(j, 0, 6) c1[i] += i >> j & 1;
	}
	fo(i, 0, 9) {
		fo(j, 0, 6) id[i] += a2[j] * (num[i][j] - '0');
	}
	scanf("%d %d", &n, &k);
	fo(i, 1, n) {
		scanf("%s", s[i]);
		fo(j, 0, 6) a[i] += a2[j] * (s[i][j] - '0');
	}
	f[n + 1][0] = 1;
	fd(i, n, 1) {
		fo(j, 0, 9) if((a[i] & id[j]) == a[i]) {
			int c = c1[id[j]] - c1[a[i]];
			fo(u, c, k) f[i][u] |= f[i + 1][u - c];
		}
	}
	if(f[1][k] == 0) {
		pp("-1\n"); return 0;
	}
	fo(i, 1, n) {
		fd(j, 9, 0) if((a[i] & id[j]) == a[i]) {
			int c = c1[id[j]] - c1[a[i]];
			if(k >= c && f[i + 1][k - c]) {
				b[i] = j;
				k -= c;
				break;
			}
		}
	}
	fo(i, 1, n) pp("%d", b[i]);
}