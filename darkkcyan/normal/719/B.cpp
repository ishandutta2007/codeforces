#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define lim numeric_limits
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

#define NN 101010
int n;
string s;
bitset<NN> bs;

int process() {
    int cnt[2] = {0};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (bs[i] != (i & 1)) {
            if (cnt[!bs[i]] == 0) ++cnt[bs[i]], ++ans;
            else --cnt[!bs[i]];
        }
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> s;
    bs = bitset<NN>(s.c_str(), n, 'r', 'b');

    int ans = process();
    bs = ~bs;
    ans = min(ans, process());
    cout << ans;

    return 0;
}