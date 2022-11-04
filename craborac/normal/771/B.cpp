#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;

int n, k;
string ans[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ans[i] = "";
        ans[i] += (i / 26) + 'A';
        ans[i] += (i % 26) + 'a';
    }
    for (int i = 0; i < n - k + 1; i++) {
        string t;
        cin >> t;
        if (t[0] == 'N') {
            ans[k - 1 + i] = ans[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
}