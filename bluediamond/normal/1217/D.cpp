#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
int n, m;
vector <int> gg[N];
int col[N], val[N];
bool u[N], act[N];

void dfs(int a) {
  u[a] = act[a] = 1;
  for (auto &i : gg[a]) {
    int b = val[i] ^ a;
    if (u[b] == 0) {
      ///cout << "# " << a << " " << b << "\n";
      col[i] = 1;
      dfs(b);
    } else {
      if (col[i] == 0) {
        if (act[b] == 0) {
          col[i] = 1;
        } else {
          col[i] = 2;
        }
      }
    }
  }
  act[a] = 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ///freopen ("input", "r", stdin);
  ///freopen ("output", "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    val[i] = a ^ b;
    gg[a].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (u[i] == 0) {
      dfs(i);
    }
  }
  int mx = 0;
  for (int i = 1; i <= m; i++) {
    mx = max(mx, col[i]);
  }
  cout << mx << '\n';
  for (int i = 1; i <= m; i++) {
    if (col[i] == 0) {
      col[i] = 1;
    }
    cout << col[i] << ' ';
  }
  cout << '\n';

  return 0;
}