#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAXN = 50100;
const int MAXV = MAXN * 32;

int bio[MAXV];
int rje[MAXN];
vector <int> T;
vector <P> V[MAXN];
int p[MAXN];
int n;

int Moze(int x)
{
  memset(bio, 0, sizeof bio);

  for (int i=0; i<n; i++) {
    int da = 0;
    for (int j=0; j<(int) V[i].size(); j++) {
      if (V[i][j].X > x)
        continue;

      if (!bio[V[i][j].Y]) {
        rje[i] = V[i][j].X;
        bio[V[i][j].Y] = 1;
        da = 1;
        break;
      }
    }

    if (!da)
      return 0;
  }

  return 1;
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    for (int tmp = p[i]; tmp; tmp /= 2) {
      V[i].push_back(P(tmp, 0));
      T.push_back(tmp);
    }
  }

  sort(T.begin(), T.end());
  T.resize(unique(T.begin(), T.end()) - T.begin());

  for (int i=0; i<n; i++)
    for (int j=0; j<(int) V[i].size(); j++)
      V[i][j].Y = lower_bound(T.begin(), T.end(), V[i][j].X) - T.begin();

  int lo = 0, hi = 1<<30;

  for (; lo<hi; ) {
    int mid = (lo + hi) / 2;
    if (Moze(mid))
      hi = mid;
    else
      lo = mid + 1;
  }

  Moze(lo);
  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}