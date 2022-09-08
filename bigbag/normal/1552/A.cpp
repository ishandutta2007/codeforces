/**
 *  created: 25/07/2021, 17:35:46
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        string q = s;
        sort(q.begin(), q.end());
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            cnt += q[i] == s[i];
        }
        cout << s.size() - cnt << "\n";
    }
    return 0;
}