#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<int> GetZFunction(const string& s) {
    const int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    for (int i = 1, l = -1, r = -1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        } else {
            z[i] = 0;
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string t;
    cin >> s >> t;

    string rs = s;
    reverse(rs.begin(), rs.end());

    vector<pair<int, int>> result;

    for (int i = 0; i < (int) t.length(); ) {
        string buf = t.substr(i) + '1' + s + '2' + rs;

        vector<int> z = GetZFunction(buf);

        int maxLen = 0;
        int l, r;

        int start = (int) t.length() - i + 1;
        for (int i = start; i < start + (int) s.length(); ++i) {
            if (z[i] > maxLen) {
                maxLen = z[i];
                l = i - start;
                r = l + maxLen - 1;
            }
        }
        start += (int) s.length() + 1;
        for (int i = start; i < (int) buf.size(); ++i) {
            if (z[i] > maxLen) {
                maxLen = z[i];
                l = i - start;
                r = l + maxLen - 1;
                l = (int) s.length() - l - 1;
                r = (int) s.length() - r - 1;
            }
        }

        if (maxLen == 0) {
            cout << -1 << endl;
            return 0;
        }

        result.push_back(make_pair(l, r));
        i += maxLen;
    }

    cout << result.size() << endl;
    for (int i = 0; i < (int) result.size(); ++i) {
        cout << result[i].first + 1 << " " << result[i].second + 1 << endl;
    }

    return 0;
}