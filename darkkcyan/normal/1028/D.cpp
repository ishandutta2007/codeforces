#include <bits/stdc++.h>
using namespace std;

#define llong long long
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; ) 

#define maxn 401010
#define rem ((llong)1e9+7)
int n;
vector<llong> unknown;
multiset<llong> sell, buy;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  sell.insert(LLONG_MAX);
  buy.insert(LLONG_MIN);

  llong ans = 1;

  rep(i, n) {
    string cmd; cin >> cmd;
    llong u; cin >> u;
    if (cmd == "ADD") {
      if (u <= *--buy.end()) buy.insert(u);
      else if (u >= *sell.begin()) sell.insert(u);
      else unknown.push_back(u);
      continue;
    }

    if (sell.count(u)) {
      if (*sell.begin() != u) {
        cout << "0";
        return 0;
      }
      sell.erase(sell.find(u));
      buy.insert(unknown.begin(), unknown.end());
      unknown.clear();
      continue;
    }
    if (buy.count(u)) {
      if (*--buy.end() != u) {
        cout << "0";
        return 0;
      }
      buy.erase(buy.find(u));
      sell.insert(unknown.begin(), unknown.end());
      unknown.clear();
      continue;
    }
    for (auto f: unknown) {
      if (f < u) buy.insert(f);
      if (f > u) sell.insert(f);
    }
    (ans *= 2) %= rem;
    unknown.clear();
  }
  (ans *= (llong)len(unknown) + 1) %= rem;
  cout << ans;

  return 0;
}