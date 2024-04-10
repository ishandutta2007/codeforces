#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
int v[N];
int rmin[N];
int thep[N];
int igh[N];
bool valid[N];
ll sol = 0;

int tree[4 * N];

void build(int v, int tl, int tr) {
  tree[v] = INF;
  if (tl == tr) {
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
}

void upd(int v, int tl, int tr, int pos, int k) {
  if (tr < pos || pos < tl) {
    return;
  }
  if (tl == tr) {
    assert(tl == pos);
    assert(tr == pos);
    tree[v] = min(tree[v], k);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, pos, k);
  upd(2 * v + 1, tm + 1, tr, pos, k);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int fnd(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return INF;
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return min(fnd(2 * v, tl, tm, l, r), fnd(2 * v + 1, tm + 1, tr, l, r));
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n + 1; i++) {
    rmin[i] = n + 1;
  }

  for (int it = 1; it <= 2; it++) {

    {
      vector<int> stk;
      for (int k = 1; k <= n; k++) {
        while (!stk.empty() && v[stk.back()] >= v[k]) {
          stk.pop_back();
        }
        if (stk.empty()) {
          thep[k] = 0;
        } else {
          thep[k] = stk.back();
        }
        stk.push_back(k);
      }
    }
    {
      vector<int> stk;

      for (int l = n; l >= 1; l--) {
        while (!stk.empty() && v[l] >= v[stk.back()]) stk.pop_back();
        igh[l] = 0;
        if (!stk.empty()) {
          igh[l] = stk.back();
        }
        stk.push_back(l);
      }
    }
    {
      vector<int> indsInOrder(n);
      iota(indsInOrder.begin(), indsInOrder.end(), 1);
      sort(indsInOrder.begin(), indsInOrder.end(), [&] (int i, int j) {
            return v[i] < v[j];
           });
      for (int i = 1; i <= n; i++) {
        valid[i] = 0;
      }

      build(1, 1, n);

      for (auto &l : indsInOrder) {
        if (igh[l]) {
          rmin[l] = min(rmin[l], fnd(1, 1, n, igh[l] + 1, n));
        }
        upd(1, 1, n, thep[l], l);
        valid[l] = 1;
      }
    }


    for (int i = 1; i <= n; i++) {
      v[i] = n + 1 - v[i];
    }
  }

  ll sol = 0;

  for (int i = n; i >= 1; i--) {
    rmin[i] = min(rmin[i + 1], rmin[i]);
    sol += rmin[i] - i;
  }


  cout << sol << "\n";
}