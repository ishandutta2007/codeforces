#include <bits/stdc++.h>
using namespace std;

int main() {
    string ans(10, '0');
    int n; cin >> n;
    string s; cin >> s;
    for (auto c: s) {
        if (isdigit(c)) ans[c - '0'] = '0';
        else if (c == 'L') ans[ans.find_first_of('0')] = '1';
        else if (c == 'R') ans[ans.find_last_of('0')] = '1';
    }
    cout << ans;
    return 0;
}