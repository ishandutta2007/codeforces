#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

bool solve() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    s = "$" + s;

    vector<int> f(s.size());
    vector<int> t(s.size(), 1);
    vector<int> r(s.size(), 0);
    
    if (p == 1) r[1] = 1;

    for (int i = 2; i <= n; ++i) {

        int k = f[i - 1];
        while (k > 0) {
            if (s[k + 1] == s[i]) break;
            else k = f[k];
        }
        if (s[k + 1] == s[i]) ++k;
        f[i] = k;

        int l = i - f[i];
        if (l > 0 && i % l == 0) t[i] = i / l;

        if (t[i] % p == 0 || t[i] % (p + 1) == 0 || t[i] % (2 * p + 1) == 0) {
            r[i] = 1;
        } else {
            int d = i - i / l * l;
            if (t[i - d] >= p) {
                int j = t[i - d] / p;
                int L = j * l;
                d += (t[i - d] % p) * l;
                if (L > d) 
                    r[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) putchar('0' + r[i + 1]);
    cout << endl;

    return false;
}

int main() {

    while (solve());
    
    return 0;
}