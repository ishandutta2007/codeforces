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

const int maxn = 30;
int n, m;
int hdir[maxn];
int vdir[maxn];
char s[maxn];
bool vis[maxn][maxn][maxn][maxn];

void dfs(int x, int y, int u, int v) {
    if (vis[x][y][u][v]) return;
    vis[x][y][u][v] = 1;
    FOR(i, -1, 2) FOR(j, -1, 2) if (i * j == 0 && i + j != 0) {
        if (u + i >= 0 && u + i < n && v + j >= 0 && v + j < m) {
            if (j == 1 && !hdir[u]) continue;
            if (j == -1 && hdir[u]) continue;
            if (i == 1 && !vdir[v]) continue;
            if (i == -1 && vdir[v]) continue;
            dfs(x, y, u + i, v + j);
        }
    }
}

void solve() {
    ms(hdir, 0); ms(vdir, 0);
    scanf("%d%d", &n, &m);
    scanf("%s", s);
    FOR(i, 0, n) hdir[i] = s[i] == '>';
    scanf("%s", s);;
    FOR(i, 0, m) vdir[i] = s[i] == 'v';
    FOR(i, 0, n) FOR(j, 0, m) dfs(i, j, i, j);
    FOR(i, 0, n) FOR(j, 0, m) FOR(k, 0, n) FOR(l, 0, m) if (!vis[i][j][k][l]) {printf("NO"); return;}
    printf("YES");
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