#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, BASE = 1e5+5;
const ll MOD = 10000000000037LL;
ll hsh[MN];
vector<int> adj[MN];
ll mul (ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b&1) {
            res += a;
            if (res >= MOD) res -= MOD;
        }
        a += a;
        if (a >= MOD) a -= MOD;
        b>>=1;
    }
    return res;
}
int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    ll pw = 1;
    for (int i = 1; i < n; i++) pw = pw*BASE%MOD;
    while (m--) {
        int a,b;
        scanf ("%d %d",&a,&b);
        int distab = b-a;
        if (distab < 0) distab += n;
        int distba = a-b;
        if (distba < 0) distba += n;
        adj[a].push_back(distab); adj[b].push_back(distba);
    }
    for (int i = 1; i <= n; i++) {
        sort(all(adj[i]));
        for (int j : adj[i]) hsh[i] = (hsh[i]*BASE+j)%MOD;
    }
    ll oghsh = 0;
    for (int i = 1; i <= n; i++) oghsh = (oghsh*BASE+hsh[i])%MOD;
    ll nhsh = oghsh;
    for (int i = 1; i < n; i++) {
        nhsh -= mul(hsh[i],pw)%MOD;
        if (nhsh<0) nhsh += MOD;
        nhsh = (nhsh * BASE + hsh[i]) % MOD;
        if (nhsh == oghsh) return !printf ("Yes\n");
    }
    printf ("No\n");
    return 0;
}