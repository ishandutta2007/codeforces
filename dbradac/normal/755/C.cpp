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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

vector <int> V[MAX];
int bio[MAX];
int p[MAX];

void dfs(int x)
{
  if (bio[x]++) return;
  for (auto it : V[x])
    dfs(it);
}

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, n) {
    scanf("%d", &p[i]); p[i]--;
    V[p[i]].push_back(i);
    V[i].push_back(p[i]);
  }

  int r=0;
  REP(i, n) {
    if (!bio[i]) {
      r++;
      dfs(i);
    }
  }

  printf("%d\n", r);

  return 0;
}