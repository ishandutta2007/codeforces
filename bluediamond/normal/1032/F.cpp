#include <bits/stdc++.h>


using namespace std;

#define free free22342423432234234324324
bool home = 1;
typedef long long ll;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int& a, int b) {
  a = add(a, b);
}

void mulup(int& a, int b) {
  a = mul(a, b);
}

const int N = (int)3e5 + 7;
int n, used[N], free[N], alone[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  {
    vector<int> kids;
    for (auto& b : g[a]) {
      if (b == p) continue;
      kids.push_back(b);
      dfs(b, a);
    }
    g[a] = kids;
  }

  {
    alone[a] = 1;
    for (auto& b : g[a]) {
      int current = 0;
      /// I skip the edge


      addup(current, add(alone[b], used[b]));

      mulup(alone[a], current);
    }
  }
  {
    free[a] = 1;
    for (auto& b : g[a]) {
      int current = 0;
      /// I skip the edge
      addup(current, add(alone[b], used[b]));
      /// I don't skip the edge
      addup(current, used[b]);

      mulup(free[a], current);
    }
  }
  {
    used[a] = 0;
    for (auto& pr : g[a]) {
      int sol = 1;
      mulup(sol, free[pr]);

      int current = 0;
      /// I skip the edge
      addup(current, add(alone[pr], used[pr]));
      /// I don't skip the edge
      addup(current, used[pr]);

      mulup(sol, dv(free[a], current));

      addup(used[a], sol);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  cout << add(used[1], alone[1]) << "\n";
}