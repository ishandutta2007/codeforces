#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<long long> total = {1}, stk = {0};
    long long ans = 0;

    while (n--) {
        string s; cin >> s;
        if (s == "add") {
            cerr << "ADDING: " << total.back() << endl;
            ans += total.back();
            if (ans > (1LL << 32) - 1) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
        if (s == "for") {
            long long x; cin >> x;
            total.push_back(min((long long)1e12, total.back() * x));
            stk.push_back(x);
        }
        if (s == "end") {
            stk.pop_back();
            total.pop_back();
        }
    }
    cout << ans << endl;

    return 0;
}