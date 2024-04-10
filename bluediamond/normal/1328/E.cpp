#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 7;
const int LG = 20;

int n, q;
vector<int> g[N], g2[N];
int dep[N];
int euler[3 * N], top;
int first[N], last[N];

struct kek {
  int fi;
  int se;
};

kek rmq[3 * N][LG];
int mylog[3 * N];

void build(int nod) {
  euler[++top] = nod;
  first[nod] = last[nod] = top;
  for(auto &nou : g[nod]) {
    dep[nou] = 1 + dep[nod];
    build(nou);
    euler[++top] = nod;
    last[nod] = top;
  }
}

kek Min(kek a, kek b) {
  if(a.fi < b.fi) {
    return a;
  } else {
    return b;
  }
}

void buildRMQ() {
  for(int i = 2; i <= top; i++) {
    mylog[i] = 1 + mylog[i / 2];
  }
  for(int i = 1; i <= top; i++) {
    rmq[i][0] = {dep[euler[i]], i};
  }
  for(int k = 1; (1 << k) <= top; k++) {
    for(int i = 1; i + (1 << k) - 1 <= top; i++) {
      rmq[i][k] = Min(rmq[i][k - 1], rmq[i + (1 << (k - 1))][k - 1]);
    }
  }
}

int lca(int a, int b) {
  int st = last[a];
  int dr = first[b];
  if(st > dr) {
    swap(st, dr);
  }
  int k = mylog[dr - st + 1];
  kek sol = Min(rmq[st][k], rmq[dr - (1 << k) + 1][k]);
  return euler[sol.se];
}

bool lmao[N];
int papa[N];

void bgg(int x) {
  lmao[x] = 1;
  for (auto &y : g2[x]) {
    if (lmao[y]) {
      continue;
    }
    g[x].push_back(y);
    bgg(y);
    papa[y] = x;
  }
}

bool cmp(int a, int b) {
  return dep[a] > dep[b];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g2[x].push_back(y);
    g2[y].push_back(x);
  }
  bgg(1);
  build(1);
  buildRMQ();

  while (q--) {
    int k;
    cin >> k;
    vector<int> a(k);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end(), cmp);
    bool ok = 1;
    int val = a[0];
    for (auto &x : a) {
      int y = lca(x, val);
      ok &= (y == x || y == papa[x]);
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}