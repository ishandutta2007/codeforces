#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int ntest; cin >> ntest;
    while (ntest--) {
        string s; cin >> s;
        int p[4];
        p[1] = p[2] = p[3] = s.size();
        int ans = s.size() + 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            p[s[i] - '0'] = i;
            int r = max({p[1], p[2], p[3]});
            if (r != s.size()) ans = min(ans, r - i + 1);
        }
        if (ans > s.size()) cout << "0\n";
        else cout << ans << '\n';
    }
}