#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define pp printf
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 1e6 + 5;

const int c = 8;

int n, m, a[N], b[N], ans, sum;
int f[2][c + 1][c + 1], o, la1, la2;

int main() {
	scanf("%d %d", &n, &m);
	fo(i, 1, n) scanf("%d", &a[i]), b[a[i]] ++;
	memset(f[o], 128, sizeof f[o]); f[o][0][0] = 0;
	la1 = 0; la2 = 0;
	fo(i, 1, m) if(b[i]) {
		while(b[i] > 8) b[i] -= 3, sum ++;
		memset(f[!o], 128, sizeof f[!o]);
		if(la1 == la2 - 1 && la2 == i - 1) {
			fo(u, 0, c) fo(v, 0, c) if(f[o][u][v] >= 0) {
				fo(j, 0, min(2, min(u, min(v, b[i])))) {
					f[!o][v - j][b[i] - j] = max(f[!o][v - j][b[i] - j], f[o][u][v] + j);
				}
			}
		} else {
			fo(u, 0, c) fo(v, 0, c)
				f[!o][v][b[i]] = max(f[!o][v][b[i]], f[o][u][v]);
		}
		la1 = la2; la2 = i;
		o = !o;
		fo(u, 0, c) fo(v, 0, c) if(f[o][u][v] >= 0)
			fo(j, 0, u / 3) fo(k, 0, v / 3) f[o][u - j * 3][v - k * 3] = max(f[o][u - j * 3][v - k * 3], f[o][u][v] + j + k);
	}
	fo(u, 0, c) fo(v, 0, c) ans = max(ans, f[o][u][v]);
	pp("%d", ans + sum);
}