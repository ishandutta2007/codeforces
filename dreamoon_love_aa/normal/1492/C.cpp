#include<bits/stdc++.h>
using namespace std;
const int MAX_LEN = 500 * 1000;
int n;
char s[MAX_LEN + 1];
int m;
char t[MAX_LEN + 1];
int pos[MAX_LEN];
void solve() {
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%s", s);
    scanf("%s", t);
    int now = 0;
    for(int i = 0; i < m; i++) {
        while(s[now] != t[i]) { now++; }
        pos[i] = now++;
    }
    now = n - 1;
    int an = 0;
    for(int i = m - 1; i > 0; i--) {
        while(s[now] != t[i]) { now--; }
        an = max(an, now - pos[i - 1]);
        now--;
    }
    printf("%d\n", an);
}
int main() {
    solve();
    return 0;
}