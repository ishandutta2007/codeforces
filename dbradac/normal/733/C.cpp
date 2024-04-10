#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 505;

int p[MAX], pref[MAX], kraj[MAX];
int n;
vector <P> R;

void nope()
{
  printf("NO\n");
  exit(0);
}

void ajde(int l, int r)
{
  int mx = -1, ind = l;
  if (l == r)
    return;

  FOR(i, l, r + 1) {
    if (p[i] > mx) {
      mx = p[i];
      ind = i;
    }
    if ((p[i] == mx) &&
        ((i - 1 >= l && p[i] > p[i-1]) ||
         (i + 1 <= r && p[i] > p[i+1]))) {
      ind = i;
    }
  }

  int da = 0;
  FOR(i, l, r + 1)
    if (p[i] != mx)
      da = 1;

  if (!da)
    nope();

  if (r == ind || (ind < r && p[ind] > p[ind+1])) {
    REP(i, r-ind)
      R.push_back(P(ind, 1));

    for (; ind > l; ind--)
      R.push_back(P(ind, 0));
  }
  else {
    for (; ind > l; ind--, r--)
      R.push_back(P(ind, 0));

    REP(i, r-ind)
      R.push_back(P(ind, 1));
  }
}

int main()
{
  int m;

  scanf("%d", &n);
  FOR(i, 1, n+1) {
    scanf("%d", &p[i]);
    pref[i] = pref[i-1] + p[i];
  }

  scanf("%d", &m);
  REP(i, m)
    scanf("%d", &kraj[i]);

  int des = n;
  for (int i=m-1; i>=0; i--) {
    int da = 0;
    for (int j=des; j; j--) {
      if (pref[des] - pref[j-1] == kraj[i]) {
        da = 1;
        ajde(j, des);
        des = j - 1;
        break;
      }
    }

    if (!da)
      nope();
  }
  if (des)
    nope();

  printf("YES\n");
  for (auto it : R)
    printf("%d %c\n", it.X, it.Y ? 'R' : 'L');

  return 0;
}