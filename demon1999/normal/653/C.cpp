#include <bits/stdc++.h>
#define forn(i, n) for(ll i = 0; i < int(n); i++)
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

struct T { int x, y; };
T t = {1, 2};
const int ma = 2 * 131072;

int n, ans;
vector<ll> a;
map<pair<int, int>, int> kk;
bool ok1(int nu) {
    if (nu % 2 == 0) {
        if (nu && a[nu - 1] <= a[nu]) re false;
        if (nu + 1 < n && a[nu + 1] <= a[nu]) re false;
    }
    if (nu % 2) {
        if (nu && a[nu - 1] >= a[nu]) re false;
        if (nu + 1 < n && a[nu + 1] >= a[nu]) re false;
    }
    re true;
}

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen("qqq.in", "r",  stdin));
    cin >> n;
    a.resize(n);
    forn (i, n) cin >> a[i];
    vector<int> nu, nu2;
    for (int i = 1; i < n; i += 2) {
        if (a[i] <= a[i - 1] || (i + 1 < n && a[i] <= a[i + 1])) nu.push_back(i);
    }
    for (int i = 0; i < n; i+= 2) {
        if ((i && a[i] >= a[i - 1]) || (i + 1 < n && a[i] >= a[i + 1])) nu2.push_back(i);
    }
    if (sz(nu) > 8 || sz(nu2) > 8) {
        cout << 0;
        re 0;
    }
    int k = nu[0];
    //cout << k << endl;
    bool ok ;
    for (int i = k - 1; i < min(k + 2, n); i++) {
        for (int j = 0; j < n; j++) {
                if (i == j) continue;
            swap(a[i], a[j]);
            ok= true;
            forn (i, sz(nu)) {
                if (!ok1(nu[i])) ok = false;
            }
            forn (i, sz(nu2)) {
                if (!ok1(nu2[i])) ok = false;
            }
            if (!ok1(i) || !ok1(j)) ok = false;
            if (ok) {
                if (!kk[mp(i, j)]) ans++;
                kk[mp(i, j)] = kk[mp(j, i)] = 1;
            }
            swap(a[i], a[j]);
        }
    }
    cout << ans;
    return 0;
}