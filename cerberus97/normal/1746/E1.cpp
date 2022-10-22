/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

set<int> add(set<int>& a, set<int>& b);
bool ask(set<int>& v);
void answer(int i);
void eval(set<int>& g1, set<int>& g2, bool r1, bool r2, set<int>& s);

int main() {
  fast_cin();
  int n; cin >> n;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    s.insert(i);
  }
  while (s.size() >= 4) {
    vector<set<int>> g(4);
    int cur = 0;
    for (auto& i : s) {
      g[cur].insert(i);
      cur = (cur + 1) % 4;
    }
    auto g23 = add(g[2], g[3]);
    auto g12 = add(g[1], g[2]);
    bool a23 = ask(g23);
    bool a12 = ask(g12);
    eval(g23, g12, a23, a12, s);
  }
  if (s.size() == 3) {
    auto cpy = s;
    int a = *s.begin(); s.erase(s.begin());
    int b = *s.begin(); s.erase(s.begin());
    int c = *s.begin(); s.erase(s.begin());
    s = cpy;
    vector<set<int>> cand = {{a}, {a}, {b}, {b}, {c}, {c}};
    int sz = cand.size();
    vector<bool> res(sz);
    for (int i = 0; i < sz; ++i) {
      res[i] = ask(cand[i]);
      if (i > 0) {
        eval(cand[i], cand[i - 1], res[i], res[i - 1], s);
      }
    }
  }
  // cout << s.size() << endl;
  for (auto& i : s) {
    answer(i);
  }
}

set<int> add(set<int>& a, set<int>& b) {
  set<int> ans = a;
  for (auto& i : b) {
    ans.insert(i);
  }
  return ans;
}

bool ask(set<int>& v) {
  cout << "? " << v.size() << ' ';
  for (auto& i : v) {
    cout << i << ' ';
  }
  cout << endl;
  string s; cin >> s;
  return (s[0] == 'Y');
}

void answer(int i) {
  cout << "! " << i << endl;
  string s; cin >> s;
  if (s == ":)") {
    exit(0);
  }
}

void eval(set<int>& g1, set<int>& g2, bool r1, bool r2, set<int>& s) {
  vector<int> ban;
  for (auto& i : s) {
    if (r1 == (g1.count(i) == 0) and r2 == (g2.count(i) == 0)) {
      ban.pb(i);
    }
  }
  for (auto& i : ban) {
    // cout << "banning " << i << endl;
    s.erase(i);
  }
}