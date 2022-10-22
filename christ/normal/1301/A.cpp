#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char a[MN], b[MN], c[MN];
void solve () {
    scanf ("%s\n%s\n%s",a,b,c);
    int n = strlen(a);
    for (int i = 0; i < n; i++) {
        if (!(a[i] == c[i] || b[i] == c[i])) return (void) printf ("NO\n");
    }
    printf ("YES\n");
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}