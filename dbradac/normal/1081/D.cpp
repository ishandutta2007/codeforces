#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;

int root[MAX], cnt[MAX];

int find(int x) {
  if (root[x] == -1) return x;
  return root[x] = find(root[x]);
}

void spoji(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (rand() & 1) swap(a, b);
  cnt[b] += cnt[a];
  root[a] = b;
}

vector <pair<int, P > > E;

int main()
{
  memset(root, -1, sizeof root);
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  REP(i, k) {
    int x;
    scanf("%d", &x); x--;
    cnt[x]++;
  }

  REP(i, m) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c); a--; b--;
    E.push_back(make_pair(c, P(a, b)));
  }

  sort(E.begin(), E.end());
  int sol=-1;

  for (auto it : E) {
    spoji(it.Y.X, it.Y.Y);
    if (cnt[find(it.Y.X)] == k) {
      sol = it.X;
      break;
    }
  }
  
  REP(i, k)
    printf("%d ", sol);
  

  return 0;
}