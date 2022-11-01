#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

map<string, bool> m;
string s[200200];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    reverse(s, s + n);
    for (int i = 0; i < n; ++i) {
        if (m.find(s[i]) != m.end()) continue;
        cout << s[i] << endl;
        m[s[i]] = true;
    }

    return 0;
}