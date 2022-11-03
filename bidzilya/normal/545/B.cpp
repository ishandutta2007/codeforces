#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.length();
    string p;
    p.resize(n);
    int sm = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            p[i] = s[i];
        } else {
            if (sm >= 0) {
                p[i] = s[i];
                --sm;
            } else {
                ++sm;
                p[i] = t[i];
            }
        }
    }
    if (sm == 0) {
        cout << p << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}