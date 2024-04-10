#include <bits/stdc++.h>

using namespace std;

namespace sol {

#define iint long long 
#define ve vector
#define vi ve<int>
#define sz(v) ((int)v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define inf(t) numeric_limits<t>::max()
#define rep(i,n) for(int i = -1; ++i < n; )

int n;
vi a, b, t;

int main() {
    srand(time(0));
    cin >> n;
    a.resize(n);
    b.resize(n);

    iint sa = 0, sb = 0;
    rep(i, n) cin >> a[i], sa += a[i];
    rep(i, n) cin >> b[i], sb += b[i];


    t.resize(n);
    rep(i, n) t[i] = i;
    int cnt = (n / 2) + 1;
    bool found = false;
    int step = 0;
    iint ta = 0, tb = 0;
    clog << sa << ' ' << sb << ' ' << cnt << endl;
    for (step = 0; step < 500; ++step) {
        random_shuffle(t.begin(), t.end());
        ta = tb = 0;
        rep(i, cnt) {
            ta += a[t[i]], tb += b[t[i]];
        }
        if (ta * 2 > sa and tb * 2 > sb) {
            clog << ta << ' ' << tb << endl;
            //rep(i, n) {
                //clog << t[i] + 1 << ' ';
            //}
            //clog << endl;
            found = true;
            break;
        } 
        if (ta * 2 < sa and tb * 2 < sb) {
            clog << "rev" << ta << ' ' << tb << endl;
            //rep(i, n) {
                //clog << t[i] + 1 << ' ';
            //}
            //clog << endl;
            found = true;
            cnt = n - cnt;
            reverse(t.begin(), t.end());
            break;
        }
    }
    clog << step << endl;
    assert(found);

    cout << cnt << '\n';
    rep(i, cnt) {
        cout << t[i] + 1 << ' ';
    }



    return 0;
}}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    return sol::main();
}