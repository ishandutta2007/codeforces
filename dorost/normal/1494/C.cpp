/*  * In the name of GOD 
    * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;

int ans (vector <int> a, vector <int> b) {
    if (a.size() == 0 || b.size() == 0)
        return 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <pair <int, int>> prep, prek, suf, suf2;
    int x = 0;
    set <int> st;
    for (int i = 0; i < a.size(); i++) {
        x++;
        prep.push_back({a[i], x});
        prek.push_back({a[i] - x, a[i]});
        st.insert(a[i]);
    }
    int y = 0;
    for (int i = b.size() - 1; i >= 0; i--) {
        if (st.count(b[i]))
            y++;
        suf.push_back({b[i], y});
    }
    int z = 0;
    for (int i = 0; i < b.size(); i++) {
        z++;
        suf2.push_back({b[i], z});
    }
    reverse(suf.begin(), suf.end());
    int mx = suf[0].S;
    for (int i = 0; i < b.size(); i++) {
        int c, t, u;
        if ((upper_bound(prep.begin(), prep.end(), make_pair(b[i] + 1, -1)) == prep.begin()))
            c = 0;
        else
            c = (*((upper_bound(prep.begin(), prep.end(), make_pair(b[i] + 1, -1)) - 1))).S;
        t = b[i] - c;
        if (upper_bound(prek.begin(), prek.end(), make_pair(t + c, -1)) - prek.begin() == 0)
            u = INT_MAX;
        else
            u = (*(upper_bound(prek.begin(), prek.end(), make_pair(t + c, -1)) - 1)).S + ((c + t) - (*(upper_bound(prek.begin(), prek.end(), make_pair(t + c, -1)) - 1)).F) - 1;
        int l;
        if (upper_bound(suf2.begin(), suf2.end(), make_pair(b[i], -1)) == suf2.begin())
            l = 0;
        else
            l = (*(upper_bound(suf2.begin(), suf2.end(), make_pair(b[i], -1)) - 1)).S;
        int r;
        if (upper_bound(suf2.begin(), suf2.end(), make_pair(u + 1, -1)) == suf2.begin())
            r = 0;
        else
            r = (*(upper_bound(suf2.begin(), suf2.end(), make_pair(u + 1, -1)) - 1)).S;
        int ans = max(0, r - l), o;
        if (upper_bound(suf.begin(), suf.end(), make_pair(u + 1, -1)) - suf.begin() == suf.size())
            o = 0;
        else
            o = (*(upper_bound(suf.begin(), suf.end(), make_pair(u + 1, -1)))).S;
        ans += o;
      //cout << i << ' ' << c << ' ' << t << ' ' << u << ' ' << l << ' ' << r << ' ' << o << '\n';
        mx = max(mx, ans);
    }
    return mx;
}

int a[N], b[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector <int> va, wa, vb, wb;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            va.push_back(-a[i]);
        } else {
            wa.push_back(a[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        if (b[i] < 0) {
            vb.push_back(-b[i]);
        } else {
            wb.push_back(b[i]);
        }
    }
    cout << ans(va, vb) + ans(wa, wb) << ' ';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}