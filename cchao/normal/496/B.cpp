#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s, ans;
    cin >> s; ans = s;
    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < n; ++j) s[j] = s[j] == '9' ? '0' : s[j] + 1;
        for(int j = 0; j < n; ++j)
            ans = min(ans, s.substr(j) + s.substr(0, j));
    }
    cout << ans << endl;
    return 0;
}