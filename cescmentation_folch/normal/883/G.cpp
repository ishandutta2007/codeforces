#include<bits/stdc++.h>

using namespace std;

struct aresta {
  int x, y;
  int d;
  int c;
};

typedef vector<aresta> va;
typedef vector<int> vi;

const int N = 300010;

vi G[N];
va A;
int K[N];
int mii;

int vei(int x, int i) {
  if (mii) {
    if (A[i].d == 0) {
      if (A[i].x == x) return A[i].y;
      return -1;
    }
    if (A[i].x == x) A[i].c = -1;
    else A[i].c = 1;
    return -1;
  }
  if (A[i].x == x) {
    if (A[i].d == 1 and A[i].c == -1) return -1;
    if (A[i].d == 1) {
      A[i].c = 1;
      return A[i].y;
    }
    return A[i].y;
  }
  if (A[i].d == 1 and A[i].c == 1) return -1;
  if (A[i].d == 1) {
    A[i].c = -1;
    return A[i].x;
  }
  return -1;
}

int dfs(int x) {
  if (x == -1 or K[x]) return 0;
  K[x] = 1;
  int sum = 1;
  for (int i = 0; i < G[x].size(); ++i) {
    int y = vei(x, G[x][i]);
    sum += dfs(y);
  }
  return sum;
}



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < m; ++i) {
    int x, y, d;
    cin >> d >> x >> y;
    aresta a;
    a.x = x;
    a.y = y;
    if (d==1) a.d = 0;
    else a.d = 1;
    a.c = 0;
    G[x].push_back(A.size());
    G[y].push_back(A.size());
    A.push_back(a);
  }
  mii = 0;
  cout << dfs(s) << endl;
  for (int i = 0; i < m; ++i) {
    if (A[i].d) {
      if (A[i].c == 1) cout << '+';
      else cout << '-';
      A[i].c = 0;
    }
  }
  cout << endl;
  memset(K, 0, sizeof(K));
  mii = 1;
  cout << dfs(s) << endl;
  for (int i = 0; i < m; ++i) {
    if (A[i].d) {
      if (A[i].c == 1) cout << '+';
      else cout << '-';
      A[i].c = 0;
    }
  }
  cout << endl;
}