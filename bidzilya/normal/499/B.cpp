#include <bits/stdc++.h>
using namespace std;

map<string, string> mp;
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int l1 = s.length();
        int l2 = (mp[s]).length();

        string r;
        if (l1 <= l2) {
            r = s;
        } else {
            r = mp[s];
        }

        cout << r;
        if (i + 1 != n) {
            cout << " ";
        }
    }
    cout << endl;


    return 0;
}