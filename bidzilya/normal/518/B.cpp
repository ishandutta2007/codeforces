#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> FromStringToMap(const string& s)
{
    map<char, int> res;
    for (int i = 0; i < (int) s.length(); ++i) {
        ++res[s[i]];
    }
    return res;
}

char GetChangedCase(char c)
{
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;

    map<char, int> mp = FromStringToMap(t);

    int ans1 = 0;
    int ans2 = 0;

    vector<bool> used(s.length(), false);
    for (int i = 0; i < (int) s.length(); ++i) {
        char c = s[i];
        if (mp[c] > 0) {
            ++ans1;
            --mp[c];
            used[i] = true;
        }
    }

    for (int i = 0; i < (int) s.length(); ++i) {
        char c = s[i];
        if (!used[i]) {
            c = GetChangedCase(c);
            if (mp[c] > 0) {
                ++ans2;
                --mp[c];
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}