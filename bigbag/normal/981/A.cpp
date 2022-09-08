#include <bits/stdc++.h>

using namespace std;

string s;
int ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        string q = "";
        for (int j = i; j < s.length(); ++j) {
            q += s[j];
            bool f = false;
            for (int k = 0; k < q.length(); ++k) {
                if (q[k] != q[q.length() - k - 1]) {
                    f = true;
                    break;
                }
            }
            if (f) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}