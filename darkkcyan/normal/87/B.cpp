#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

map<string, int> types;
int gettype(const string& s) {
  int asc = 0, amc = 0;
  string name = "";
  for (auto i: s) {
    if (i == '&') amc++;
    else if (i == '*') asc++;
    else name += i;
  }
  if (!types.count(name)) return -1;
  if (types[name] == -1) return -1;
  int ans = types[name] + asc - amc;
  return ans < 0 ? -1 : ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  types["void"] = 0;
  types["errtype"] = -1;
  while (n--) {
    string cmd; cin >> cmd;
    if (cmd[4] == 'd') {
      string a, b; cin >> a >> b;
      types[b] = gettype(a);
    } else {
      string a; cin >> a;
      int ans = gettype(a);
      if (ans == -1) cout << "errtype\n";
      else cout << "void" << string(ans, '*') << '\n';
    }
  }
  
  return 0;
}