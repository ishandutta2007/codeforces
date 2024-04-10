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

int lens, lent;
char s[MAX], t[MAX];
int per[MAX];
int ima[MAX];

int moze(int x)
{
  memset(ima, 0, sizeof ima);
  REP(i, x) ima[per[i]] = 1;

  for (int i=0, j=0; i<lens; i++) {
    if (!ima[i] && s[i] == t[j]) j++;
    if (j == lent) return 1;
  }

  return 0;
}

int main()
{
  scanf("%s%s", s, t);
  lens = (int) strlen(s);
  lent = (int) strlen(t);
  
  REP(i, lens) {
    int x;
    scanf("%d", &x); x--;
    per[i] = x;
  }
  
  int lo = 0, hi = lens;
  for (; lo < hi; ) {
    int mid = (lo + hi + 1) / 2;
    if (moze(mid))
      lo = mid;
    else
      hi = mid - 1;
  }

  printf("%d\n", lo);

  return 0;
}