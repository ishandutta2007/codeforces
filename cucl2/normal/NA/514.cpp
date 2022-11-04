/*
_/      _/  _/_/_/_/_/ _/    _/
_/      _/      _/      _/  _/
_/      _/      _/       _/_/
_/  _/  _/      _/        _/
_/ _/_/ _/      _/        _/
_/_/  _/_/  _/  _/        _/
_/      _/    _/_/        _/

_/_/_/_/_/  _/    _/  _/_/_/_/
        _/   _/  _/   _/      _/
      _/      _/_/    _/      _/
    _/         _/     _/_/_/_/
  _/           _/     _/      _/
_/             _/     _/      _/
_/_/_/_/_/     _/     _/_/_/_/ 
 
_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
 
_/_/_/_/_/ _/_/_/_/_/ _/_/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/         _/     _/_/_/_/
    _/         _/     _/
    _/         _/     _/
    _/     _/_/_/_/_/ _/_/_/_/_/
*/
#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const ll jt = 10000000000000ll;
void inline add(ll &a, ll b) { a += b - jt; a += (a >> 63) & jt; }
void inline sub(ll &a, ll b) { a -= b; a += (a >> 63) & jt; }
ll inline Add(ll a, ll b) { return a + b >= jt ? a + b - jt : a + b; }
ll inline Sub(ll a, ll b) { return a - b < 0 ? a - b + jt : a - b; }
ll inline Mul(ll a, ll b) {
    ll res = 0;
    while (b) {
        if (b & 1) add(res, a);
        add(a, a); b >>= 1;
    }
    return res;
}
void inline mul(ll &a, ll b) { a = Mul(a, b); }

struct Matrix {
    ll t[2][2];
    Matrix(int x = 0) { t[0][0] = t[1][1] = x; t[0][1] = t[1][0] = 0; }
    friend Matrix inline operator * (const Matrix &a, const Matrix &b) {
        static Matrix res; res = Matrix();
        loop(i, 2) loop(j, 2) loop(k, 2) add(res.t[i][j], Mul(a.t[i][k], b.t[k][j]));
        return res;
    }
} tr;

Matrix ksmii(Matrix a, ll b) {
    Matrix res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a; b >>= 1;
    }
    return res;
}

const int mxs = 150002;
ll bls = 150000;
ll x;
ll be[mxs + 5];

int main() {
    tr.t[0][0] = 1;
    tr.t[0][1] = 1;
    tr.t[1][0] = 1;
    tr = ksmii(tr, bls);
    cin >> x;
    be[0] = 0; be[1] = 1;
    circ(i, 2, mxs) be[i] = Add(be[i - 1], be[i - 2]);
    ll ans;
    ll hjt = 100000;
    vector<pair<ll, pair<ll, ll> > > pos;
    loop(i, mxs) if (be[i] % hjt == x % hjt) pos.emb(i, mak(be[i], be[i + 1]));
    circ(bi, 6, 13) {
        vector<pair<ll, pair<ll, ll> > > npos;
        hjt *= 10;
        parse(it, pos) {
            ll cur = it.second.first, nxt = it.second.second;
            ll id = it.first;
            loop(g, 10) {
                if (cur % hjt == x % hjt) npos.emb(id, mak(cur, nxt));
                tie(nxt, cur) = mak(Add(Mul(nxt, tr.t[0][0]), Mul(cur, tr.t[0][1])), Add(Mul(nxt, tr.t[1][0]), Mul(cur, tr.t[1][1])));
                id += bls;
            }
        }
        bls *= 10;
        tr = ksmii(tr, 10);
        pos.swap(npos);
    }
    sort(all(pos));
    if (!SZ(pos)) ans = -1;
    else ans = pos[0].first;
    cout << ans << endl;
    return 0;
}