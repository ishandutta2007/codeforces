#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1 << 17;
char s[SIZE];
int a[SIZE];
char op[SIZE];
__int128_t dp[30], from[30], mul[30][30];
void solve (int l, int r) {
    while (a[l] == 1 && l < r) {
        l++;
        op[l] = '+';
    }
    if (l == r) { return; }
    while (a[r] == 1 && r > l) {
        op[r] = '+';
        r--;
    }
    vector<int> pos;
    for (int i = l; i <= r; i++) {
        if (a[i] != 1) {
            pos.PB(i);
        }
    }
    if (SZ(pos) > 29) {
        for (int i = l + 1; i <= r; i++) {
            op[i] = '*';
        }
        return;
    }
    for(int i = 0; i < SZ(pos); i++) { dp[i] = 0; }
    for (int i = 0; i < SZ(pos); i++) {
        mul[i][i] = a[pos[i]];
        for (int j = i + 1; j < SZ(pos); j++) {
            mul[i][j] = mul[i][j - 1] * a[pos[j]];
        }
    }
    for (int i = 0; i < SZ(pos); i++) {
        dp[i] = mul[0][i];
        from[i] = 0;
    }
    for(int i = 0; i < SZ(pos); i++) {
        for(int j = i + 1; j < SZ(pos); j++) {
            if(dp[i] + pos[i + 1] - pos[i] - 1 + mul[i + 1][j] > dp[j]) {
                dp[j] = dp[i] + pos[i + 1] - pos[i] - 1 + mul[i + 1][j];
                from[j] = i + 1;
            }
        }
    }
    int now = SZ(pos) - 1;
    while(now >= 0) {
        int nxt = from[now];
        for(int i = pos[nxt] + 1; i <= pos[now]; i++) {
            op[i] = '*';
        }
        now = nxt - 1;
        if(nxt) {
            for(int i = pos[now] + 1; i <= pos[nxt]; i++) {
                op[i] = '+';
            }
        }
    }
}
void solve(int n) {
    for(int i = 1, j; i <= n; i = j) {
        if(a[i] == 0) {
            op[i] = op[i + 1] = '+';
            j = i + 1;
        } else {
            for(j = i + 1; j <= n && a[j]; j++);
            solve(i, j - 1);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i > 1) { printf("%c", op[i]); }
        printf("%d", a[i]);
    }
    puts("");
}
void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%s", s);
    int len = strlen(s);
    sort(s, s + len);
    if (len == 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d%c", a[i], i < n ? s[0] : '\n');
        }
    } else if (count(s, s + len, '+') && count(s, s + len, '*')){
        solve(n);
    } else if(count(s, s + len, '+')) {
        for (int i = 1; i <= n; i++) {
            printf("%d%c", a[i], i < n ? '+' : '\n');
        }
    } else {
        int st = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] == 0) {
                st = i;
                break;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i > 1) {
                if(i == st) { printf("-"); }
                else { printf("*"); }
            }
            printf("%d", a[i]);
        }
        puts("");
    }
}
int main() {
    solve();
    return 0;
}