#include <bits/stdc++.h>

using namespace std;

const string s = "codeforces";
const int n = 10;

long long k;
int cnt[22];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> k;
    int pos = 0;
    while (true) {
        long long x = 1;
        for (int i = 0; i < n; ++i) {
            x *= cnt[i];
        }
        if (x >= k) {
            break;
        }
        ++cnt[pos];
        pos = (pos + 1) % n;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}