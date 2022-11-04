#include<cstdio>
#include<algorithm>
#define ll long long
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 255;
const ll mo = 23333333333333333;

int n, m;
char s[N][N];
int bz[N][N][N]; ll t[N][N][N], a[N * 2];
int cnt[26], r[N];
ll ans;

void Build() {
	fd(i, n, 1) a[i * 2] = a[i];
	fo(i, 1, n + 1) a[i * 2 - 1] = -2;
    int p = 0, mx = 0;
    fo(i, 1, 2 * n + 1) {
    	if(a[i] == -1) continue;
        r[i] = mx > i ? min(r[p * 2 - i], mx - i + 1) : 1;
        while (i > r[i] && i + r[i] <= 2 * n + 1 && a[i - r[i]] == a[i + r[i]] && a[i - r[i]] != -1 && a[i + r[i]] != -1) r[i] ++;
        if(i + r[i] - 1 > mx) p = i, mx = i + r[i] - 1;
        ans += r[i] / 2;
    }
}

ll am[27];

int main() {
//	freopen("e.in", "r", stdin);
	am[0] = 1; fo(i, 1, 25) am[i] = am[i - 1] * 251 % mo;
	scanf("%d %d", &n, &m);
	fo(i, 1, n) scanf("%s", s[i] + 1);
	fo(i, 1, n) fo(j, 1, m) s[i][j] -= 'a';
	fo(i, 1, n) {
		fo(j, 1, m) {
			fo(p, 0, 25) cnt[p] = 0;
			int s1 = 0; ll h = 0;
			fo(k, j, m) {
				if(cnt[s[i][k]] & 1) s1 --;
				h = (h + am[s[i][k]]) % mo;
				cnt[s[i][k]] ++;
				if(cnt[s[i][k]] & 1) s1 ++;
				bz[i][j][k] = s1 <= 1;
				t[i][j][k] = h;
			}
		}
	}
	fo(i, 1, m) fo(j, i, m) {
		fo(k, 1, n) {
			if(bz[k][i][j]) a[k] = t[k][i][j]; else a[k] = -1;
		}
		ll a1 = ans;
		Build();
	}
	printf("%I64d", ans);
}