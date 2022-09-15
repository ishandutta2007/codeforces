#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const ld PI = acos(-1);
const int maxn = 110;
int n;
int x[4 * maxn];
int y[4 * maxn];
int a[4 * maxn];
int b[4 * maxn];

int distance(int x, int y, int z, int t) {
    return (x - z) * (x - z) + (y - t) * (y - t);
}

int cal(int d) {
    int res = -1;
    FOR(i, 0, 4) FOR(j, 0, 4) FOR(k, 0, 4) FOR(l, 0, 4) {
        int px[4], py[4];
        ld co[4], si[4];
        co[0] = cos(90.0 * i * PI / 180);
        si[0] = sin(90.0 * i * PI / 180);

        co[1] = cos(90.0 * j * PI / 180);
        si[1] = sin(90.0 * j * PI / 180);

        co[2] = cos(90.0 * k * PI / 180);
        si[2] = sin(90.0 * k * PI / 180);

        co[3] = cos(90.0 * l * PI / 180);
        si[3] = sin(90.0 * l * PI / 180);

        px[0] = (int) round(co[0] * (x[d] - a[d]) - si[0] * (y[d] - b[d])) + a[d];
        py[0] = (int) round(si[0] * (x[d] - a[d]) + co[0] * (y[d] - b[d])) + b[d];

        px[1] = (int) round(co[1] * (x[d + 1] - a[d + 1]) - si[1] * (y[d + 1] - b[d + 1])) + a[d + 1];
        py[1] = (int) round(si[1] * (x[d + 1] - a[d + 1]) + co[1] * (y[d + 1] - b[d + 1])) + b[d + 1];

        px[2] = (int) round(co[2] * (x[d + 2] - a[d + 2]) - si[2] * (y[d + 2] - b[d + 2])) + a[d + 2];
        py[2] = (int) round(si[2] * (x[d + 2] - a[d + 2]) + co[2] * (y[d + 2] - b[d + 2])) + b[d + 2];

        px[3] = (int) round(co[3] * (x[d + 3] - a[d + 3]) - si[3] * (y[d + 3] - b[d + 3])) + a[d + 3];
        py[3] = (int) round(si[3] * (x[d + 3] - a[d + 3]) + co[3] * (y[d + 3] - b[d + 3])) + b[d + 3];

        bool flag = true;
        FOR(u, 0, 4) FOR(v, u + 1, 4) if (px[u] == px[v] && py[u] == py[v]) {flag = false; break;}
        if (!flag) continue;

        int p[] = {0, 1, 2, 3};
        do {
            int tmp[4];
            FOR(u, 0, 4) {
                int nxt = (u + 1) % 4;
                tmp[u] = distance(px[p[u]], py[p[u]], px[p[nxt]], py[p[nxt]]);
            }
            if (tmp[0] > 0 && tmp[0] == tmp[1] && tmp[1] == tmp[2] && tmp[2] == tmp[3] && distance(px[p[0]], py[p[0]], px[p[2]], py[p[2]]) == 2 * tmp[0]) {
                if (res == -1) res = i + j + k + l; else res = min(res, i + j + k + l);
            }
        }
        while (next_permutation(p, p + 4));
    }
    return res;
}

void solve() {
    scanf("%d", &n);
    FOR(i, 0, 4 * n) scanf("%d%d%d%d", x + i, y + i, a + i, b + i);
    FOR(i, 0, n) printf("%d\n", cal(4 * i));
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}