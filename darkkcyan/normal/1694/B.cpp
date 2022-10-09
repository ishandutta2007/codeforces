#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string s;
        cin >> n >> s;
        long long ans = n;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) continue;
            ans += i;
        }
        cout << ans << '\n';
    }
}