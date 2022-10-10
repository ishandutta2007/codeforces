#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define len(x) ((int)x.size())
#define llong long long 
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define llong long long 

template<typename x> ostream& operator<< (ostream& cout, const vector<x>& a) {
  cout << "[";
  len(a) && cout << a[0];
  rep1(i, len(a) - 1) cout << ", " << a[i] ;
  return cout << "]";
}

template<typename u, typename v>
ostream& operator<< (ostream& cout, const pair<u, v>& a) {
  return cout << "(" << a.xx << ", " << a.yy << ")";
}

#define maxbit 13
int w, n, m;
vector<int> cnt[1 << maxbit];
int tempcnt[1 << maxbit] = {0};

bool runcmd(char cmd, bool u, bool v) {
  bool ans = 0;
  switch(toupper(cmd)) {
    case 'A': ans = u and v; break;
    case 'O': ans = u or v; break;
    case 'X': ans = u != v; break;
  }
  if (islower(cmd)) ans = !ans;
  return ans;
}

bool preruncmd[127][2][2] = {0};

void add(int u, int mask = 0, int num = 0, int p = w) {
  if (!p--) {
    cnt[mask][num] += tempcnt[u];
    return ;
  }
  add(u, mask << 1, num, p);
  add(u, mask << 1 | 1, num << 1 | ((u >> p) & 1), p);
}

string cmd;
int get(int u = 0, int mask = 0, int num = 0, int p = 0) {
  if (p == w) {
    return cnt[mask][num] * tempcnt[u];
  }
  int ans = 0;
  u <<= 1;
  mask <<= 1;
  rep(i, 2) {
    bool c0 = preruncmd[(int)cmd[p]][i][0];
    bool c1 = preruncmd[(int)cmd[p]][i][1];
    if (c0 and c1) continue;
    else if (!c0 and !c1) ans += get(u | i, mask, num, p + 1);
    else if (!c0) ans += get(u | i, mask | 1, num << 1, p + 1);
    else if (!c1) ans += get(u | i, mask | 1, num << 1 | 1, p + 1);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> w >> n >> m;
  for (int c: "AOXaox") rep(i, 2) rep(f, 2) {
    preruncmd[c][i][f] = runcmd((char)c, i, f);
  }
  rep(i, (1 << w)) {
    cnt[i].resize(1 << __builtin_popcount(i));
  }
  rep(i, n) {
    int u; cin >> u;
    tempcnt[u] ++;
  }
  rep(i, (1 << w)) {
    if (tempcnt[i]) add(i);
  }

  while (m--) {
    cin >> cmd;
    cout << get() << '\n';
  }

  return 0;
}