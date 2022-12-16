#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct Rat {
  ll num, den;
  Rat() {}
  Rat(ll x) {
    num = x, den = 1;
  }
  Rat(ll a, ll b) {
    ll g = __gcd(a, b);
    num = a/g;
    den = b/g;
    if (den < 0) {
      den *= -1;
      num *= -1;
    }
  }

  Rat operator+ (const Rat& o) const {
    return Rat(num*o.den + den*o.num, o.den*den);
  }
};

struct Pt {
  Rat x, y;
  int idx;
  bool operator< (const Pt& o) const {
    __int128_t s1 = x.num*y.den;
    s1 *= o.x.den*o.y.num;
    __int128_t s2 = o.x.num*o.y.den;
    s2 *= x.den*y.num;
    return s1 < s2;
  }
};

const int N = 200200;
Pt p[N];
int taken[N];
vector<int> edges[N];
vector<pair<int, int>> adj[N*2];

vector<pair<int, int>> ans;
int seen[N*2];

int dfs(int u, int p) {
  if (seen[u]) {
    return 0;
  }
  seen[u] = 1;
  int avail = 0;
  for (auto& [v, e] : adj[u]) {
    if (v == p) continue;
    if (taken[e]) continue;
    int f;
    if (f = dfs(v, u)) {
      ans.push_back({e, f});
      taken[e] = 1;
      taken[f] = 1;
    } else {
      if (avail) {
        ans.push_back({e, avail});
        taken[e] = 1;
        taken[avail] = 1;
        avail = 0;
      } else {
        avail = e;
      }
    }
  }
  return avail;
}


int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<Pt> branch;
  for (int i=1; i<=n; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    p[i].x = Rat(a, b);
    p[i].y = Rat(c, d);
    branch.push_back({p[i].x+1, p[i].y, i});
    branch.push_back({p[i].x, p[i].y+1, i});
  }
  sort(branch.begin(), branch.end());

  int zz = 0;
  for (int i=0; i<branch.size(); ++i) {
    int j=i;
    while (j+1 < branch.size() &&
        !(branch[i] < branch[j+1])) {
      ++j;
    }
    {
      ++zz;
      for (int k=i; k<=j; ++k) {
        edges[branch[k].idx].push_back(zz);
      }
    }
    i = j;
  }

  for (int i=1; i<=n; ++i) {
    adj[edges[i][0]].push_back({edges[i][1], i});
    adj[edges[i][1]].push_back({edges[i][0], i});
  }

  for (int i=1; i<=zz; ++i) {
    dfs(i, 0);
  }
  cout << ans.size() << "\n";
  for (auto& [x, y] : ans) {
    cout << x << " " << y << "\n";
  }

  return 0;
}