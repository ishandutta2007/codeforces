#include <bits/stdc++.h>

using namespace std;

const int N = 1'000'007;
const int S = 500'001;

string get(string s)
{
    int cnt_b = 0;

    string ret;
    for (auto c: s) {
        if (c == 'B') {
            cnt_b ^= 1;
            continue;
        }

        if (ret.empty() || ret.back() != c) {
            ret.push_back(c);
        } else {
            ret.pop_back();
        }
    }

    if (cnt_b) {
        ret.push_back('B');
    }

    return ret;
}

void solve()
{
    string s, t;
    cin >> s >> t;

    if (get(s) == get(t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int cases;
    cin >> cases;

    while (cases--) {
        solve();
    }

    return 0;
}