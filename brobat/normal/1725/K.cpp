#include <bits/stdc++.h>
using namespace std;

// DSU
struct node {
  int p,s, h;
};
vector<node> nodes;

int make_node(int h) {
  nodes.push_back({(int)nodes.size(), 1, h});
  return (int)nodes.size()-1;
}

int find(int v) {
  if (nodes[v].p == v) return v;
  return nodes[v].p = find(nodes[v].p);
}

bool merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return false;
  nodes[b].p = a;
  nodes[a].s += nodes[b].s;
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n);
  set<int> available; // available states
  map<int,int> state_map; // maps state to index
  vector<int> curr_state(n, -1); // current state of building

  auto create_or_get = [&](int h) {
    if (available.count(h) == 0) {
      available.insert(h);
      state_map[h] = make_node(h);
    }
    return state_map[h];
  };
  for (int i =0; i < n; i++) {
    cin >> a[i];
    curr_state[i] = create_or_get(a[i]);
  }

  int q;
  cin >> q;
  while(q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k,w;
      cin >> k >> w;
      k--;
      curr_state[k] = create_or_get(w);
    } else if (t==2) {
      int k;
      cin >> k;
      k--;
      cout << nodes[find(curr_state[k])].h << '\n';
    } else if (t==3) {
      int l,r;
      cin >> l >> r;
      int lim = (l+r)/2;

      // make everything small
      int goal = create_or_get(l-1);
      auto it = available.lower_bound(l);
      while(it != available.end() && *it <= lim) {
        merge(goal, state_map[*it]);
        state_map.erase(*it);
        it = available.erase(it);
      }

      // make everything big
      goal = create_or_get(r+1);
      it = available.lower_bound(lim+1);
      while(it != available.end() && *it <= r) {
        merge(goal, state_map[*it]);
        state_map.erase(*it);
        it = available.erase(it);
      }
    } else assert(false);
  }
}