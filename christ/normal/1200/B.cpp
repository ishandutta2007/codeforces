#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6+2;
int h[MN];
void solve () {
    int n,m,k;
    scanf ("%d %d %d",&n,&m,&k);
    for (int i = 1; i <= n; i++) scanf ("%d",&h[i]);
    for (int i = 1; i < n; i++) {
        int low = max(0,h[i+1]-k);
        m += h[i]-low;
        if (m < 0) {printf ("NO\n");return;}
    }
    printf("YES\n");
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}