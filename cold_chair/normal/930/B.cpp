#include<cstdio>
#include<cstring>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 1e4 + 5;

char s[N]; int n, d[N], sum[N][26];

int final[N], next[N], to[N], tot, ans;

void link(int x, int y) {
	next[++ tot] = final[x], to[tot] = y, final[x] = tot;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%s", s + 1); n = strlen(s + 1);
	fo(i, n + 1, 2 * n) s[i] = s[i - n];
	fo(i, 1, n) link(s[i] - 'a', i);
	fo(i, 0, 25) {
		d[0] = 0;
		for(int j = final[i]; j; j = next[j])
			d[++ d[0]] = to[j];
		fo(j, 1, n) memset(sum[j], 0, sizeof sum[j]);
		fo(j, 1, d[0]) {
			int x = d[j];
			fo(k, x, x + n - 1) sum[k - x + 1][s[k] - 'a'] ++;
		}
		int mx = 0;
		fo(j, 2, n) {
			int y = 0;
			fo(k, 0, 25) if(sum[j][k] == 1) y ++;
			mx = max(mx, y);
		}
		ans += mx;
	}
	printf("%.10lf", (double) ans / n);
}