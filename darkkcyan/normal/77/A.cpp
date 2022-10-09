#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

vector<string> names = {
  "Anka",
  "Chapay",
  "Cleo",
  "Troll",
  "Dracul",
  "Snowy",
  "Hexadecimal",
};

map<string, int> nid;

vector<int> gr[7];
llong a[3];

int cntlike(set<int> group) {
  int ans = 0;
  for (auto u: group) {
    for (auto v: gr[u]) ans += group.count(v);
  }
  return ans;
}

int p[7] = {0};
bool incp() {
  int i;
  for (i = 0; i < 7; ++i)
    if (p[i] != 2) break;
  if (i == 7) return false;
  ++p[i];
  for (; i--; ) p[i] = 0;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  rep(i, len(names)) nid[names[i]] = i;
  int n; cin >> n;
  rep(i, n) {
    string u, v, t; cin >> u >> t >> v;
    gr[nid[u]].push_back(nid[v]);
  }
  rep(i, 3) cin >> a[i];
  pair<llong, int> ans(-LLONG_MAX, 0);
  do {
    set<int> t[3];
    rep(i, 7) t[p[i]].insert(i);
    bool has0 = false;
    llong ep[3];
    int sl = 0;
    rep(i, 3) {
      if (len(t[i]) == 0) {
        has0 = true;
        break;
      }
      ep[i] = a[i] / len(t[i]);
      sl += cntlike(t[i]);
    }
    if (has0) continue;
    sort(ep, ep + 3);
    ans = max(ans, {ep[0] - ep[2], sl});
  } while (incp());
  cout << -ans.xx << ' ' << ans.yy;
  
  return 0;
}