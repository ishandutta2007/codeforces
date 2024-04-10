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

const int MAX = 1024;

int n;
int rje[MAX];

vector <int> ask(vector <int> T)
{
  printf("%d\n", (int) T.size());
  for (auto it : T)
    printf("%d ", it+1);
  printf("\n");
  fflush(stdout);

  vector <int> R;
  REP(i, n) {
    int x; scanf("%d", &x);
    R.push_back(x);
  }

  return R;
}

void pitaj(int bt, int val)
{
  vector <int> T;
  REP(i, n)
    if ((i >> bt & 1) == val)
      T.push_back(i);

  if (T.empty()) return;
  auto R = ask(T);

  REP(i, n)
    if ((i >> bt & 1) != val)
      rje[i] = min(rje[i], R[i]);
}

int main()
{
  memset(rje, 0x3f, sizeof rje);

  scanf("%d", &n);
  REP(i, 10)
    REP(j, 2)
      pitaj(i, j);

  printf("-1\n");
  REP(i, n)
    printf("%d ", rje[i]);
  printf("\n");
  fflush(stdout);

  return 0;
}