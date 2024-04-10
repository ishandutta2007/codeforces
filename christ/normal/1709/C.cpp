#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5, MOD = 1e9 + 7, MM = 1e5;
char s[MN];
void solve () {
    scanf ("%s",s+1);
    int n = (int)strlen(s+1);
    int L = 0, R = 0;
    for (int i = 1; i<= n; i++) {
        if (s[i] == '(') ++L;
        else if (s[i] == ')') ++R;
    }
    assert(n % 2 == 0);
    vector<int> put(n+1, -1);
    vector<int> pre(n+1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1];
        if (s[i] == '(') ++pre[i];
        else if (s[i] == ')') --pre[i];
        else if (s[i] == '?') {
            if (L < n/2) ++L, ++pre[i], put[i] = 0;
            else ++R, --pre[i], put[i] = 1;
        }
    }
    int lst = -1;
    for (int i = 1; i <= n; i++) {
        if (put[i] == 0) lst = i;
    }
    if (lst == -1) {
        printf ("YES\n");
        return;
    }
    int nxt = -1;
    for (int i = lst; i <= n; i++) {
        if (put[i] == 1) {
            nxt = i;
            break;
        }
    }
    if (nxt == -1) {
        printf ("YES\n");
        return;
    }
    swap(put[lst],put[nxt]);
    int got = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(' || put[i] == 0) ++got;
        else --got;
        if (got < 0) {
            printf ("YES\n");
            return;
        }
    }
    printf ("NO\n");
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}