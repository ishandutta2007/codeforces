#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for (int i = -1; ++i < n; )

namespace Sol {

#define maxn 301010
int n;
int a[2 * maxn];
vi gr[maxn];
map<int, int> ma;

int main() {
    scanf("%d", &n);
    rep(i, n) {
        scanf("%d", &a[i]);
        ma[a[i] + 2]++;
    }
    rep(i, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    long ans = inf(long);
    rep(i, n) {
        if (--ma[a[i] + 2] == 0) ma.erase(a[i] + 2);
        ma[a[i]] ++;
        for(auto u : gr[i]) {
            if (--ma[a[u] + 2] == 0) ma.erase(a[u] + 2);
            ma[a[u] + 1]++;
        }
        ans = min(ans, (long)ma.rbegin()->xx);
        if (--ma[a[i]] == 0) ma.erase(a[i]);
        ma[a[i] + 2]++;
        for (auto u : gr[i]) {
            if (--ma[a[u] + 1] == 0) ma.erase(a[u] + 1);
            ma[a[u] + 2]++;
        }
    }
    cout << ans;


    return 0;
}}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    return Sol::main();
}