#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int add(int a, int b, int M) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b, int M) {
  return a * (ll)b % M;
}

int pw(int a, int b, int M) {
  int r = 1;
  while (b) {
    if (b & 1) r = r * (ll)a % M;
    a = a * (ll)a % M;
    b /= 2;
  }
  return r;
}

int dv(int a, int b, int M) {
  return mul(a, pw(b, M - 2, M), M);
}

const int M0 = (int)1e9 + 7;
const int M1 = (int)1e9 + 7;

struct Mint {
  int a0;
  int a1;
  void operator = (int x) {
    a0 = x % M0;
    a1 = x % M1;
    if (a0 < 0) a0 += M0;
    if (a1 < 0) a1 += M1;
  }
};

bool operator < (Mint x, Mint y) {
  if (x.a0 != y.a0) return x.a0 < y.a0;
  return x.a1 < y.a1;
}

Mint operator + (Mint x, Mint y) {
  return { add(x.a0,y.a0,M0), add(x.a1,y.a1,M1) };
}

Mint operator - (Mint x, Mint y) {
  return { add(x.a0,-y.a0,M0), add(x.a1,-y.a1,M1) };
}

Mint operator * (Mint x, Mint y) {
  return { mul(x.a0,y.a0,M0), mul(x.a1,y.a1,M1) };
}

Mint operator ^ (Mint x, int y) {
  return { pw(x.a0,y,M0), pw(x.a1,y,M1) };
}

Mint operator / (Mint x, Mint y) {
  return { dv(x.a0,y.a0,M0), dv(x.a1,y.a1,M1) };
}

bool operator == (Mint x, Mint y) {
  return x.a0 == y.a0 && x.a1 == y.a1;
}

const int N = 300000 + 7;
Mint magic = { 77, 99 };
int n;
int ct[N];
int value[N];
int score[N];
vector<int> g[N];
set<Mint> gs[N];
Mint weight[N];
Mint bias[N];

void solve(int a, int parrent = -1) {
  {
    vector<int> kids;
    for (auto& b : g[a]) {
      if (b == parrent) continue;
      kids.push_back(b);
      solve(b, a);
    }
    g[a] = kids;
  }

  Mint caract;
  caract = value[a];

  if (g[a].empty()) {
    weight[a] = 1;
    bias[a] = 0;
    gs[a].insert(caract);
    score[a] = (int)gs[a].size() + ct[a];
    return;
  }

  weight[a] = 1;
  bias[a] = 0;

  int big_node = g[a][0];
  for (auto& b : g[a]) {
    if ((int)gs[b].size() > (int)gs[big_node].size()) {
      big_node = b;
    }
  }

  weight[a] = weight[big_node];
  bias[a] = bias[big_node];
  swap(gs[a], gs[big_node]);

  {
    Mint y;
    y = 0;
    y = y - bias[a];
    y = y / weight[a];
    gs[a].insert(y);
  }

  for (auto& b : g[a]) {
    if (b == big_node) continue;
    for (auto& M : gs[b]) {
      gs[a].insert((weight[b] * M + bias[b] - bias[a]) / weight[a]);
    }
    gs[b].clear();
  }
  weight[a] = weight[a] * magic;
  bias[a] = bias[a] * magic + caract;
  score[a] = (int)gs[a].size() + ct[a];
}

signed main() { 
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ct[i];
  {
    string str;
    cin >> str;
    for (int i = 1; i <= n; i++) {
      int x = str[i - 1] - 'a';
      value[i] = x + 1;
    }
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  solve(1);

  int how_many = 0;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (score[i] > mx) {
      mx = score[i];
      how_many = 0;
    }
    how_many += (mx == score[i]);
  }
  cout << mx << "\n";
  cout << how_many << "\n";
}