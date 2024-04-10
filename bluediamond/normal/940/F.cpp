#include <bits/stdc++.h>

using namespace std;

map<int, int> Transformer; int OptimusPrime;

struct Q {
  int t;
  int l;
  int r;
  int ind;
};

int RAD;

bool operator < (Q a, Q b) {
  if (a.t / RAD != b.t / RAD) return a.t / RAD < b.t / RAD;
  if (a.l / RAD != b.l / RAD) return a.l / RAD < b.l / RAD;
  return a.r < b.r;
}

const int N = (int) 1e5 + 7;
int n, q, a[N], f[2 * N], ff[2 * N];
pair<int, int> operations[N];

int getNumber(int x) {
  if (!Transformer.count(x)) {
    Transformer[x] = ++OptimusPrime;
  }
  return Transformer[x];
}

void del(int x) {
  ff[f[x]]--;
  f[x]--;
  ff[f[x]]++;
}

void add(int x) {
  ff[f[x]]--;
  f[x]++;
  ff[f[x]]++;
}


int T, L = 1, R = 0;

vector<pair<int, int>> Updates;

void bring(int t, int l, int r) {
  while (T > t) {
    if (L <= Updates.back().first && Updates.back().first <= R) del(a[Updates.back().first]);
    a[Updates.back().first] = Updates.back().second;
    if (L <= Updates.back().first && Updates.back().first <= R) add(a[Updates.back().first]);
    Updates.pop_back();
    T--;
  }
  while (T < t) {
    T++;
    int j = operations[T].first, x = operations[T].second;
    Updates.push_back({j, a[j]});
    if (L <= j && j <= R) del(a[j]);
    a[j] = x;
    if (L <= j && j <= R) add(a[j]);
  }
  int lmax = max(L, l);
  int rmin = min(R, r);
  if (lmax <= rmin) {
    while (L < lmax) del(a[L++]);
    while (R > rmin) del(a[R--]);
    while (L > l) add(a[--L]);
    while (R < r) add(a[++R]);
  } else {
    for (int j = L; j <= R; j++) {
      del(a[j]);
    }
    L = l;
    R = r;
    for (int j = L; j <= R; j++) {
      add(a[j]);
    }
  }
}

int memo[N];

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  ff[0] = (int) 1e9 + 1;

  cin >> n >> q;
  while (RAD * RAD * RAD <= n) RAD++;
  RAD *= RAD;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = getNumber(a[i]);
  }


  vector<Q> questions;

  int OoOoOoOoOoOoOo = 0;
  int C = 0;

  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      questions.push_back({OoOoOoOoOoOoOo, l, r, (int) questions.size()}); C++;
    } else {
      int pos, x;
      cin >> pos >> x;
      x = getNumber(x);
      operations[++OoOoOoOoOoOoOo] = {pos, x};
    }
  }

  sort(questions.begin(), questions.end());

  int cnt = 0;

  for (auto &it : questions) {
    cnt++;
    bring(it.t, it.l, it.r);
    int sol = 0;
    while (ff[sol]) {
      sol++;
    }
    memo[it.ind] = sol;
  }

  for (int j = 0; j < C; j++) {
    cout << memo[j] << "\n";
  }

  return 0;
}