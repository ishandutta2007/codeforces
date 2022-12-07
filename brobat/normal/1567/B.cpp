#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 300100
#define MOD 1000000007

int p[MAXN];

void pre() {
    p[0] = 0;
    forn(i, 1, MAXN) p[i] = p[i-1]^i;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int x = p[a-1]^b;
    if(x==0) cout << a << "\n";
    else if(x==a) cout << a + 2 << "\n";
    else cout << a + 1 << "\n";
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    pre();
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}