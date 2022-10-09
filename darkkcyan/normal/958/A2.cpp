#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define base1 ((llong)1e9+7)
#define base2 ((llong)1e9+8181)
#define ll pair<llong, llong>
#define maxn 2010
ll operator +(ll u, llong v) {
  (u.xx += v) %= base1;
  (u.yy += v) %= base2;
  return u;
}

ll operator+(ll u, const ll& v) {
  (u.xx += v.xx) %= base1;
  (u.yy += v.yy) %= base2;
  return u;
}

ll operator -(ll u, const ll& v) {
  (u.xx += base1 - v.xx) %= base1;
  (u.yy += base2 - v.yy) %= base2;
  return u;
}

ll operator*(ll u, const llong& v) {
  (u.xx *= v) %= base1;
  (u.yy *= v) %= base2;
  return u;
}

ll operator*(ll u, const ll& v) {
  (u.xx *= v.xx) %= base1;
  (u.yy *= v.yy) %= base2;
  return u;
}

void precomphash(string s[], ll ans[maxn][maxn], int n, int m) {
  rep(i, n) {
    ans[i][0] = ll() + ((llong)s[i][0] - 'a' + 1);
    rep1(f, m - 1) ans[i][f] = ans[i][f - 1] * 29 + ((llong)s[i][f] - 'a' + 1);
  }
}

vector<ll> p29(1, ll(1, 1));
ll getp29(int num) {
  while (len(p29) <= num) p29.push_back(p29.back() * 29);
  return p29[num];
}

ll gethash(ll hs[], int l, int r) {
  return hs[r] - (l ? hs[l - 1] : ll()) * getp29(r - l + 1);
}

int n, m;
string s1[maxn], s2[maxn];
ll h1[maxn][maxn], h2[maxn][maxn];
map<ll, int> p1;

ll calhash(ll hs[maxn][maxn], int r, int c) {
  ll ans(0, 0);
  rep(i, m) ans = ans * getp29(m) + gethash(hs[i + r], c, c + m - 1);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  rep(i, n) cin >> s1[i];
  rep(i, m) cin >> s2[i];
  precomphash(s1, h1, n, m);
  precomphash(s2, h2, m, n);
  rep(i, n - m + 1) {
    p1[calhash(h1, i, 0)] = i + 1;
    ll t = calhash(h1, i, 0);
    //clog << i << ' ' << t.xx << ' ' << t.yy << endl;
  }
  rep(i, n - m + 1) {
    ll t = calhash(h2, 0, i);
    if (p1.count(t)) {
      cout << p1[t] << ' ' << i + 1;
      return 0;
    }
  }

  return 0;
}