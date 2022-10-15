#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, m;

struct Ed {
  int a;
  int b;
};

Ed e[N];

int sz[N];
ll ans[N];
int t[N];

int par(int a) {
  if (t[a] == a) {
    return a;
  } else {
    return t[a] = par(t[a]);
  }
}

ll sol = 0;

void uni(int a, int b) {
  a = par(a);
  b = par(b);
  t[a] = b;
  sol -= (ans[a] + ans[b]);
  ans[b] = ans[b] + ans[a] + sz[a] * (ll) sz[b];
  sol += ans[b];
  sz[b] += sz[a];
}

vector <Ed> u[N];
ll res[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    u[w].push_back({a, b});
  }

  for (int i = 1; i <= n; i++) {
    t[i] = i;
    sz[i] = 1;
  }

  for (int i = 1; i < N; i++) {
    for (auto &it : u[i]) {
      uni(it.a, it.b);
    }
    res[i] = sol;
  }

  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    cout << res[x] << " ";
  }
  cout << "\n";

  return 0;
}