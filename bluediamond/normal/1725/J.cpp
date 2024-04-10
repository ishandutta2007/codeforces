#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const ll INF = (ll) 1e18 + 7;
int n, par[N], edge_par_len[N];
vector<pair<int, int>> gw[N];
vector<int> g[N];

ll max_leg_down[N];
vector<ll> legs_down[N];
ll max_leg_up[N];

ll max_path_down[N];
ll max_path_up[N];

void build_tree(int a, int p = 0) {
  for (auto &it : gw[a]) {
    int b = it.first, len = it.second;
    if (b == p) continue;
    build_tree(b, a);
    par[b] = a;
    edge_par_len[b] = len;
    g[a].push_back(b);
  }
}

void build2(int a) {
  legs_down[a] = {0, 0, 0, 0};

  for (auto &b : g[a]) {
    build2(b);
    assert(par[b] == a);
    legs_down[a].push_back(max_leg_down[b] + edge_par_len[b]);
    max_path_down[a] = max(max_path_down[a], max_path_down[b]);
  }

  sort(legs_down[a].rbegin(), legs_down[a].rend());
  max_leg_down[a] = legs_down[a][0];
  max_path_down[a] = max(max_path_down[a], legs_down[a][0] + legs_down[a][1]);

  max_path_down[a] = max(max_path_down[a], max_leg_down[a]);
}

void build3(int a) {
  for (int iter = 1; iter <= 2; iter++) {
    reverse(g[a].begin(), g[a].end());

    ll mx = -INF, mx2 = -INF, mx3 = -INF;

    for (auto &b : g[a]) { /// optimize this !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      max_leg_up[b] = max(max_leg_up[b], mx + edge_par_len[b]);
      mx = max(mx, max_leg_down[b] + edge_par_len[b]);
    }


    for (auto &b : g[a]) { /// optimize this !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      max_path_up[b] = max(max_path_up[b], mx2);
      max_path_up[b] = max(max_path_up[b], mx3);
      mx2 = max(mx2, max_path_down[b]);
      mx3 = max(mx3, max_leg_up[a] + edge_par_len[b] + max_leg_down[b]);
    }

    if ((int) g[a].size() >= 3) {
      multiset<ll> gs;
      for (auto &b : g[a]) {
        gs.insert(-(max_leg_down[b] + edge_par_len[b]));
      }
      for (auto &b : g[a]) { /// optimize this !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        gs.erase(gs.find(-(max_leg_down[b] + edge_par_len[b])));
        ll x = *gs.begin();
        gs.erase(gs.find(x));
        max_path_up[b] = max(max_path_up[b], -(*gs.begin() + x));
        gs.insert(x);
        gs.insert(-(max_leg_down[b] + edge_par_len[b]));
      }
    }




  }

  for (auto &b : g[a]) {
    assert(par[b] == a);
    max_leg_up[b] = max(max_leg_up[b], max_leg_up[a] + edge_par_len[b]);
    max_path_up[b] = max(max_path_up[b], max_leg_up[a]);
    max_path_up[b] = max(max_path_up[b], max_path_up[a]);
    build3(b);
  }


}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  ll sum_edges = 0;
  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    sum_edges += c;
    gw[a].push_back({b, c});
    gw[b].push_back({a, c});
  }

  build_tree(1);
  build2(1);
  build3(1);

  if (0) {
    for (int i = 1; i <= n; i++) {
      cout << i << " : " << max_leg_down[i] << " and " << max_leg_up[i] << " <<<AND>>> " << max_path_down[i] << " and " << max_path_up[i] << "\n";
    }
    exit(0);
  }

  ll print_ret = 0;

  { /// common vertex case
    for (int i = 1; i <= n; i++) {
      vector<ll> legs = legs_down[i];
      legs.push_back(max_leg_up[i]);
      sort(legs.rbegin(), legs.rend());
      assert((int) legs.size() >= 4);
      print_ret = max(print_ret, legs[0] + legs[1] + legs[2] + legs[3]);
    }
  }
  {
    /// no common vertex case
    for (int a = 1; a <= n; a++) {
      for (auto &b : g[a]) {
        /// edge a, b is completely deleted from the face of the Universe
        print_ret = max(print_ret, 2 * edge_par_len[b] + max_path_down[b] + max_path_up[b]);
      }
    }
  }

  cout << 2 * sum_edges - print_ret << "\n";
  return 0;
}