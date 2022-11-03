#include <bits/stdc++.h>
using namespace std;

const int kModulus = 1e9 + 7;

vector<int> GetZFunction(const string& s)
{
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    for (int l = -1, r = -1, i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    string p;
    cin >> p;
    vector<bool> is_occ(n);
    for (int i = 0; i < m; ++i) {
        int occ;
        cin >> occ;
        --occ;
        is_occ[occ] = true;
    }
    string sz = p + '#' + p;
    vector<int> z = GetZFunction(sz);
    int pn = p.length();
    int ans = 1;
    for (int i = 0, l = -1, r = -1; i < n; ++i) {
        if (is_occ[i]) {
            if (i <= r) {
                if (!(z[pn + 1 + (i - l)] >= r - i + 1)) {
                    cout << 0 << endl;
                    return 0;
                }
            } 
            l = i;
            r = i + pn - 1;
        } else {
            if (i > r) {
                ans = (26LL * ans) % kModulus;
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}