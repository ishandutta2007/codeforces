#include <bits/stdc++.h>
using namespace std;
#define forn(i, a, b)   for(int i=a; i <=b; ++i)
#define repn(i, a, b)   for(int i=a; i < b; ++i)
const int maxn = 5010;
int nxt[maxn][30][3];
int f[maxn][maxn];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    string A, B; cin >> A >> B;
    for(int chr = 0; chr < 26; ++ chr) {
        nxt[n][chr][0] = n;
        nxt[m][chr][1] = m;
        for(int i = n - 1; i >= 0; --i) {
            if (A[i] == char(chr + 'a')) {
                nxt[i][chr][0] = i;
            } else nxt[i][chr][0] = nxt[i+1][chr][0];
        }
        for(int i = m - 1; i >= 0; --i) {
            if (B[i] == char(chr + 'a')) {
                nxt[i][chr][1] = i;
            } else nxt[i][chr][1] = nxt[i+1][chr][1];
        }
    }
    int answer = -INT_MAX;
    memset(f, -1, sizeof f);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) 
        if (A[i] == B[j]) {
            f[i][j] = 2;
            answer = 2;
        }
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) 
        if (f[i][j] != -1) {
            for(int chr = 0; chr < 26; ++chr) {
                if (nxt[i+1][chr][0] < n && nxt[j+1][chr][1] < m) {
                    int u = nxt[i+1][chr][0], v = nxt[j+1][chr][1];
                    f[u][v] = max(f[u][v], f[i][j] + 4 - (u - i + v - j));
                    // if (f[u][v] == 16) cerr << u << ' ' << v << ' ' << char(chr + 'a') << '\n';
                    answer = max(answer, f[u][v]);
                }
            }
        }
    cout << max(answer, 0) << '\n';
}