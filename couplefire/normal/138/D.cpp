#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
 
const int maxn = 41;
int f[maxn][maxn][maxn][maxn];
char s[maxn][maxn];
int n, m;
 
int g(int a, int b, int c, int d, int t) {
    if (a > b || c > d) return 0;
    if (f[a][b][c + 20][d + 20] != -1)
        return f[a][b][c + 20][d + 20];
    int i, j, x, y; set<int> h; h.clear();
    for (i = a; i <= b; ++i)
        for (j = c; j <= d; ++j) 
            if ((i + j) % 2 == 0) {
                x = (i + j) / 2; y = (i - j) / 2;
                if (x < 0 || x > n || y < 0 || y > m || (x + y) % 2 != t)
                    continue;
                if (s[x][y] == 'L')
                    h.insert(g(a, i - 1, c, d, t) ^ g(i + 1, b, c, d, t));
                else if (s[x][y] == 'R')
                    h.insert(g(a, b, c, j - 1, t) ^ g(a, b, j + 1, d, t));
                else {
                    h.insert(g(a, i - 1, c, j - 1, t) ^ g(a, i - 1, j + 1, d, t) ^
                             g(i + 1, b, c, j - 1, t) ^ g(i + 1, b, j + 1, d, t));
                }
            }
    for (i = 0; h.count(i); ++i) ;
    return f[a][b][c + 20][d + 20] = i;
}
 
int main() {
    int i, a, b;
    scanf("%d%d", &n, &m); --n; --m;
    for (i = 0; i <= n; ++i) scanf("%s", s[i]);
    memset(f, 255, sizeof f);
    a = g(0, n + m, -m, n, 0);
    memset(f, 255, sizeof f);
    b = g(0, n + m, -m, n, 1);
    puts(a ^ b ? "WIN" : "LOSE");
    return 0;
}