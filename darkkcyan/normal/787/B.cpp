#include <bits/stdc++.h>

using namespace std;

#define long long long
#define ve vector
#define vi ve<int>
#define ii pair<int, int>
#define xx first
#define yy second
#define sz(v) ((int)v.size())
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

namespace Sol {
vi cnt[2];
int main() {
    int n, m; cin >> n >> m;
    cnt[0].resize(n + 1); cnt[1] = cnt[0];
    while (m--) {
        static vi inp;
        int k; cin >> k;
        inp.resize(k);
        rep(i, k) cin >> inp[i];
        bool has = true;
        for (auto i: inp) cnt[i < 0][abs(i)]++;
        for (auto i: inp) if (cnt[i > 0][abs(i)]) {
            has = false;
            break;
        }
        if (has) {
            cout << "YES";
            exit(0);
        }
        for (auto i: inp) cnt[i < 0][abs(i)] --;
    }
    cout << "NO";
    
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return Sol::main();
}