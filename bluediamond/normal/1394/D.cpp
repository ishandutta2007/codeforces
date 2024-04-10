#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void maxup(ll &a, ll b) {
  a = max(a, b);
}

const int N = (int) 2e5 + 7;
int n;
ll t[N];
ll h[N];
vector<int> g[N];
int in[N];
int out[N];
bool vis[N];
ll dp0[N];
ll dp1[N];

void dfs(int a, bool is_root) {
  ll sum_dp1 = 0;
  vis[a] = 1;

  vector<ll> difs;
  vector<int> kids;

  for (auto &b : g[a]) {
    if (vis[b]) continue;
    kids.push_back(b);
    dfs(b, 0);

    sum_dp1 += dp1[b];
    difs.push_back(dp0[b] - dp1[b]);
  }

  sort(difs.rbegin(), difs.rend());

  int sz = (int) kids.size();
  assert((int) kids.size() == sz);
  assert((int) difs.size() == sz);


  ll sum = sum_dp1;


  for (int times = 0; times <= sz; times++) {
    if (times) {
      sum += difs[times - 1];
    }
    maxup(dp0[a], sum + t[a] * min(in[a] + times, out[a] + sz + !is_root - times));
    maxup(dp1[a], sum + t[a] * min(in[a] + times + !is_root, out[a] + sz - times));
  }

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

///  freopen ("___input___.txt", "r", stdin);


  cin >> n;
  ll sum_total = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    sum_total += t[a] + t[b];
    if (h[a] == h[b]) {
      g[a].push_back(b);
      g[b].push_back(a);
    } else {
      if (h[a] > h[b]) swap(a, b);
      assert(h[a] < h[b]);
      in[a]++;
      out[b]++;
    }
  }

  ll sol = 0;

  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs(i, 1);
    sol += max(dp0[i], dp1[i]);

    continue;
  }
  cout << sum_total - sol << "\n";


  return 0;
}