#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

template<typename container>
vector<int> gen_kmp(container const& s) {
    vector<int> res(1, 0);
    for (int cur = 0; res.size() < s.size(); ) {
        if (s[res.size()] == s[cur]) res.push_back(++cur);
        else if (cur) cur = res[cur - 1];
        else res.push_back(0);
    }
    return res;
}

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

string s, t;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    
    int cnt1 = (int)(count_if(s.begin(), s.end(), [](char c) { return c == '1'; }));
    int cnt0 = len(s) - cnt1;

    auto t_kmp = gen_kmp(t);
    int cur = 0;
    rep(i, len(s)) {
        if (!cnt1 or !cnt0) break;
        if (cur == len(t)) cur = t_kmp[cur - 1];
        if (t[cur++] == '1') {
            cout << '1';
            --cnt1;
        } else {
            cout << '0';
            --cnt0;
        }
    }
    cout << string(cnt1, '1') << string(cnt0, '0');

    return 0;
}