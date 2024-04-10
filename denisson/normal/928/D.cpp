#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 1
using lint = long long;

int ch[333333][33];
int d[333333];
bool f[333333];
int deg[333333];
int lid = 1;

int ans = 0;

void add(const string& s) {
    int cur = 0;
    rep(i, 0, s.size()) {
        int c = s[i] - 'a';
        if (ch[cur][c] == -1) {
            ch[cur][c] = lid++;
            deg[cur]++;
        }
        cur = ch[cur][c];
        f[cur] = false;
        d[cur]++;
    }
    f[cur] = true;
}

bool have(const string& s) {
    int cur = 0;
    rep(i, 0, s.size()) {
        int c = s[i] - 'a';
        if (ch[cur][c] == -1) {
            return false;
        }
        cur = ch[cur][c];
    }
    return f[cur];
}

int get(const string& s) {
    int f1 = -1;
    int cur = 0;
    rep(i, 0, s.size()) {
        int c = s[i] - 'a';
        if (ch[cur][c] == -1) {
            if (f1 != -1 && deg[cur] == 0) {
                return min(int(s.size()), f1 + 1 + int(s.size()) - i);
            }
            return s.size();
        }
        cur = ch[cur][c];
        if (f1 == -1 && d[cur] == 1) {
            f1 = i + 1;
        }
    }

    if (f1 != -1 && deg[cur] == 0) {
        return min(int(s.size()), f1 + 1);
    }

    return s.size();
}

void go(const string& s) {
    int x = get(s);
    ans += x;
    if (!have(s)) {
        add(s);
    }
}

void solve(istream& cin, ostream& cout) {
    memset(ch, -1, sizeof(int) * 333333 * 33);
    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    memset(deg, 0, sizeof(f));
    lid = 1;
    ans = 0;

    string s;
    while (getline(cin, s)) {
        s.push_back('\n');
        int l = -1;
        rep(i, 0, s.size()) {
            if (s[i] < 'a' || s[i] > 'z') {
                ans++;
                if (l + 1 != i) {
                    go(s.substr(l + 1, i - l - 1));
                }
                l = i;
            }
        }
    }
    cout << ans;
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand(322326);
    for (int ti = 0; ti < 1000; ti++) {
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