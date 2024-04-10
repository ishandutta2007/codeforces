#include<iostream>
#include<algorithm>
using namespace std;
void solve() {
    string s[2];
    cin >> s[0] >> s[1];
    s[0] += s[1];
    sort(s[0].begin(), s[0].end());
    int an = 0;
    for(int i = 1; i < 4; i++) {
        an += (s[0][i] != s[0][i - 1]);
    }
    cout << an << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}