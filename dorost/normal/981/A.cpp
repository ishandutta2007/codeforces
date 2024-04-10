#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string t;
            for (int k = i; k <= j; k++) {
                t += s[k];
            }
            string g = t;
            reverse(g.begin(), g.end());
            if (g != t)
                mx = max(mx, j - i + 1);
        }
    }
    cout << mx;
}