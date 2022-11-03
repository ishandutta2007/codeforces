#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    
    int n = s.length();
    
    vector<bool> pr(n, false);
    vector<bool> sf(n, false);
    pr[0] = false;
    for (int i = 1; i < n; ++i) {
        pr[i] = pr[i - 1];
        if (s[i] == 'A' && s[i - 1] == 'B') {
            pr[i] = true;
        }
    }
    
    sf[n - 1] = false;
    for (int i = n - 2; i >= 0; --i) {
        sf[i] = sf[i + 1];
        if (s[i] == 'B' && s[i + 1] == 'A') {
            sf[i] = true;
        }
    }
    
    bool found = false;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'A' && s[i + 1] == 'B') {
            if (i > 0 && pr[i - 1]) {
                found = true;
            }
            if (i + 2 < n && sf[i + 2]) {
                found = true;
            }
        }
    }
    if (found) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}