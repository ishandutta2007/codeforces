#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

bool head_eq(string s, string t) {
  if (s.size() >= t.size()) {
    for (int i=0; i<t.size(); ++i) {
      if (s[i] != t[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

struct State {
  ll hahas = 0;
  string beg, fin;
  State() {}
  State(string s) {
    for (int i=0; i+3<s.size(); ++i) {
      hahas += (s[i] == 'h' && s[i+1] == 'a' && s[i+2] == 'h' && s[i+3] == 'a');
    }
    for (int i=0; i<s.size() && i<3; ++i) {
      beg += s[i];
      fin += s[(int) s.size()-1-i];
    }
    reverse(fin.begin(), fin.end());
  }
  State operator+ (const State& o) const {
    State res;
    res.hahas = hahas + o.hahas;
    string mid = fin + o.beg;
    for (int i=0; i+3<mid.size(); ++i) {
      if (mid[i] == 'h' && mid[i+1] == 'a' && mid[i+2] == 'h' && mid[i+3] == 'a') {
        ++res.hahas;
      }
    }
    if (beg.size() == 3) {
      res.beg = beg;
    } else {
      res.beg = beg + o.beg;
      while (res.beg.size() > 3) {
        res.beg.pop_back();
      }
    }
    if (fin.size() == 3) {
      res.fin = o.fin;
    } else {
      res.fin = fin + o.fin;
      reverse(res.fin.begin(), res.fin.end());
      while (res.fin.size() > 3) {
        res.fin.pop_back();
      }
      reverse(res.fin.begin(), res.fin.end());
    }
    return res;
  }
};
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n;
    map<string, State> mp;
    State recent;
    while (n--) {
      string nom;
      cin >> nom;
      string op;
      cin >> op;
      if (op[0] == ':') {
        string val;
        cin >> val;
        recent = mp[nom] = State(val);
      } else {
        string v1, v2, o;
        cin >> v1 >> o >> v2;
        assert(o == "+");
        recent = mp[nom] = mp[v1] + mp[v2];
      }
    }
    cout << recent.hahas << "\n";
  }
  return 0;
}