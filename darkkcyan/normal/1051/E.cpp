#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

#define maxn 1000011
#define rem1 ((llong)1e9+7)
#define rem2 ((unsigned llong)ULLONG_MAX)
#define rem ((llong)998244353)
#define ll pair<llong, unsigned llong>

inline ll operator+(ll u, const ll& v) {
  u.xx += v.xx;
  u.yy += v.yy;
  if (u.xx >= rem1) u.xx -= rem1;
  return u;
}

inline ll operator-(ll u, const ll& v) {
  u.xx -= v.xx;
  u.yy -= v.yy;
  if (u.xx < 0) u.xx += rem1;
  return u;
}

inline ll operator*(ll u, const ll& v) {
  (u.xx *= v.xx) %= rem1;
  u.yy *= v.yy;
  return u;
}

inline ll operator*(ll u, llong num) {
  (u.xx *= num % rem1) %= rem1;
  u.yy *= num;
  return u;
}

ll p11[maxn];
void genp11() {
  p11[0] = {1, 1};
  rep1(i, maxn - 1) p11[i] = p11[i - 1] * (llong)11;
}

vector<ll> calhash(const string& s) {
  vector<ll> ans(len(s));
  rep(i, len(s)) {
    ans[i] = (i ? ans[i - 1] : ll()) * p11[1] + ll(s[i] - '0' + 1, s[i] - '0' + 1);
  }
  return ans;
}

inline
ll geths(const vector<ll>& u, int l, int r) {
  if (l == 0) return u[r];
  else return u[r] - u[l - 1] * p11[r - l + 1];
}

bool cmp(const vector<ll>& a, int la, int ra, const vector<ll>& b, int lb, int rb) {
  int na = ra - la + 1;
  //int nb = rb - lb + 1;
  //if (na < nb) return true;
  //if (na > nb) return false;
  int l = 0, r = na;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (geths(a, la, la + mid) != geths(b, lb, lb + mid)) r = mid;
    else l = mid + 1;
  }
  if (l >= na) return false;
  //clog << geths(a, la + l, la + l).xx << ' ' << geths(b, lb + l, lb + l).xx << endl;
  return geths(a, la + l, la + l) < geths(b, lb + l, lb + l);
}

string a, b, c;
vector<ll> ha, hb, hc;

llong dp[maxn] = {0};
llong getsum(int l, int r) {
  ++l, ++r;
  if (r < 0) return 0;
  l = max(l, 0);
  llong ans = dp[r] - dp[l - 1];
  ans %= rem;
  if (ans < 0) ans += rem;
  return ans;
}

int main() {
  genp11();
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> a >> b >> c;
  ha = calhash(a);
  hb = calhash(b);
  hc = calhash(c);
  //for (auto i: ha) clog << i.xx << ':' << i.yy << ' ';
  //clog << endl;
  //for (auto i: hb) clog << i.xx << ':' << i.yy << ' ';
  //clog << endl;
  //for (auto i: hc) clog << i.xx << ':' << i.yy << ' ';
  //clog << endl;
  
  dp[0] = 1;
  llong preans = 0;
  rep(i, len(a)) {
    llong& curans = dp[i + 1];
    int r = i - len(b) + 1, l = i - len(c) + 1;
    //clog << i << ' ' << l << ' ' << r << endl;
    if (l <= r - 2) {
      (curans += getsum(l, r - 2)) %= rem;
    }
    bool addr = 0, addl = 0;
    if (r >= 0) if (!cmp(ha, r, i, hb, 0, len(hb) - 1)) {
      if (a[r] != '0' || i == r) 
        addr = 1;
      //clog << "Add right" << endl;
    }
    if (l >= 0) if (!cmp(hc, 0, len(hc) - 1, ha, l, i)) {
      if (a[l] != '0' || i == l)
        addl = 1;
      //clog << "Add left" << endl;
    }

    if (l == r) {
        if (addr and addl)
          (curans += getsum(l - 1, l - 1)) %= rem;
    } else {
      if (addr) 
        (curans += getsum(r - 1, r - 1)) %= rem;
      if (addl) 
        (curans += getsum(l - 1, l - 1)) %= rem;
    }
    if (a[i] == '0') {
      (dp[i] -= preans) %= rem;
      if (dp[i] < 0) dp[i] += rem;
    }
    preans = curans;
    curans += dp[i];
    //clog << i << ' ' << getsum(i, i) << endl;
  }
  //clog << getsum(-1, -1) << endl;
  cout << getsum(len(a) - 1, len(a) - 1);

  return 0;
}