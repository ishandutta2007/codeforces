#include <bits/stdc++.h>
using namespace std;

const int MAXn = 2e5 + 5;

int ans[MAXn];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int last0 = -1, last1 = -1;
        for (last0++; last0 < (int)s.size() && s[last0] != '0'; last0++);
        for (last1++; last1 < (int)s.size() && s[last1] != '1'; last1++);
        int cnt = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '0') {
                if (last1 >= i)
                    cnt += 1, ans[i] = cnt;
                else {
                    ans[i] = ans[last1];
                    for (last1++; last1 < (int)s.size() && s[last1] != '1'; last1++);
                }
            }
            else { // s[i] == '1'
                if (last0 >= i)
                    cnt += 1, ans[i] = cnt;
                else {
                    ans[i] = ans[last0];
                    for (last0++; last0 < (int)s.size() && s[last0] != '0'; last0++);
                }
            }
        }
        cout << cnt << "\n";
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}