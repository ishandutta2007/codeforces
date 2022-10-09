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

namespace sol {
// solution start here
long n, k;

int main() {
    cin >> n >> k;
    vi ans;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0 and k > 1) {
            --k;
            n /= i;
            ans.push_back(i);
        }
    }
    ans.push_back(n);
    if (n == 1) cout << -1;
    else for (auto i : ans) cout << i << ' ';
    
    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}