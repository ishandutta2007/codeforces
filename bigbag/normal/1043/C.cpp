#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

string s;
int ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i < s.length(); ) {
        int st = i;
        while (i < s.length() && s[i] == s[st]) {
            ++i;
        }
        if (s[st] == 'a' || (s[st] == 'b' && i < s.length())) {
            ans[i - 1] = 1;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}