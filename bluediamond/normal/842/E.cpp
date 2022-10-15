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
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 


bool home = true;
using namespace std;

const int N = (int)3e5 + 7;
const int K = 20;
int n;
int parrent[N];
int first[N];
int last[N];
int top;
pair<int, int> tab[K][2 * N];
int dep[N];
int lg[2 * N];
vector<int> g[N];

void build(int a) {
  tab[0][++top] = { dep[a], a };
  first[a] = last[a] = top;

  for (auto& b : g[a]) {
    dep[b] = 1 + dep[a];
    build(b);
    tab[0][++top] = { dep[a], a };
    last[a] = top;
  }
}

int lca(int a, int b) {
  if (first[a] > last[b]) swap(a, b);
  a = first[a];
  b = last[b];
  assert(a <= b);
  int k = lg[b - a + 1];
  return min(tab[k][a], tab[k][b - (1 << k) + 1]).second;
}

int dist(int a, int b) {
  return dep[a] + dep[b] - 2 * dep[lca(a, b)];
}

int prs[N][2];
int jmen[N];

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
  n++;
  for (int i = 2; i <= n; i++) {
    cin >> parrent[i];
    g[parrent[i]].push_back(i);
  }
  build(1);
  for (int i = 2; i <= top; i++) lg[i] = 1 + lg[i / 2];
  for (int k = 1; (1 << k) <= top; k++) {
    for (int i = 1; i + (1 << k) - 1 <= top; i++) {
      tab[k][i] = min(tab[k - 1][i], tab[k - 1][i + (1 << (k - 1))]);
    }
  }
  int a = 1, b = 1;
  prs[1][0] = a;
  prs[1][1] = b;
  for (int i = 2; i <= n; i++) {
    int new_max = max(dist(a, i), dist(b, i));
    if (new_max > dist(a, b)) {
      if (dist(a, i) > dist(b, i)) b = i;
      else a = i;
    }
    prs[i][0] = a;
    prs[i][1] = b;
  }


  for (int i = 1; i <= n; i++) {
    int last = i - 1, low = i, high = n;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (dist(prs[mid][0], prs[mid][1]) == max(dist(prs[mid][0], i), dist(prs[mid][1], i))) {
        last = mid;
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    jmen[i]++;
    jmen[last + 1]--;
  }
  for (int i = 2; i <= n; i++) {
    jmen[i] += jmen[i - 1];
    cout << jmen[i] << "\n";
  }
}