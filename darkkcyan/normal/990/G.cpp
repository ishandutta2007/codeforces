#include<bits/stdc++.h>
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
using namespace std;
#define maxn 201010

vector<int> divlist[maxn];
void gendivlist() {
  rep1(i, maxn - 1) {
    for (int f = i; f < maxn; f += i)
      divlist[f].push_back(i);
  }
}

int n;
int a[maxn];
vector<int> gr[maxn];
vector<int> group[maxn];

int curtime = 0;
int t[maxn] = {0};

int bfs(int u, int div) {
  int ans = 1;
  t[u] = curtime;
  queue<int> qu;
  for (qu.push(u); qu.size(); qu.pop()) {
    u = qu.front();
    for (auto v: gr[u]) {
      if (a[v] % div) continue;
      if (t[v] == curtime) continue;
      t[v] = curtime;
      ++ans;
      qu.push(v);
    }
  }
  return ans;
}

llong dp[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  gendivlist();
  cin >> n;
  rep1(i, n) {
    cin >> a[i];
    for (auto v: divlist[a[i]]) group[v].push_back(i);
  }
  rep(i, n - 1) {
    int u, v; cin >> u >> v;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }

  rep1(i, maxn - 1) {
    ++curtime;
    dp[i] = 0;
    for (auto f: group[i]) {
      if (t[f] == curtime) continue;
      llong temp = bfs(f, i);
      dp[i] += temp * (temp + 1) / 2;
    }
  }
  for (int i = maxn; --i > 0; ) {
    if (!dp[i]) continue;
    for (int f = i * 2; f < maxn; f += i) {
      dp[i] -= dp[f];
    }
  }
  rep1(i, maxn - 1) {
    if (dp[i]) cout << i << ' ' << dp[i] << '\n';
  }

  return 0;
}