#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[1<<17];
vector<int> child[1<<17];
int par[1<<17];

pair<int,int> fur;
void dfs(int p, int parent = -1, int d = 0) {
  if (parent == -1) fur = {-1,-1};
  par[p] = parent;
  fur = max(fur, {d,p});
  for (int i : node[p])
    if (i != parent) dfs(i,p,d+1);
}

vector<int> medians() {
  dfs(0);
  dfs(fur.second);
  int p = fur.second;
  for (int i = 0; i < fur.first/2; i++)
    p = par[p];
  if (fur.first%2) return {p,par[p]};
  else return {p};
}

int depth[1<<17];

void order(int p, int par = -1) {
  child[p].clear();
  depth[p] = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    child[p].push_back(i);
    order(i, p);
    depth[p] = max(depth[p], depth[i]+1);
  }
}

bool check(int p, int d) {
  if (d == 1) return child[p].empty();
  if (child[p].size() != 2) return 0;
  for (int i : child[p]) if (!check(i, d-1)) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int m = (1<<n)-2;
  for (int i = 1; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }

  if (n == 2) {
    cout << 2 << endl;
    cout << 1 << ' ' << 2 << endl;
    return 0;
  }

  vector<int> ans;
  auto roots = medians();
  for (int root : roots) {
    order(root);

    int parent = -1;

    map<int,vector<int>> bydeg;
    for (int i = 0; i < m; i++) {
      bydeg[node[i].size()].push_back(i);
    }

    if (bydeg[2].size() == 2) {
      // Removed leaf
      parent = bydeg[2][0] ^ bydeg[2][1] ^ root;
      if (parent == bydeg[2][0] || parent == bydeg[2][1])
	child[parent].push_back(m);
      else continue;
    } else {
      // Removed inner node
      for (int i = 0; i < m; i++) {
	if (child[i].size() == 3) {
	  parent = i;
	  break;
	}
      }
      if (parent == -1) continue;

      int maxdepth = -1, good = -1;
      for (int i : child[parent]) {
	if (depth[i] > maxdepth) {
	  maxdepth = depth[i];
	  good = i;
	}
      }
      if (good == -1) continue;

      vector<int> grandchild;
      for (int i : child[parent])
	if (i != good)
	  grandchild.push_back(i);

      child[m] = grandchild;
      child[parent] = {good, m};
    }

    if (check(root, n)) {
      ans.push_back(parent);
    }
  }
  //assert(ans.size());
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i : ans)
    cout << i+1 << ' ';
  cout << endl;
}