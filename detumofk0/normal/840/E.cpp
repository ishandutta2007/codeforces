
#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int M = 515;

struct Trie{
  int cnt;
  int value[M];
  bool is_contained[M];

  void ins(int x, int y) {
    int cur = 0;
    for(int i = 7; i >= 0; --i) {
      int b = (x >> i) & 1;
      int new_cur = (cur << 1) + b + 1;
      cur = new_cur;
      is_contained[cur] = 1;
    }
    value[cur] = max(value[cur], y);
  }

  int get(int x) {
    int cur = 0, ans = 0;
    for(int i = 7; i >= 0; --i) {
      int b = (x >> i) & 1;
      if(is_contained[(cur << 1) + 2 - b]) {
        ans += (1 << i);
        cur = (cur << 1) + 2 - b;
      }
      else {
        cur = (cur << 1) + 1 + b;
      }
    }
    return (ans << 8) + value[cur];
  }
}root[N][1];

int n, q;
int a[N];
int risan[N][256];
vector < int > g[N];

int par[N];
int height[N];
int jump[N][20];

void dfs_prep(int v, int p){

  jump[v][0] = p;
  for(int i = 1; i < 9; ++i) {
    jump[v][i] = jump[jump[v][i - 1]][i - 1];
  }

  height[v] = height[p] + 1;
  if(height[v] >= 256) {
    int x = v;
    for(int i = 0; i < 256; ++i) {
      int fr = (a[x] >> 8);
      int md = (a[x] & 255);
      root[v][0].ins(fr, md ^ i);
      x = jump[x][0];
    }
    for(int i = 0; i < 256; ++i) {
      risan[v][i] = root[v][0].get(i);
    }
  }

  for(int s : g[v]) {
    if(s == p) continue;
    dfs_prep(s, v);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  if(fopen("1.inp", "r")) freopen("1.inp", "r", stdin);

  cin >> n >> q;

 // fo << n << " " << q << "\n";

  for(int i = 1; i <= n; ++i) {

    cin >> a[i];
  //  fo << a[i] << " ";
  }
 // fo << "\n";

  for(int i = 2; i <= n; ++i) {
    int u, v; cin >> u >> v;
   // fo << u << " " << v << "\n";
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs_prep(1, 0);

  while(q--) {
    int u, v; cin >> u >> v;
  /*  u = 49767; v = 4045;
    u_ = u;
    v_ = v;
    //u_ = u = 1LL * rand() * rand() % (5000) + 1;
    //v_ = v = n - 1LL * rand() * rand() % (500) - 1;
    /*if(rand() % 2) {
      swap(u, v);
      swap(u_, v_);
    }*/

    //fo << u << " " << v << "\n";
    int p = u;
    int hv = height[v];

    int ans = 0;

    for(int fr = 0; fr < 256; ++fr) {
      if(height[v] - height[p] + 1 < 256) break;
      ans = max(ans, risan[v][fr]);
      v = jump[v][8];
    }

    while(height[v] >= height[p]) {
      int dst = hv - height[v];
      ans = max(ans, a[v] ^ dst);
      v = jump[v][0];
    }


/*    int brute = 0;
    int x = u_;
    while(x != jump[p][0]) {
      brute = max(brute, (height[x] + hv - 2 * height[p]) ^ a[x]);
      x = jump[x][0];
    }
    int y = v_;
    while(y != jump[p][0]) {
      brute = max(brute, (hv - height[y]) ^ a[y]);
      y = jump[y][0];
    }*/

    cout << ans << "\n";
  }

  return 0;
}