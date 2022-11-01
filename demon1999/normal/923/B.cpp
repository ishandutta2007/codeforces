#include <bits/stdc++.h>
 
 
using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
typedef unsigned long long ull;
const ll mod = int(1e9) + 7;
const int ma = 1024 * 1024;

ll n;
vector<ll> v;
ll cc;
set<pair<ll, ll> > cq;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    v.resize(n);
    forn (i, n) {
        cin >> v[i];
    }
    forn (i, n) {
        ll t;
        cin >> t;
        cq.insert(mp(cc + v[i], i));
        ll sum = 0;
        while (sz(cq) && (cq.begin()->fi) - cc <= t) {
            sum += (cq.begin()->fi) - cc;
            cq.erase(cq.begin());
        }
        sum += ((ll)sz(cq) * t);
        cc += t;
        cout << sum << " ";
    }
}