#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
char s[MN];
int psa[MN];
void solve () {
    scanf ("%s",s+1);
    int n = strlen(s+1);
    for (int i = 1; i <= n; i++) psa[i] = psa[i-1] + (s[i] == '1');
    int sum = psa[n], can = 0;
    for (int i = 1; i + sum - 1 <= n; i++) {
        can = max(can,psa[i + sum - 1] - psa[i-1]);
    }
    printf ("%d\n",sum - can);
}
int main () {
    int t; scanf ("%d",&t);
    while (t--) solve();
    return 0;
}