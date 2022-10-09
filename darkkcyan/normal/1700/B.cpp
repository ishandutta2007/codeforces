#include <bits/stdc++.h>
using namespace std;

int main() {
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int len;
        cin >> len;
        string num;
        cin >> num;
        
        if (num[0] != '9') {
            for (auto ch: num) {
                cout << char('9' - ch + '0');
            }
            cout << '\n';
            continue;
        }
        
        string ans;
        int borrow = 0;
        for (int i = 0; i < len; ++i) {
            int target = i == 0 ? 1 : 2;
            target -= borrow;
            target -= num.rbegin()[i] - '0';
            if (target < 0) {
                borrow = 1;
                target += 10;
            } else {
                borrow = 0;
            }
            ans += char(target % 10 + '0');
        }
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}