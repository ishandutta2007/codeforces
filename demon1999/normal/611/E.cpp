#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <cassert>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second

typedef long long ll;
typedef long double ld;
using namespace std;

struct T { ll m1, m2; };
T t = {1, 2};

const int ma = 2 * 131072;
ll n, m, a, b, c, k;
set<pair<int, int> > p;
string s;
int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //freopen("qqq.in", "r",  stdin);
    cin >> n >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    forn (i, n) {
        cin >> m;
        p.insert(mp(m, i));
    }
    ll ans = 0;
    while (!p.empty()) {
        /*for (auto it = p.begin(); it != p.end(); it++)
            cout << it -> fi << " ";
        cout << endl;*/
        if (p.rbegin() -> fi > a + b + c) {
            cout << -1;
            re 0;
        }
        if (c >= p.rbegin() -> fi) break;
        ans++;
        if (a + b >= p.rbegin() -> fi) {
            //cout << "HEHE" << endl;
            p.erase(*p.rbegin());
            p.insert(mp(c, n + 1));
            auto it = p.find(mp(c, n + 1));
            if (it != p.begin()) {
                it--;
                p.erase(it);
            }
            p.erase(mp(c, n + 1));
            continue;
        }
        if (a + c >= p.rbegin() -> fi) {
            p.erase(*p.rbegin());
            p.insert(mp(b, n + 1));
            auto it = p.find(mp(b, n + 1));
            if (it != p.begin()) {
                it--;
                p.erase(it);
            }
            p.erase(mp(b, n + 1));
            continue;
        }
        if (b + c >= p.rbegin() -> fi) {
            p.erase(*p.rbegin());
            p.insert(mp(a, n + 1));
            auto it = p.find(mp(a, n + 1));
            if (it != p.begin()) {
                it--;
                p.erase(it);
            }
            p.erase(mp(a, n + 1));
            continue;
        }
        p.erase(*p.rbegin());
    }
    vector<int> a1;
    int na = -1, nb = -1, nc = -1, nab = -1;
    for (auto it = p.begin(); it != p.end(); it++) {
        a1.push_back(it -> fi);
    }
    forn (i, sz(a1)) {
        //cout << a1[i] << endl;
        if (a1[i] <= a) na = i;
        if (a1[i] <= b) nb = i;
        if (a1[i] <= c) nc = i;
        if (a1[i] <= a + b) nab = i;
    }
    if (nab == -1 || sz(a1) == 0) {
        cout << ans + sz(a1);
        re 0;
    }
    //cout << endl << ans << endl;
    int fc = sz(a1);
    for (int q = 0; q < sz(a1); q++) {
        int n1 = min(q, na + 1);
        n1 = min(n1 + q, nb + 1);
        int qq = 1000000000;
        if (nab < n1) qq = nc - n1 + 1;
        else {
            qq = max(nc - nab, (nc - n1 + 1) / 2 + (nc - n1 + 1) % 2);
        }
        //cout << q << " " << n1 << " " << qq << endl;
        fc = min(fc, q + max(0, qq));
        nc--;
    }
    cout << ans + fc;
    return 0;
}