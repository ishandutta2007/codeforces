#include <bits/stdc++.h>


using namespace std;

int nax;

struct NodeData {
  /// whatever you want, sir!
  int mn;
  NodeData() : mn(0) {}
};

NodeData operator + (NodeData a, NodeData b) {
  /// complete this please
  a.mn = min(a.mn, b.mn);
  return a;
}


struct Node {
  int left_id;
  int right_id;
  NodeData my_data;
  Node() : left_id(0), right_id(0), my_data() {}
};

vector<Node> nodes = { {} }; /// I may use .reserve();

void createAndGetCopyNode(int node_id) {
  nodes.push_back(nodes[node_id]);
}

void createAndGetEmptyNode() {
  nodes.push_back({});
}

void join(int node_id) {
  /// complete here
  nodes[node_id].my_data = nodes[nodes[node_id].left_id].my_data + nodes[nodes[node_id].right_id].my_data;
}

void build(int node_id, int tl, int tr) {
  if (tl == tr) {
    return;
  }
  int tm = (tl + tr) / 2;
  createAndGetEmptyNode(), nodes[node_id].left_id = (int)nodes.size() - 1;
  createAndGetEmptyNode(), nodes[node_id].right_id = (int)nodes.size() - 1;
  build(nodes[node_id].left_id, tl, tm);
  build(nodes[node_id].right_id, tm + 1, tr);
  join(node_id);
}

int st = 0;

int update(int node_id, int tl, int tr, int p, NodeData value) { /// returns the new root
  createAndGetCopyNode(node_id); int new_node = (int)nodes.size() - 1;
  if (tl == tr) {
    /// change the value of new_node here
    nodes[new_node].my_data.mn = max(nodes[new_node].my_data.mn, value.mn);
    return new_node;
  }
  int tm = (tl + tr) / 2;
  if (p <= tm) {
    nodes[new_node].left_id = update(nodes[new_node].left_id, tl, tm, p, value);
  }
  else {
    nodes[new_node].right_id = update(nodes[new_node].right_id, tm + 1, tr, p, value);
  }
  join(new_node);
  return new_node;
}

NodeData get(int node_id, int tl, int tr, int l, int r) { /// returns the combined NodeData of the interval
  if (l <= tl && tr <= r) {
    return nodes[node_id].my_data;
  }
  int tm = (tl + tr) / 2;
  if (r <= tm) return get(nodes[node_id].left_id, tl, tm, l, r);
  if (l >= tm + 1) return get(nodes[node_id].right_id, tm + 1, tr, l, r);
  return get(nodes[node_id].left_id, tl, tm, l, r) + get(nodes[node_id].right_id, tm + 1, tr, l, r);
}

struct Segment {
  int l, r, id;
};

bool operator < (Segment a, Segment b) {
  return a.r < b.r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q, m;
  cin >> n >> q >> m;
  nodes.reserve((int)4e7);
  nax = n;
  vector<Segment>segments;
  segments.reserve(m);
  for (int i = 0; i < m; i++) {
    int l, r, id;
    cin >> l >> r >> id;
    id--;
    segments.push_back({ l,r,id });
  }
  createAndGetEmptyNode();
  int root = 1;
  build(1, 0, n - 1);
  sort(segments.begin(), segments.end());
  vector<pair<int, int>>guys;
  int l = 0;
  int tt = 0;
  while (l < (int)segments.size()) {
    int r = l;
    while (r + 1 < (int)segments.size() && segments[r + 1].r == segments[r].r)r++;
    /// everything from l to r
    for (int i = l; i <= r; i++) {
      tt++;
      NodeData gg;
      gg.mn = segments[i].l;
      root = update(root, 0, n - 1, segments[i].id, gg);
      st = 0;
    }

    guys.push_back({ segments[l].r,root });
    l = r + 1;
  }
  for (int iq = 1; iq <= q; iq++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    a--;
    b--;
    int pz = -1, l = 0, r = (int)guys.size() - 1;
    while (l <= r) {
      int i = (l + r) / 2;
      if (guys[i].first <= y) {
        pz = i;
        l = i + 1;
      }
      else r = i - 1;
    }
    if (pz == -1) {
      cout << "no" << endl;
      continue;
    }
    int sol = get(guys[pz].second, 0, n - 1, a, b).mn;
    st = 0;

    if (sol < x) {
      cout << "no" << endl;
    }
    else {
      cout << "yes" << endl;
    }

  }
}