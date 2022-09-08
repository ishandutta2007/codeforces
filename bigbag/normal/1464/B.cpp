/**
 *  created: 20/12/2020, 17:41:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111;
const long long inf = 1000111222000111222LL;

int zeros[max_n], ones[max_n];
string s;
long long x[2], ans = inf;

long long solve() {
    long long res = inf;
    vector<int> v;
    for (int i = 0; i < s.length(); ++i) {
        zeros[i] = s[i] == '0';
        ones[i] = s[i] == '1';
        if (i) {
            zeros[i] += zeros[i - 1];
            ones[i] += ones[i - 1];
        }
        if (s[i] == '?') {
            v.push_back(i);
        }
    }
    const int tot0 = zeros[s.length() - 1];
    const int tot1 = ones[s.length() - 1];
    long long cur = 0;
    for (int i = 0; i < v.size(); ++i) {
        cur += x[0] * zeros[v[i]];
        cur += x[1] * (tot0 - zeros[v[i]]);
    }
    res = cur;
    //cout << "#" << cur << endl;
    for (int i = 0; i < v.size(); ++i) {
        cur -= x[0] * zeros[v[i]];
        cur -= x[1] * (tot0 - zeros[v[i]]);

        cur += x[1] * ones[v[i]];
        cur += x[0] * (tot1 - ones[v[i]]);

        cur += x[0] * (v.size() - i - 1);
        cur -= x[0] * (i);

        res = min(res, cur);
        //cout << "#" << cur << endl;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1') {
            res += x[0] * zeros[i];
        } else if (s[i] == '0') {
            res += x[1] * ones[i];
        }
    }
    return res;
}

int main() {
    //freopen("output.txt", "w", stdout);
    cin >> s >> x[0] >> x[1];
    for (int it = 0; it < 2; ++it) {
        ans = min(ans, solve());
        swap(x[0], x[1]);
        reverse(s.begin(), s.end());
        //cout << s << endl;
    }
    cout << ans << "\n";
    return 0;
}