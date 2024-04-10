#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 

bool home = true;
using namespace std;

const int K = 20;
const int N = (int)2e5 + 7;
int n;
int parrent[N];
int type[N];

int dep[N];

int first[2 * N];
int last[2 * N];
int lg[2 * N];
int top;
int len[N];

vector<int> g[N];

pair<int, int> rmq[K][2 * N];

void dfs(int a) {
  rmq[0][++top] = { dep[a], a };
  first[a] = last[a] = top;

  for (auto& b : g[a]) {
    dep[b] = 1 + dep[a];
    len[b] = 1 + len[a] * (type[b] == type[a]);

    dfs(b);
    rmq[0][++top] = { dep[a], a };

    last[a] = top;
  }
}

int getlca(int a, int b) {
  if (first[a] > last[b]) {
    swap(a, b);
  }
  a = first[a];
  b = last[b];
  assert(a <= b);
  int k = lg[b - a + 1];
  return min(rmq[k][a], rmq[k][b - (1 << k) + 1]).second;
}

bool oksmart(int a, int k, int value, bool wa) {
  if (k == 0) return wa;
  if (type[a] != value) return 0;
  return len[a] >= k;
}

bool ok(int a, int k, int value, bool wa) {

  return oksmart(a, k, value, wa);
}

signed main() {

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    FILE* stream;
    freopen_s(&stream, "iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> parrent[i] >> type[i];
    if (parrent[i] == -1) {
      parrent[i] = 0;
    }
    g[parrent[i]].push_back(i);
  }

  dfs(0);
  for (int i = 2; i <= top; i++) {
    lg[i] = 1 + lg[i / 2];
  }

  for (int k = 1; (1 << k) <= top; k++) {
    for (int i = 1; i + (1 << k) - 1 <= top; i++) {
      rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    }
  }


  int q;
  cin >> q;
  for (int iq = 1; iq <= q; iq++) {
    int tp, a, b;
    cin >> tp >> a >> b;
    if (tp == 1) {
      int c = getlca(a, b);
      if (c != a) {
        cout << "NO\n";
        continue;
      }


      if (ok(b, dep[b] - dep[c], 0, 0)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
    else {
      int c = getlca(a, b);
      if (ok(b, dep[b] - dep[c], 1, 0) && ok(a, dep[a] - dep[c], 0, 1)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }

}