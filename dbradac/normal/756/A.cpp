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

const int MAX = 1<<19;

int p[MAX];
int b[MAX];
int bio[MAX];
int n;

int brcik()
{
  int ret = 0;
  REP(i, n) {
    if (bio[i]) continue;
    int sz = 0;
    for (int tmp=i; tmp != i || !sz; tmp = p[tmp], sz++)
      bio[tmp] = 1;
    ret++;
  }

  return ret;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) { scanf("%d", &p[i]); p[i]--; }
  int imab = 0;
  REP(i, n) { scanf("%d", &b[i]); imab ^= b[i]; }

  int ret = 1 - imab;
  int tmp = brcik();
  if (tmp > 1) ret += tmp;

  printf("%d\n", ret);

  return 0;
}