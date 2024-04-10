#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

vector<int> find_pos(const string& s, const string& sub) {
    vector<int> ans;
    rep(i, len(s) - len(sub) + 1) {
        bool ok = 1;
        rep(f, len(sub)) {
            if (sub[f] == s[i + f]) continue;
            ok = false;
            break;
        }
        if (ok) ans.push_back(i);
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        vector<int> ans;
        auto twone = find_pos(s, "twone");
        for (auto i: twone) {
            ans.push_back(i + 2);
            s[i + 2] = ' ';
        }
        auto one = find_pos(s, "one");
        auto two = find_pos(s, "two");
        for (auto i: one) ans.push_back(i + 1);
        for (auto i: two) ans.push_back(i + 1);
        cout << len(ans) << '\n';
        for (auto i: ans) cout << i + 1 << ' ';
        cout << '\n';
    }

    return 0;
}