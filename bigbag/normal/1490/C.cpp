/**
 *  created: 16/02/2021, 16:43:37
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 10011;

int t;
vector<long long> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int x = 1; x < inf; ++x) {
        v.push_back(1LL * x * x * x);
    }
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int pos = v.size() - 1;
        bool ok = 0;
        for (int i = 0; i < v.size(); ++i) {
            while (pos > 0 && v[i] + v[pos] > x) {
                --pos;
            }
            if (v[i] + v[pos] == x) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }

    }
    return 0;
}