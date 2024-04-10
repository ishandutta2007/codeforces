#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
vector<int> in[N];
int ocount[N];
int n, m, q;
ll sum = 0;

void add_edge(int u, int v) {
  //cerr << "ADD " << u << " -> " << v << " : ADD " << in[u].size() << " + " << out[v].size() << endl;
  sum += in[u].size() + ocount[v];
  in[v].push_back(u);
  ++ocount[u];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=1; i<=m; ++i) {
    int u, v;
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    add_edge(v, u);
  }
  cout << sum << "\n";
  cin >> q;
  vector<int> st;
  for (int qq=1; qq<=q; ++qq) {
    int v;
    cin >> v;
    while (in[v].size()) {
      int u = in[v].back(); in[v].pop_back();
      sum -= in[u].size() + ocount[v];
      --ocount[u];
      add_edge(v, u);
    }
    cout << sum << "\n";
    assert(in[v].size() == 0);
  }
  return 0;
}