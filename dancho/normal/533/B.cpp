#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<int> son[1 << 18];
long long a[1 << 18];
long long dp[1 << 18][2];
long long sdp[1 << 18][2];
int ns[1 << 18];

long long getSDP(int v, int pa);

long long getDP(int v, int pa) {
  if (dp[v][pa] != -1) {
    return dp[v][pa];
  }
  long long sol = 0;
  // take
  //
  if (pa == 1) {
    long long wtake = a[v];
    if (son[v].size()) {
      wtake += getSDP(son[v][0], 0);
    }
    sol = max(sol, wtake);
  }

  long long ntake = 0;
  if (son[v].size()) {
    ntake += getSDP(son[v][0], pa);
  }
  sol = max(sol, ntake);
  return (dp[v][pa] = sol);
}

long long getSDP(int v, int pa) {
  if (sdp[v][pa] != -1) {
    return sdp[v][pa];
  }
  long long sol = 0;
  if (ns[v] == -1) {
    return (sdp[v][pa] = getDP(v, pa));
  }
  sol = max(getDP(v, 1) + getSDP(ns[v], 1 - pa), getDP(v, 0) + getSDP(ns[v], pa));
  return (sdp[v][pa] = sol);
}

int main() {
  memset(ns, -1, sizeof(ns));
  
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int p;
    scanf("%d %lld", &p, &a[i]);
    if (p != -1) {
      if (son[p].size()) {
        ns[son[p].back()] = i;
      }
      son[p].push_back(i);
    }
  }

  memset(dp, -1, sizeof(dp));
  memset(sdp, -1, sizeof(sdp));

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, getDP(i, 1));
    ans = max(ans, getDP(i, 0));
  }

  printf("%lld\n", ans);
  return 0;
}