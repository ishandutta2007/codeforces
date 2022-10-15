#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

const int N = (int)2e5 + 7;
int n;
int m;
int q;
int curt;
pair<int, int> want[N];

map<pair<int, int>, int> mp;
map<pair<int, int>, int> whenStart;

struct Edge {
  int x;
  int y;
  int d;
};

vector<pair<Edge, pair<int, int>>> pushing;

void add(int x, int y, int d) {
  if (x > y) swap(x, y);

  mp[{x, y}] = d;
  whenStart[{x, y}] = curt;
}

void del(int x, int y) {
  if (x > y) swap(x, y);
  int d = mp[{x, y}];
  int Start = whenStart[{x, y}];
  int End = curt;
  mp.erase({ x, y });
  whenStart.erase({ x, y });

  if (Start < End) {
    pushing.push_back({ {x, y, d}, {Start, End - 1} });
  }
}

vector<Edge> edges[4 * N];

void pushEdge(int v, int tl, int tr, int l, int r, Edge edge) {
  if (r < tl || tr < l) return;
  if (l <= tl && tr <= r) {
    edges[v].push_back(edge);
    return;
  }
  int tm = (tl + tr) / 2;
  pushEdge(2 * v, tl, tm, l, r, edge);
  pushEdge(2 * v + 1, tm + 1, tr, l, r, edge);
}

const int B = 30;
int t[N];
int h[N];
int Xor[N];
vector<int> num(B, 0);

int getRoot(int a) {
  if (t[a] == a) {
    return a;
  }
  else {
    return getRoot(t[a]);
  }
}

int getXor(int a) {
  if (t[a] == a) {
    return 0;
  }
  else {
    return Xor[a] ^ getXor(t[a]);
  }
}

struct History {
  vector<int> num;
  int a;
  int b;
  int ha;
  int hb;
  int XorA;
  int XorB;
};

vector<History> history;

void unite(int a, int b, int d) {
  int EdgeFirst = a;
  int EdgeSecond = b;
  a = getRoot(a);
  b = getRoot(b);

  history.push_back({ num, a, b, h[a], h[b], Xor[a], Xor[b] });

  if (a == b) {

    int XorCycle = getXor(EdgeFirst) ^ getXor(EdgeSecond) ^ d;

    for (int i = B - 1; i >= 0; i--) {
      if (XorCycle & (1 << i)) {
        XorCycle ^= num[i];
      }
    }

    if (XorCycle > 0) {
      for (int i = B - 1; i >= 0; i--) {
        if (XorCycle & (1 << i)) {
          num[i] = XorCycle;
          break;
        }
      }
    }

    return;
  }

  if (h[a] > h[b]) {
    swap(a, b);
    swap(EdgeFirst, EdgeSecond);
  }


  t[a] = b;
  h[b] += (h[a] == h[b]);

  int XorOnPath = getXor(EdgeFirst) ^ getXor(EdgeSecond);

  Xor[a] ^= XorOnPath ^ d;

  XorOnPath = getXor(EdgeFirst) ^ getXor(EdgeSecond);


}

void rollBack() {
  History Data = history.back();
  history.pop_back();
  num = Data.num;
  int a = Data.a;
  int b = Data.b;
  int ha = Data.ha;
  int hb = Data.hb;
  int XorA = Data.XorA;
  int XorB = Data.XorB;
  t[a] = a;
  t[b] = b;
  h[a] = ha;
  h[b] = hb;
  Xor[a] = XorA;
  Xor[b] = XorB;
}

void dfs(int v, int tl, int tr) {
  for (auto& edge : edges[v]) {
    unite(edge.x, edge.y, edge.d);
  }
  if (tl == tr) {
    int x = want[tl].first;
    int y = want[tr].second;

    int XorOnPath = getXor(x) ^ getXor(y);

    for (int i = B - 1; i >= 0; i--) {
      XorOnPath = min(XorOnPath, XorOnPath ^ num[i]);
    }
    cout << XorOnPath << "\n";

  }
  else {
    int tm = (tl + tr) / 2;
    dfs(2 * v, tl, tm);
    dfs(2 * v + 1, tm + 1, tr);
  }
  for (auto& edge : edges[v]) {
    rollBack();
  }
}


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


  for (int i = 0; i < N; i++) {
    t[i] = i;
    h[i] = 1;
  }

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y, d;
    cin >> x >> y >> d;
    add(x, y, d);
  }
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, y, d;
      cin >> x >> y >> d;
      add(x, y, d);
    }
    if (type == 2) {
      int x, y;
      cin >> x >> y;
      del(x, y);
    }
    if (type == 3) {
      int x, y;
      cin >> x >> y;
      want[curt] = { x, y };
      curt++;
    }
  }
  for (auto& IT : mp) {
    Edge edge = { IT.first.first, IT.first.second, IT.second };
    int Start = whenStart[IT.first];
    int End = curt;
    if (Start < End) {
      pushing.push_back({ edge, {Start, End - 1} });
    }
  }
  for (auto& PR : pushing) {
    Edge edge = PR.first;
    int l = PR.second.first;
    int r = PR.second.second;
    pushEdge(1, 0, curt - 1, l, r, edge);
  }
  dfs(1, 0, curt - 1);
}