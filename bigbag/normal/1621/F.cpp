/**
 *  created: 03/01/2022, 17:49:00
**/

#include <bits/stdc++.h>

using namespace std;

int t, n, a, b, c;
string s;

const bool debug = 0;

long long solve() {
    vector<int> v[2], add, ops(2);
    for (int i = 0; i < n; ) {
        int pos = i;
        while (i < n && s[pos] == s[i]) {
            ++i;
        }
        if (s[pos] == '0' && (pos == 0 || i == n)) {
            add.push_back(i - pos);
        } else {
            v[s[pos] - '0'].push_back(i - pos);
        }
        ops[s[pos] - '0'] += i - pos - 1;
    }
    sort(v[0].begin(), v[0].end());
    reverse(v[0].begin(), v[0].end());
    long long res = 0;
    if (c >= b) {
        for (int start = 0; start < 2; ++start) {
            vector<int> ok_ops(2);
            ok_ops[start] = min(ops[start], ops[start ^ 1] + 1);
            ok_ops[start ^ 1] = min(ops[start ^ 1], ops[start]);
            //cout << "#" << ops[0] << " " << ops[1] << " -> " << ok_ops[0] << " " << ok_ops[1] << endl;
            res = max(res, 1LL * ok_ops[0] * a + 1LL * ok_ops[1] * b);
        }
    }
    auto cv0 = v[0], cv1 = v[1], cadd = add;
    int cops0 = ops[0], cops1 = ops[1];
    for (int start = 0; start < 2; ++start) {
        v[0] = cv0;
        v[1] = cv1;
        add = cadd;
        ops[0] = cops0;
        ops[1] = cops1;
        int f = start, ones = 0;
        long long tot = 0;
        while (!v[0].empty() && v[0].back() == 1) {
            ++ones;
            v[0].pop_back();
        }
        if (debug) cout << "$" << add.size() << endl;
        if (debug) cout << "$$$" << v[0].size() << " " << ones << "    " << ops[0] << endl;
        while (true) {
            if (f) {
                if (debug) cout << 2;
                if (!ops[1]) {
                    break;
                }
                --ops[1];
                tot += b;
            } else {
                if (!ops[1] && ones) {
                    --ones;
                    ++ops[1];
                    tot -= c;
                    if (debug) cout << 3;
                } else if (!v[0].empty()) {
                    --v[0].back();
                    tot += a;
                    if (v[0].back() == 1) {
                        v[0].pop_back();
                        ++ones;
                    }
                    if (debug) cout << 1;
                } else if (!add.empty()) {
                    int id = 0;
                    for (int i = 0; i < add.size(); ++i) {
                        if (add[i] > 1) {
                            id = i;
                        }
                    }
                    if (add[id] > 1) {
                        --add[id];
                        tot += a;
                        if (debug) cout << 1;
                    } else if (add[id] == 1) {
                        if (ones) {
                            --ones;
                            ++ops[1];
                            tot -= c;
                            if (debug) cout << 3;
                        } else if (!ops[1]) {
                            break;
                        } else {
                            tot -= c;
                            add.erase(add.begin() + id);
                        }
                    }
                } else if (ones) {
                    --ones;
                    ++ops[1];
                    tot -= c;
                    if (debug) cout << 3;
                } else {
                    break;
                }
            }
            f ^= 1;
        }
        if (debug) cout << endl << start << ": " << tot << endl;
        res = max(res, tot);
    }
    return res;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> s;
        cout << solve() << "\n";
    }
    return 0;
}