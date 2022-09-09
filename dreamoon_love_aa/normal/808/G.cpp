#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1<<17;
const int MOD = 1'000'000'007;
void make_kmp(char s[], int n, int phi[]) {
    phi[0] = -1;
    for(int i = 1; i < n; i++) {
        phi[i] = -1;
        int now = i - 1;
        while(now != -1) {
            if(s[phi[now] + 1] == s[i]) {
                phi[i] = phi[now] + 1;
                break;
            } else {
                now = phi[now];
            }
        }
    }
}
int bk[SIZE];
int nxt[SIZE][26];
char s[SIZE], t[SIZE];
int dp[2][SIZE];
void update (int &x, int v) {
    if(x < v) {
        x = v;
    }
}
void solve() {
    scanf("%s%s", s, t);
    int m = strlen(s);
    int n = strlen(t);
    t[n] = 'A';
    make_kmp(t, n + 1, bk);
    for(int i = 0; i < 26; i++) { nxt[n + 1][i] = n + 1; }
    for(int i = 0; i <= n; i++) {
        for(int j = 'a', k = 0; j <= 'z'; j++, k++) {
            if(t[i] == j) {
                nxt[i][k] = i + 1;
            } else {
                nxt[i][k] = i ? nxt[bk[i - 1] + 1][k] : 0;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[0][i] = -m;
    }
    dp[0][0] = 0;
    int now = 0, nt = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j <= n; j++) {
            dp[nt][j] = -m;
        }
        for(int j = 0; j <= n; j++) {
            if(dp[now][j] < 0) { continue; }
            if(s[i] == '?') {
                for(int k = 0; k < 26; k++) {
                    if(nxt[j][k] < n) {
                        update(dp[nt][nxt[j][k]], dp[now][j]);
                    } else {
                        update(dp[nt][n], dp[now][j] + 1);
                    }
                }
            } else {
                int k = s[i] - 'a';
                if(nxt[j][k] < n) {
                    update(dp[nt][nxt[j][k]], dp[now][j]);
                } else {
                    update(dp[nt][n], dp[now][j] + 1);
                }
            }
        }
        swap(now, nt);
    }
    printf("%d\n", *max_element(dp[now], dp[now] + n + 1));
}
int main() {
    solve();
    return 0;
}