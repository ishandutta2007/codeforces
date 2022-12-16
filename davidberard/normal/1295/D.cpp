#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

void solve() {
    vector<ll> bad;
    ll a, m;
    cin >> a >> m;
    ll ai = a, mi = m;
    ll g = __gcd(a, m);
    ll g_alt = 1;
    for (ll i=2; i*i<=a || i*i<=m; ++i) {
        int ac = 0, mc = 0;
        while (a%i == 0) {
            ++ac;
            a/=i;
        }
        while (m%i == 0) {
            ++mc;
            m/=i;
        }
        if (ac < mc) bad.push_back(i);
        for (int j=0; j<min(ac, mc); ++j) {
            g_alt *= i;
        }
    }

    if (m != 1 && a != m) {
        bad.push_back(m);
    }
    if (a == m) {
        g_alt *= a;
    }
    /*
    if (a == 1 && m != 1) {
        bad.push_back(m);
    }
    if (a != 1 && m != 1) {
        assert(a==m);
        g_alt *= a;
    }
    */
    assert(g == g_alt);

    ll mx = (ai+mi-1)/g;
    ll sumx = (ai-1)/g;
    //cerr << "MX = " << mx << " :: " << a+m-1 << "/" << g << endl;
    ll amt = 0;
    for (int i=0; i<bad.size(); ++i) {
        //cerr << "BAD " << bad[i] << endl;
    }
    ll sub = 0;
    
    for (int i=0; i<(1<<bad.size()); ++i) {
        ll pro = 1;
        for (int j=0; j<bad.size(); ++j) {
            if ((i>>j)&1) {
                pro *= bad[j];
            }
        }

        ll cur = mx/pro;
        ll su = sumx/pro;
        if (__builtin_popcount(i)%2) {
            cur *= -1;
            su *= -1;
        }
        //cerr << "   ADD " << cur << " (REM " << su << ")" << endl;
        amt += cur;
        sub += su;
    }

    cout << amt-sub << "\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}