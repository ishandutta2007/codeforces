#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
int n, pl, ng, qs;
string str;

struct Node {
  int min_pref;
  int sum;
};

Node operator + (Node a, Node b) {
  int min_pref = min(a.min_pref, a.sum + b.min_pref);
  int sum = a.sum + b.sum;
  return {min_pref, sum};
}

Node t[4 * N];


void clr(int v, int tl, int tr) {
  t[v] = {0, 0};
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    clr(2 * v, tl, tm);
    clr(2 * v + 1, tm + 1, tr);
  }
}

void modif(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    assert(tl == i);
    assert(tr == i);
    t[v] = {x, x};
    return;
  }
  int tm = (tl + tr) / 2;
  modif(2 * v, tl, tm, i, x);
  modif(2 * v + 1, tm + 1, tr, i, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void modif(int i, int x) {
  modif(1, 1, n, i, x);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);

  int tst;
  cin >> tst;
  for (int tc = 1; tc <= tst; tc++) {
    cin >> str;
    n = (int) str.size();
    assert(n % 2 == 0);
    pl = ng = qs = 0;
    clr(1, 1, n);
    for (int i = 1; i <= n; i++) {
      char ch = str[i - 1];
      if (ch == '(') pl++, modif(i, +1);
      if (ch == ')') ng++, modif(i, -1);
      if (ch == '?') qs++, modif(i, +1);
    }
    bool ok = 1;
    for (int i = 1; i <= n; i++){
      char ch = str[i - 1];
      if (ch == '?') {
        bool ok_pl = 0;
        bool ok_ng = 0;


        if (pl + 1 <= n / 2) {
          ok_pl = 1;
        }
        if (ng + 1 <= n / 2) {
          modif(i, -1);


          ok_ng = (t[1].min_pref >= 0);
          modif(i, 0);
        }
        if (ok_pl && ok_ng) {
          ok = 0;
          break;
        }
        assert(ok_pl || ok_ng);

        if (ok_pl) {
          modif(i, +1);
          pl++;
        } else {
          assert(ok_ng);
          modif(i, -1);
          ng++;
        }
      }
    }
    cout << ((ok) ? ("YES") : ("NO")) << "\n";
  }
}