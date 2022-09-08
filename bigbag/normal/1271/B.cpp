#include <bits/stdc++.h>

using namespace std;

const int max_n = 200022, inf = 1000111222;

int n, a[max_n];
string s;
vector<char> v{'W', 'B'};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (char c : v) {
        for (int i = 0; i < n; ++i) {
            a[i] = s[i] == c;
        }
        vector<int> ans;
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i]) {
                a[i] ^= 1;
                a[i + 1] ^= 1;
                ans.push_back(i);
            }
        }
        if (!a[n - 1]) {
            cout << ans.size() << endl;
            for (int pos : ans) {
                cout << pos + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}