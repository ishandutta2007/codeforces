#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string s;
int up[100005];
int lo[100005];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        up[i] = (i == 0) ? 0 : up[i - 1];
        lo[i] = (i == 0) ? 0 : lo[i - 1];
        up[i] += isupper(s[i]) != 0;
        lo[i] += islower(s[i]) != 0;
    }
    int ans = up[s.size() - 1];
    for (int i = 0; i < s.size(); ++i)
        ans = min(ans, lo[i] + up[s.size() - 1] - up[i]);
    cout << ans << "\n";
    return 0;
}