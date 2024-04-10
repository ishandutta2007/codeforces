#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 53;
const int mlen = 103;

int n, a[maxn][maxn], b[maxn][maxn];
char name[maxn][mlen], tmp[mlen];
int score[maxn], sDiff[maxn], sA[maxn], p[maxn];

int Find( char *s )
{
  forn(i, n)
    if (strcmp(name[i], s) == 0)
      return i;
  return -1;
}

bool pless( int i, int j )
{
  #define F(score) if (score[i] != score[j]) return score[i] > score[j];
  F(score)
  F(sDiff)
  F(sA)
  return 0;
}

bool sless( int i, int j )
{
  return strcmp(name[i], name[j]) < 0;
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%s", name[i]);
  forn(i, n * (n - 1) / 2)
  {
    scanf("%s", tmp);
    int p = strchr(tmp, '-') - tmp;
    tmp[p] = 0;
    int x = Find(tmp);
    int y = Find(tmp + p + 1);
    int A, B;
    scanf("%d:%d", &A, &B);
    a[x][y] = A, b[x][y] = B;
    a[y][x] = B, b[y][x] = A;
  }

  forn(i, n)
    forn(j, n)
    {
      if (a[i][j] > b[i][j])
        score[i] += 3;
      else if (a[i][j] == b[i][j])
        score[i]++;
      sDiff[i] += a[i][j] - b[i][j];
      sA[i] += a[i][j];
      p[i] = i;
    }
  sort(p, p + n, pless);
  sort(p, p + n / 2, sless);

  forn(i, n / 2)
    puts(name[p[i]]);
  return 0;
}