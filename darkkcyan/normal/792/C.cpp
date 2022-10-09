#include <bits/stdc++.h>

using namespace std;

#define long long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define inf(t) (numeric_limits<t>::max())
#define rep(i,n) for(int i = -1; ++i < n; )

string s;
vi cnt[3];

void del(int c1, int c2, string& t) {
    vi delpos;
    rep(i, c1) delpos.push_back(cnt[1][i]);
    rep(i, c2) delpos.push_back(cnt[2][i]);
    for (int i = c1 + c2; i--; ) t.erase(delpos[i], 1);
    while (sz(t) > 1 and t[sz(t) - 1] == '0') t.erase(sz(t) - 1, 1);
}

int cntdel(int c1, int c2) {
    if (sz(cnt[1]) < c1) return -1;
    if (sz(cnt[2]) < c2) return -1;
    string t = s;
    del(c1, c2, t);
    //clog << c1 << ' ' << c2 << ' ' << t << endl;
    if (sz(t) == 0) return -1;
    return sz(s) - sz(t);
}

#define iii pair<int, ii>

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s; reverse(s.begin(), s.end());

    del(0, 0, s);
    int m3 = 0;

    rep (i, sz(s)) {
        m3 = (m3 + s[i] - '0') % 3;
        cnt[(s[i] - '0') % 3].push_back(i);
    }

    //clog << m3 << endl;

    iii ans(inf(int), ii());
    if (m3 == 0) {
        reverse(s.begin(), s.end());
        cout << s, exit(0);
    }
    if (m3 == 1) {
        int c1 = cntdel(1, 0);
        int c2 = cntdel(0, 2);
        if (c1 != -1) ans = min(ans, iii(c1, ii(1, 0)));
        if (c2 != -1) ans = min(ans, iii(c2, ii(0, 2)));
    } else {
        int c1 = cntdel(2, 0);
        int c2 = cntdel(0, 1);
        if (c1 != -1) ans = min(ans, iii(c1, ii(2, 0)));
        if (c2 != -1) ans = min(ans, iii(c2, ii(0, 1)));
    }

    if (ans.xx == inf(int)) cout << -1;
    else {
        del(ans.yy.xx, ans.yy.yy, s);
        reverse(s.begin(), s.end());
        cout << s;
    }

    return 0;
}