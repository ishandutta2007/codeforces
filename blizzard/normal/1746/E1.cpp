#include <bits/stdc++.h>

#ifdef LOCAL
#define err cerr
#else
#define err if (false) cerr
#endif

using namespace std;
using ll = long long;

using bs = bitset<200000>;

const int MAXN = 200000;
vector<int> e[MAXN];

bool ask(const vector<int>& a, const vector<int>& b) {
    cout << "? " << a.size() + b.size() << " ";
    for (auto x : a) {
        cout << x << " ";
    }
    for (int i = 0; i < b.size(); i++) {
        cout << b[i];
        if (i != b.size() - 1) cout << " ";
    }
    cout << endl;
    string s;
    cin >> s;
    return s == "YES";
}

void solve() {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    while (s.size() > 3) {
        vector<vector<int>> v(4);
        int i = 0;
        for (int x : s) {
            v[i].push_back(x);
            i++;
            if (i == 4) i = 0;
        }
        bool fl1 = ask(v[0], v[1]);
        bool fl2 = ask(v[0], v[2]);
        if (fl1 and fl2) {
            for (int x : v[3])
                s.erase(x);
        }
        if (fl1 and !fl2) {
            for (int x : v[2])
                s.erase(x);
        }
        if (!fl1 and fl2) {
            for (int x : v[1])
                s.erase(x);
        }
        if (!fl1 and !fl2) {
            for (int x : v[0])
                s.erase(x);
        }
    }
    string ss;
    if (s.size() > 2) {
        bool fl1 = ask({}, {*s.begin()});
        bool fl2 = ask({}, {*s.rbegin()});
        bool fl3 = ask({}, {*s.rbegin()});
        bool fl4 = ask({}, {*s.begin()});

        if (fl2 and fl3) {
            cout << "! " << *s.rbegin() << endl;
            cin >> ss;
            assert(ss == ":)");
            return;
        }
        if (!fl2 and !fl3) {
            s.erase(--s.end());
        }
        if (!fl1 and fl2 and !fl3 and !fl4) {
            s.erase(s.begin());
        }
        if (!fl1 and !fl2 and fl3 and !fl4) {
            s.erase(s.begin());
        }
        if (fl1 and fl2 and !fl3 and fl4) {
            cout << "! " << *s.begin() << endl;
            cin >> ss;
            assert(ss == ":)");
            return;
        }
        if (fl1 and !fl2 and fl3 and fl4) {
            cout << "! " << *s.begin() << endl;
            cin >> ss;
            assert(ss == ":)");
            return;
        }
        if (fl1 and fl2 and !fl3 and !fl4) {
            s.erase(++s.begin());
        }
        if (!fl1 and !fl2 and fl3 and fl4) {
            s.erase(++s.begin());
        }
        if (!fl1 and fl2 and !fl3 and fl4) {
            s.erase(++s.begin());
        }
        if (fl1 and !fl2 and fl3 and !fl4) {
            s.erase(++s.begin());
        }
    }
    cout << "! " << *s.begin() << endl;

    cin >> ss;
    if (ss == ":)") {
        return;
    }
    s.erase(s.begin());
    cout << "! " << *s.begin() << endl;
    cin >> ss;
    assert(ss == ":)");
}

signed main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}