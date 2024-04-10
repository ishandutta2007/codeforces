#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(239);
constexpr int N = 1e5 + 5;
constexpr int M = 1e4 + 5;
int dp[N];
int a[N];
set<string> mn;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < (1 << n); i++) {
        string t = s;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                t[j]-= '0';
                t[j] = 9 - t[j];
                t[j] += '0';
            }
        }
        if (t[0] != '0')
        mn.insert(t);
    }
    cout << *mn.begin() << "\n";
}