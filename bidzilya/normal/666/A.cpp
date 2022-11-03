#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = s.length();

    set<string> result;

    vector<bool> can[4];

    can[2].assign(n + 1, false);
    can[3].assign(n + 1, false);

    can[2][n] = can[3][n] = true;
    for (int i = n - 1; i >= 0; --i) {
        if (i < 5) {
            continue;
        }

        for (int len : {2, 3}) {
            if (i + len > n) {
                continue;
            }
            const string& t = s.substr(i, len);
            if (i + len == n) {
                can[len][i] = true;
                result.insert(t);
                continue;
            }
            for (int len2 : {2, 3}) {
                if (i + len + len2 > n) {
                    continue;
                }
                const string& t2 = s.substr(i + len, len2);

                if (can[len2][i + len] && t != t2) {
                    can[len][i] = true;
                    result.insert(t);
                }
            }
        }
    }

    cout << result.size() << endl;
    for (const string& t : result) {
        cout << t << '\n';
    }
    cout.flush();

    return 0;
}