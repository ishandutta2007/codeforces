#include <bits/stdc++.h>
using namespace std;

int Find(const string& s, const string& t)
{
    for (int i = 0, j = 0; i < (int) s.length() && j < (int) t.length(); ++j) {
        if (s[i] == t[j]) {
            ++i;
        }
        if (i == (int) s.length()) {
            return j;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    int pos1 = Find(s, t);

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    int pos2 = Find(s, t);

    if (pos1 != -1 && pos2 != -1) {
        pos2 = m - pos2 - 1;

        if (pos1 < pos2) {
            cout << pos2 - pos1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}