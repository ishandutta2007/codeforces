#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (s.size() <= 2)
        return cout << "YES" << endl, 0;
    for (int i = 2; i < (int)s.size(); i++) {
        if (s[i] - 'A' != ((int)s[i - 1] - 'A' + (int)s[i - 2] - 'A') % 26)
            return cout << "NO" << endl, 0;
    }
    cout << "YES" << endl;

}