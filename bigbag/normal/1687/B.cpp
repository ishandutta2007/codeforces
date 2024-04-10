/**
 *  created: 03/06/2022, 18:02:55
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int n, m;
pair<int, int> a[max_n];

int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s(m, '0');
        s[i] = '1';
        a[i] = {ask(s), i};
    }
    sort(a, a + m);
    string s(m, '0');
    int cur = 0;
    for (int i = 0; i < m; ++i) {
        s[a[i].second] = '1';
        int val = ask(s);
        if (cur + a[i].first != val) {
            s[a[i].second] = '0';
        } else {
            cur = val;
        }
    }
    cout << "! " << cur << endl;
    return 0;
}