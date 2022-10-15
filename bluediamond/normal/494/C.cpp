#include <bits/stdc++.h>

using namespace std;

typedef double ld;

struct T {
  int l, r, mx;
  ld prob_yes, prob_no;
};

bool operator < (T a, T b) {
  if (a.r == b.r) {
    return a.l < b.l;
  } else {
    return a.r > b.r;
  }
}

const int N = (int) 1e5 + 7;
const int Q = (int) 5e3 + 7;
const int INF = (int) 1e9 + 7;
int n, q, init_dollars[N], par[Q];
T offers[Q];
int max_tree[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    max_tree[v] = init_dollars[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    max_tree[v] = max(max_tree[2 * v], max_tree[2 * v + 1]);
  }
}

int get_max(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return -INF;
  }
  if (l <= tl && tr <= r) {
    return max_tree[v];
  } else {
    int tm = (tl + tr) / 2;
    return max(get_max(2 * v, tl, tm, l, r), get_max(2 * v + 1, tm + 1, tr, l, r));
  }
}

int get_max(int l, int r) {
  return get_max(1, 1, n, l, r);
}

vector<int> g[Q];
int mx[Q];
int maxdown[Q];
ld prob[Q][Q];
ld new_prob[Q];

void dfs(int a) {
  maxdown[a] = 0;
  prob[a][0] = 1;

  for (auto &b : g[a]) {
    dfs(b);


    for (int j = 0; j <= max(maxdown[a], maxdown[b]); j++) {
      new_prob[j] = 0;
    }


    for (int i = 0; i <= maxdown[a]; i++) {
      for (int j = 0; j <= maxdown[b]; j++) {
        int val_i = mx[a] + i, val_j = mx[b] + j;
        int val_mx = max(val_i, val_j);

        assert(mx[a] <= val_i && val_i <= mx[a] + max(maxdown[a], maxdown[b]));
        assert(mx[a] <= val_mx && val_mx <= mx[a] + max(maxdown[a], maxdown[b]));
        new_prob[val_mx - mx[a]] += prob[a][i] * prob[b][j];
      }
    }

    for (int j = 0; j <= max(maxdown[a], maxdown[b]); j++) {
      prob[a][j] = new_prob[j];
    }

    maxdown[a] = max(maxdown[a], maxdown[b]);
  }

  maxdown[a]++;

  for (int j = 0; j <= maxdown[a]; j++) {
    new_prob[j] = 0;
  }

  for (int j = 0; j <= maxdown[a]; j++) {
    new_prob[j] += offers[a].prob_no * prob[a][j];
    new_prob[j + 1] += offers[a].prob_yes * prob[a][j];
  }

  for (int j = 0; j <= maxdown[a]; j++) {
    prob[a][j] = new_prob[j];
  }

}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> init_dollars[i];
  }

  build(1, 1, n);

  for (int i = 1; i <= q; i++) {
    cin >> offers[i].l >> offers[i].r >> offers[i].prob_yes;
  }

  offers[++q] = {1, n, 0};

  for (int i = 1; i <= q; i++) {
    offers[i].prob_no = 1 - offers[i].prob_yes;
  }

  sort(offers + 1, offers + q + 1);

  for (int i = 1; i <= q; i++) {
    offers[i].mx = get_max(offers[i].l, offers[i].r);

    /// cout << " : " << offers[i].l << ", " << offers[i].r << " -> " << offers[i].mx << "\n";
  }

  vector<int> stk;
  stk.push_back(1);

  for (int i = 2; i <= q; i++) {
    while (!stk.empty() && offers[i].r < offers[stk.back()].l) {
      stk.pop_back();
    }
    assert(!stk.empty());
    par[i] = stk.back();
    stk.push_back(i);
  }

  for (int i = 2; i <= q; i++) {
    g[par[i]].push_back(i);
  }

  for (int i = 1; i <= q; i++) {
    mx[i] = offers[i].mx;
  }

  dfs(1);

  ld e = 0;

  for (int j = 0; j <= maxdown[1]; j++) {
    e += (offers[1].mx + j) * prob[1][j];
  }
  cout << fixed << setprecision(6) << e << "\n";

  /**for (int i = 2; i <= q; i++) {
    cout << "(" << offers[par[i]].l << " " << offers[par[i]].r << ") -> " << "(" << offers[i].l << " " << offers[i].r << ")\n";
  }**/
}