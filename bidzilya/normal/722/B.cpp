#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const string YES = "YES";
const string NO = "NO";

inline bool IsAlpha(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);

        int cur = 0;
        for (int j = 0; j < (int) s.length(); ++j) {
            cur += IsAlpha(s[j]);
        }

        if (cur != p[i]) {
            cout << NO << endl;
            return 0;
        }
    }

    cout << YES << endl;

    return 0;
}