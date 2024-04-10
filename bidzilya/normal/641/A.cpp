#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<bool> used(n, false);
    for (int i = 0; i >= 0 && i < n; ) {
        if (used[i]) {
            cout << "INFINITE" << endl;
            return 0;
        }
        used[i] = true;
        if (s[i] == '<') {
            i -= d[i];
        } else {
            i += d[i];
        }
    }

    cout << "FINITE" << endl;

    return 0;
}