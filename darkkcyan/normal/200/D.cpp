#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

struct func {
  string name;
  vector<string> pl;
};

func parsefunc(string s, bool iscall) {
  for (char& i: s) if (i == '(' or i == ')' or i == ',') i = ' ';
  stringstream ss; ss << s;
  func ans;
  if (!iscall) ss >> s;
  ss >> ans.name;
  while (ss >> s) {
    ans.pl.push_back(s);
    if (!iscall) ans.pl.back() = s[0];
  }
  return ans;
}

map<string, vector<func> > funcmap;
map<string, char> varmap;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m, k;
  cin >> n;
  string s;
  rep(_, n) {
    getline(cin >> ws, s);
    func t = parsefunc(s, 0);
    funcmap[t.name].push_back(t);
  }
  cin >> m;
  rep(_, m) {
    getline(cin >> ws, s);
    stringstream ss; ss << s;
    string type, name; ss >> type >> name;
    varmap[name] = type[0];
  }
  cin >> k;
  rep(_, k) {
    getline(cin >> ws, s);
    func t = parsefunc(s, 1);
    vector<char> tl;
    try {
      if (!funcmap.count(t.name)) throw 0;
      for (auto u: t.pl) {
        if (!varmap.count(u)) throw 0;
        tl.push_back(varmap[u]);
      }
      int ans = 0;
      for (auto u: funcmap[t.name]) {
        if (len(u.pl) != len(tl)) continue;
        ++ans;
        rep(i, len(tl)) {
          if (u.pl[i] != "T" and tl[i] != u.pl[i][0]) {
            --ans;
            break;
          }
        }
      }
      throw ans;
    } catch (int ans) {
      cout << ans << '\n';
    }
  }
  
  return 0;
}