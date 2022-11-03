#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

void f(string& s) {
    for (char& c : s) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }
        if (c == '0') {
            c = 'O';
        }
        if (c == '1' || c == 'I') {
            c = 'L';
        }
    }
}

void solve(istream& cin, ostream& cout) {
    string s;
    cin >> s;
    f(s);
    int n;
    cin >> n;
    rep(i, 0, n) {
        string t;
        cin >> t;
        f(t);
        if (s == t) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}