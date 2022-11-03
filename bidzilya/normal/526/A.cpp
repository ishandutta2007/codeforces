#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    bool found = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; i + 4 * j < n; ++j) {
            bool cur_good = true;
            for (int k = 0; k <= 4; ++k) {
                if (s[i + j * k] == '.') {
                    cur_good = false;
                }
            }
            if (cur_good) {
                found = true;
            }
        }
    }

    if (found) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}