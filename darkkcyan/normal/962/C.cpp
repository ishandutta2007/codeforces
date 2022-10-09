#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )

llong tonum(const string& s) {
  llong ans = 0;
  for (auto i: s) ans = ans * 10 + i - '0';
  return ans;
}

bool checksq(const string& s) {
  llong num = tonum(s);
  llong sq = (llong)sqrt(num);
  //clog << num << " " << sq << endl;
  return (sq * sq == num);
}

map<string, int> ma;
llong process(string s) {
  queue<string> qu;
  ma[s] = 0;
  for (qu.push(s); len(qu); qu.pop()) {
    string u = qu.front();
    if (u == "") continue;
    clog << u << endl;
    if (checksq(u)) return ma[u];
    rep(i, len(u) + 1) {
      string v = u.substr(0, i) + u.substr(min(i + 1, len(u)));
      if (ma.count(v)) continue;
      if (v[0] == '0') continue;
      //clog << v << endl;
      ma[v] = ma[u] + 1;
      qu.push(v);
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s;
  cin >> s;
  cout << process(s);

  return 0;
}