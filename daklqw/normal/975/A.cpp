#include <iostream>
#include <algorithm>

using namespace std;
string s[101000];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        std::sort(s[i].begin(), s[i].end());
        for (int j = 1; j < s[i].length(); j++)
            if (s[i][j] == s[i][j - 1]) s[i].erase(s[i].begin() + j), --j;
    }
    std::sort(s + 1, s + n + 1); int ans = 1;
    // for (int i = 1; i <= n; i++) cout << s[i] << endl;
    for (int i = 2; i <= n; i++) if (s[i] != s[i - 1]) ++ans;
    cout << ans << endl;
    return 0;
}