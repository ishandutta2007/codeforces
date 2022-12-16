#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll sgn(ll x) {
  return (x == 0 ? 0 : (x < 0 ? -1 : 1));
}

struct Pt {
  ll x, y;
  ld dist() const {
    return sqrt(x*x + y*y);
  }
  bool operator== (const Pt& o) const {
    return x == o.x && y == o.y;
  }
  bool operator< (const Pt& o) const {
    return (x == o.x ? y < o.y : x < o.x);
  }
  Pt operator- (const Pt& o) const {
    return {x - o.x, y-o.y};
  }
  pair<ll,ll> slope() const {
    ll g = __gcd(x, y);
    ll a = x/g, b = y/g;
    if (a == 0 && b < 0) {
      b *= -1;
    }
    if (b == 0 && a < 0) {
      a *= -1;
    }
    if (a < 0) {
      a *= -1;
      b *= -1;
    }
    return {a, b};
  }
};

ld solve(const vector<Pt>& vec) {
  ld ans = 0.;
  for (int i=0; i+1<vec.size(); ++i) {
    ans += (vec[i+1] - vec[i]).dist();
  }
  return ans;
}

bool is_parallel(const Pt& a, const Pt& b) {
  return a.slope() == b.slope();
}

const int N = 200200;
Pt p[N];
int n, k;
int offx;

int find_offx() {
  vector<bool> is_line_fwd(n+1), is_line_bck(n+1);
  is_line_fwd[1] = is_line_fwd[2] = true;
  is_line_bck[n] = is_line_bck[n-1] = true;
  for (int i=3; i<=n; ++i) {
    is_line_fwd[i] = is_line_fwd[i-1];
    if (!is_parallel(p[i]-p[i-1], p[i-1]-p[i-2])) {
      is_line_fwd[i] = false;
    }
  }

  for (int i=n-2; i>=1; --i) {
    is_line_bck[i] = is_line_bck[i+1];
    if (!is_parallel(p[i]-p[i+1], p[i+1]-p[i+2])) {
      is_line_bck[i] = false;
    }
  }

  if (is_line_fwd[n]) {
    return -1;
  }
  if (is_line_fwd[n-1]) {
    //////cerr << " OFFX " << n << endl;
    return n;
  }
  if (is_line_bck[2]) {
    return 1;
  }
  int ans = 0;
  for (int i=2; i<n; ++i) {
    Pt oth = (i == 2 ? p[i+1]-p[i+2] : p[1]-p[2]);
    if (is_line_fwd[i-1] && is_line_bck[i+1] && is_parallel(p[i-1]-p[i+1], oth)) {
      //////cerr << " OFF LINE " << i << endl;
      ans = i;
    }
  }

  return ans;
}

ld checker(const Pt& s, const vector<Pt>& l, const Pt& q, const vector<Pt>& r) {
  vector<int> idxl(l.size());
  vector<int> idxr(r.size());
  for (int i=0; i<l.size(); ++i) {
    idxl[i] = i;
  }
  for (int i=0; i<r.size(); ++i) {
    idxr[i] = i;
  }
  vector<Pt> cur(2+l.size()+r.size());
  ld ans = 1e50;
  do {
    cur[0] = s;
    cur[1+l.size()] = q;
    for (int i=0; i<l.size(); ++i) {
      cur[i+1] = l[idxl[i]];
    }
    do {
      for (int i=0; i<r.size(); ++i) {
        cur[i+2+l.size()] = r[idxr[i]];
      }
      ld cv = solve(cur);
      if (cv < ans) {
        //cerr << " " << cv << ":";
        //cerr; for (auto& z : cur) {
          //cerr << " " << z.x << "," << z.y;
        //cerr; }
        //cerr << endl;
        ans = cv;
      }
    } while (next_permutation(idxr.begin(), idxr.end()));
  } while (next_permutation(idxl.begin(), idxl.end()));
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int _n, _k;
  cin >> _n >> _k;
  map<Pt, int> st;
  int idx = 0;
  for (int i=1; i<=_n; ++i) {
    int x, y;
    cin >> x >> y;
    if (!st.count({x, y})) {
      st[{x, y}] = i;
      p[++idx] = {x, y};
    }
    if (_k == i) {
      k = st[{x, y}];
    }
  }
  n = idx;
  cout << fixed << setprecision(10);
  if (n == 1) {
    cout << 0.0 << endl;
    return 0;
  } else if (n == 2) {
    cout << (p[1]-p[2]).dist() << endl;
    return 0;
  } else if (n == 3) {
    cout << (p[1]-p[2]).dist() + (p[2]-p[3]).dist() + (p[3]-p[1]).dist() << endl;
    return 0;
  }

  offx = find_offx();

  map<Pt, int> mp;
  for (int i=1; i<=n; ++i) {
    if (i == offx) {
      continue;
    }
    mp[p[i]] = i;
  }
  vector<Pt> ordered;
  for (auto& q : mp) {
    ordered.push_back(q.first);
    /*
    if (q.first == p[k]) {
      w = ordered.size();
    }
    */
  }
  //cerr << " OFFX " << offx << endl;

  if (offx == -1 || p[k] == p[offx]) {
    //cerr << "IN A LINE" << endl;
    ld ans = 1e50;
    ans = min(ans, solve({p[k], mp.begin()->first, mp.rbegin()->first}));
    ans = min(ans, solve({p[k], mp.rbegin()->first, mp.begin()->first}));
    cout << ans << endl;
    return 0;
  }

  ld ans = 1e50;

  ans = min(ans, checker(p[k], {}, p[offx], {ordered[0], ordered.back()}));
  ans = min(ans, checker(p[k], {ordered[0], ordered.back()}, p[offx], {}));
  for (int i=0; i+1<ordered.size(); ++i) {
    vector<Pt> l = {ordered[0], ordered[i]}, r = {ordered[i+1], ordered.back()};
    ans = min(ans, checker(p[k], l, p[offx], r));
    ans = min(ans, checker(p[k], r, p[offx], l));
  }


  cout << ans << "\n";

  return 0;
}