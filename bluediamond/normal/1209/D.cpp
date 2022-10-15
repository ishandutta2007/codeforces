#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, m;
vector <int> g[N];
bool u[N];

int ctc;
void dfs(int nod) {
  u[nod] = 1;
  ctc++;
  for (auto &nou : g[nod]) {
    if (u[nou] == 0) {
      dfs(nou);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (u[i] == 0) {
      ctc = 0;
      dfs(i);
      ans += ctc - 1;
    }
  }
  cout << m - ans << '\n';

  return 0;
}