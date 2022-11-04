#include<cstdio> 
#include<cstring>
#include<algorithm>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int N = 1e3 + 5;

char s[N];

int n, k;

int f[N][N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	sort(s + 1, s + n + 1);
	memset(f, 127, sizeof f);
//	fo(i, 1, n) printf("%c\n", s[i]);
	fo(i, 1, n) {
		f[i][1] = s[i] - 'a' + 1;
		fo(j, 2, i) {
			fo(k, 1, i - 1) if(s[i] - s[k] >= 2)
				f[i][j] = min(f[i][j], f[k][j - 1] + s[i] - 'a' + 1);
		}
	}
	int ans = 1e9;
	fo(i, k, n) ans = min(ans, f[i][k]);
	if(ans == 1e9) printf("-1"); else printf("%d", ans);
}