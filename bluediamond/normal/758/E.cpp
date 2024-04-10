#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, ix[N], iy[N], iw[N], ip[N], kek[N];

struct Edge {
  int w;
  int p;
  int to;
  int ind;
  int take;
  int wfrom;
};

vector<Edge> g[N];
int totaltaken;
vector<Edge> edges;

int build(int a, int p = -1) {
  int sumw = 0;
  vector<Edge> newKids;
  for (auto &it : g[a]) {
    if (it.to == p) continue;

    int wfrom = build(it.to, a);
    if (it.p < wfrom) {
      cout << "-1\n";
      exit(0);
    }

    it.take = min(it.w - 1, it.p - wfrom);
    it.p -= it.take;
    it.w -= it.take;

    sumw += wfrom + it.w;

    it.wfrom = wfrom;
    newKids.push_back(it);
  }
  g[a] = newKids;
  return sumw;
}

int tg[N];

int dfs(int a, int limit) {
  int sumw = 0;
  tg[a] = 0;
  for (auto &it : g[a]) {

    int wfrom = it.wfrom;
    int maxgrow = it.take;



    int grow = maxgrow;
    grow = min(grow, limit);
  ///  cout << a << " : " << grow << " : " << maxgrow << " vs " << it.p - wfrom << "\n";
   /// cout << a << " -> " << it.to << " and " << it.p << " " << it.w << " and " << it.take << ", " << grow << "\n";

    tg[a] += grow;

    it.p += grow;
    it.w += grow;
    limit -= grow;
    assert(limit >= 0);

//    it.p += grow;

    assert(it.p >= wfrom);
   // assert(wfrom == dfs(it.to, limit));

    int nw = dfs(it.to, min(limit, it.p - wfrom));
    //cout << " la " << a << " : " << grow << "\n";
    limit -= tg[it.to];
    tg[a] += tg[it.to];


    if (it.p < nw) {
      cout << " bad : " << a << " vs " << it.to << " lol " << it.p << " si " << nw << "\n";
      cout << tg[it.to] << " vs " << min(limit, it.p - wfrom) << "\n";
      exit(0);
    }

  ///  assert(tg[it.to] <= min(limit, it.p - wfrom));
    assert(it.p >= nw);

    kek[it.ind] = it.take - grow;
    ///totaltaken += it.take - grow;

    sumw += nw + it.w;
  }
  return sumw;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, w, p;
    cin >> x >> y >> w >> p;
    ix[i] = x;
    iy[i] = y;
    iw[i] = w;
    ip[i] = p;
    g[x].push_back({w, p, y, i, 0, 0});
    g[y].push_back({w, p, x, i, 0, 0});
  }

  build(1);
  dfs(1, (int) 1e18);
  cout << n << "\n";
  for (int i = 1; i < n; i++) {
    cout << ix[i] << " " << iy[i] << " " << iw[i] - kek[i] << " " << ip[i] - kek[i] << "\n";
  }
//  cout << totaltaken << "\n";

  return 0;
}