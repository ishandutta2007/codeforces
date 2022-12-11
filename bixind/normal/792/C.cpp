#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>

using namespace std;

string rem(const string& s, int v, int sum) {
    string s1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (sum % 3 == 0 || (s[i] - '0') % 3 != v) {
            s1.push_back(s[i]);
        } else {
            sum -= (s[i] - '0');
        }
    }
    if (sum % 3 != 0)
        return "";
    while (s1.size() > 1 && s1.back() == '0')
        s1.pop_back();
    return s1;
}

void solve() {
    string s;
    cin >> s;
    int sum = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        sum += (s[i] - '0');
    }
    string s1 = rem(s, 1, sum);
    string s2 = rem(s, 2, sum);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if (s1.size() == s2.size() && s1.size() == 0) {
        cout << "-1" << endl;
    } else {
        cout << (s1.size() > s2.size() ? s1 : s2) << endl;
    }
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

}