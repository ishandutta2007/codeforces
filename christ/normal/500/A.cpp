#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    int n,t;
    scanf ("%d %d",&n,&t);
    vector<int> go(n+1);
    for (int i = 1; i <= n-1; i++) scanf ("%d",&go[i]);
    vector<bool> poss(n+1);
    poss[1] = 1;
    for (int i = 1; i <= n; i++) if (poss[i]) {
        if (i == t) return !printf ("YES\n");
        poss[i+go[i]] = 1;
    }
    printf ("NO\n");
    return 0;
}