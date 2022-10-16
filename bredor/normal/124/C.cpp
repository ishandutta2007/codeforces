//  228

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int f[26];
int main()
{
    string s; cin >> s;
    int sz = (int)s.size();
    for (int i = 0; i < sz; ++i)
        f[s[i] - 'a']++;
    vector<char>ans(sz + 1, '0');
    for (int i = 2; i <= sz; i++) {
        if (ans[i] == '0') {
            char intersect = '0';
            for(int j = i + i ; j <= sz ; j += i)
                if (ans[j] != '0') {
                    intersect = ans[j];
                    break;
                }
            char a = 'a';
            if (intersect != '0')
                a = intersect;
            else {
                int mx = INT_MIN;
                for (int i = 0; i < 26; ++i)
                    if (f[i] > mx) mx = f[i], a = char(i + 'a');
            }
            for (int j = i; j <= sz; j += i)
            {
                if (ans[j] == '0') {
                    if (f[a - 'a'] == 0) return cout << "NO", 0;
                    ans[j] = a , f[a - 'a']--;
            }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < 26; ++i)
        if (f[i]) ans[1] = char(i + 'a');
    for (int i = 1; i <= sz; ++i) cout << ans[i];
    return 0;
}