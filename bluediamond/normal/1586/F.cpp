#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int relu(int a) {return max(a, 0);}

const int N = 1000 + 7;
int n, k, edge[N][N], mx;

void split(int l, int r, int cur) {
  if (l >= r) {
    return;
  }
  mx += relu(cur - mx);
  int len = r - l + 1;
  vector<int> lens(k);
  for (int i = 0; i < k; i++) {
    lens[i] = len / k;
  }
  for (int i = 0; i < len % k; i++) {
    lens[i]++;
  }
  vector<pair<int, int>> intvs;
  for (auto &it : lens) {
    intvs.push_back({l, l + it - 1});
    l += it;
  }
  assert(l == r + 1);
  for (auto &it : intvs) {
    split(it.first, it.second, cur + 1);
  }
  for (auto &it : intvs) {
    for (auto &it2 : intvs) {
      if (it == it2) break;
      for (int j = it.first; j <= it.second; j++) {
        for (int i = it2.first; i <= it2.second; i++) {
          edge[i][j] = cur;
        }
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 // freopen ("input", "r", stdin);

  cin >> n >> k;

  split(1, n, 1);

  cout << mx << "\n";
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      cout << edge[i][j] << " ";
    }
  }
  cout << "\n";

  return 0;
}