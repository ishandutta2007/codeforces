#include <iostream>
#include <algorithm>

using namespace std;

string s;

bool pal(string& s) {
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            return 0;
    return 1;
}

int main() {

    cin >> s;

    string ans = s.substr(0, 1);

    for (int m = 1; m < (1 << s.size()); ++m) {
        string t = "";
        for (int j = 0; j < s.size(); ++j)
            if ((1 << j) & m)
                t += s[j];
        if (!pal(t))
            continue;
        if (t > ans)
            ans = t;
    }
    cout << ans << "\n";
    return 0;
}