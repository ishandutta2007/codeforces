#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

pair<int, int> Solve(int a, int b) {
    if (b == 0) {
        if (a == 1) return make_pair(0, 0);
        return make_pair(0, 100000000);
    }
    int rem = a % b;
    int div = a / b;
    auto p = Solve(b, rem);
    p.first += (div - 1);
    p.second += div;
    return p;
}

string output;
void Output(int a, int b, char last) {
    if (a == 0 or b == 0) return;
    if (a == 1 and b == 1) {
        output += (last ^ 'B' ^ 'T');
        return;
    }

    if (a > b) {
        Output(a - b, b, 'B');
        output += 'B';
    } else {
        Output(a, b - a, 'T');
        output += 'T';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, r; cin >> n >> r;
    pair<int, int> ans = {1e8, 1e8};

    for (int oth = 1; oth <= r; ++oth) {
        auto p = Solve(r, oth);
        if (p.second == n) {
            ans = min(ans, make_pair(p.first, oth));
        }    
    }
    if (ans.first <= n) {
        cout << max(0, ans.first - 1) << endl;
        Output(r, ans.second, 'B');
        char xor_with = 0;
        if (output[0] == 'B') {
            xor_with = ('B' ^ 'T');
        }
        for (auto x : output) {
            cout << char(x ^ xor_with);
        }
        cout << endl;

    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}