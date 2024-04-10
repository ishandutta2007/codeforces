#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
bool gd(string s) {
    int bl = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            bl++;
        else
            bl--;
        if (bl < 0)
            return 0;
    }
    return 1;
}
void exper(string s) {
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            string s2 = s;
            reverse(s2.begin() + j, s2.begin() + i + 1);
            if (gd(s2))
                cout << j + 1 << ' ' << i + 1 << endl;
        }
    }
}
void solve(string s) {
    if (gd(s)) {
        cout << "0\n";
        return;
    }
    int prefmx = 0, ind = 0;
    int bl = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            bl++;
        else
            bl--;
        if (bl >= prefmx) {
            prefmx = bl;
            ind = i + 1;
        }
        if (bl < 0) {
            break;
        }
    }
    int prmx = 0;
    int mstrgt = -1;
    bl = 0;
    for (int i = ind; i < s.size(); ++i) {
        if (s[i] == '(')
            bl++;
        else
            bl--;
        prmx = max(prmx, bl);
        if (bl - prmx + prefmx >= 0) {
            mstrgt = i;
        }
    }
    if (mstrgt != -1) {
        string s2 = s;
        reverse(s2.begin() + ind, s2.begin() + mstrgt + 1);
        if (gd(s2)) {
            cout << 1 << '\n';
            cout << ind + 1 << ' ' << mstrgt + 1 << '\n';
            return;
        }
    }
    int prmn = 0;ind = 0;
    bl = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            bl++;
        else
            bl--;
        if (bl <= prmn) {
            prmn = bl;
            ind = i + 1;
        }
    }
    int ind2 = ind;
    prmx = 0;
    for (int i = ind; i < s.size(); ++i) {
        if (s[i] == '(')
            bl++;
        else
            bl--;
        if (bl >= prmx) {
            prmx = bl;
            ind2 = i;
        }
    }
    reverse(s.begin(), s.begin() + ind2 + 1);
    reverse(s.begin() + ind2 - ind + 1, s.end());
    if (!gd(s))
        exit(1);
    cout << 2 << '\n';
    cout << 1 << ' ' << ind2 + 1 << '\n';
    cout << ind2 - ind + 2 << ' ' << s.size() << '\n';
}
void gen() {
    int n = rand() % 10 + 2;
    string s(n * 2, ')');
    for (int i = 0; i < n; ++i) {
        s[i] = '(';
    }
    for (int i = 0; i < n * 2; ++i) {
        swap(s[i], s[rand() % s.size()]);
    }
    cout << s << '\n';
    solve(s);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //while (1) gen();
    cin >> t;
    while (t--) {
        int n;string s;
        cin >> n >> s;
        solve(s);
    }
}