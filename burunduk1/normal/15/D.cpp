#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int inf = (int)2e9;
const int maxn = 1 << 10;

int H, W, h, w, a[maxn][maxn];
ll asum[maxn][maxn];
int amin[maxn][maxn];
ll asum2[maxn][maxn];
int amin2[maxn][maxn];
ll f[maxn][maxn];

int tmin[2 * maxn];
ll tsum[2 * maxn];

int c[maxn][maxn];
vector <int> res;

struct Pos
{
  int x, y;

  Pos() { }
  Pos( int _x, int _y ) : x(_x), y(_y) { }
};

int pn = 0;
Pos p[maxn * maxn];

bool operator < ( Pos a, Pos b )
{
  if (f[a.y][a.x] != f[b.y][b.x])
    return f[a.y][a.x] < f[b.y][b.x];
  if (a.y != b.y)
    return a.y < b.y;
  return a.x < b.x;
}

ll Sum( int l, int r )
{
  ll res = 0;
  l += maxn, r += maxn;
  while (l <= r)
  {
    if (l & 1)    res += tsum[l++];
    if (!(r & 1)) res += tsum[r--];
    if (l > r)
      break;
    l >>= 1, r >>= 1;
  }
  return res;
}

int Min( int l, int r )
{
  int res = inf;
  l += maxn, r += maxn;
  while (l <= r)
  {
    if (l & 1)    res = min(res, tmin[l++]);
    if (!(r & 1)) res = min(res, tmin[r--]);
    if (l > r)
      break;
    l >>= 1, r >>= 1;
  }
  return res;
}

void Add( int i, int j )
{
//  printf("add(%d,%d)\n", i, j);
  for (int y = i; y < H; y |= y + 1)
    for (int x = j; x < W; x |= x + 1)
      c[y][x]++;
}

int Get( int i, int j )
{
  int sum = 0;
  for (int y = i; y >= 0; y = (y & (y + 1)) - 1)
    for (int x = j; x >= 0; x = (x & (x + 1)) - 1)
      sum += c[y][x];
  return sum;
}

int main()
{
  scanf("%d%d%d%d", &H, &W, &h, &w);
  forn(i, H)
    forn(j, W)
      scanf("%d", &a[i][j]);
  forn(i, H)
  {
    forn(j, W)
      tmin[j + maxn] = tsum[j + maxn] = a[i][j];
    for (int j = maxn - 1; j > 0; j--)
    {
      tmin[j] = min(tmin[j * 2], tmin[j * 2 + 1]);
      tsum[j] = tsum[j * 2] + tsum[j * 2 + 1];
    }
    forn(j, W - w + 1)
    {
      asum[i][j] = Sum(j, j + w - 1);
      amin[i][j] = Min(j, j + w - 1);
    }
  }
  forn(j, W)
  {
    forn(i, H)
    {
      tmin[i + maxn] = amin[i][j];
      tsum[i + maxn] = asum[i][j];
    }
    for (int i = maxn - 1; i >= 0; i--)
    {
      tmin[i] = min(tmin[i * 2], tmin[i * 2 + 1]);
      tsum[i] = tsum[i * 2] + tsum[i * 2 + 1];
    }
    forn(i, H - h + 1)
    {
      asum2[i][j] = Sum(i, i + h - 1);
      amin2[i][j] = Min(i, i + h - 1);
    }
  }
  forn(i, H - h + 1)
    forn(j, W - w + 1)
    {
      f[i][j] = (ll)asum2[i][j] - (ll)amin2[i][j] * h * w;
      p[pn++] = Pos(j, i);
    }
  sort(p, p + pn);

  forn(j, pn)
  {
    int x = p[j].x - 1, y = p[j].y - 1;
    if (Get(y, x) + Get(y + h, x + w) - Get(y + h, x) - Get(y, x + w) == 0)
    {
      res.push_back(j);
      forn(a, h)
        forn(b, w)
          Add(y + a + 1, x + b + 1);
    }
  }

  printf("%d\n", res.size());
  forn(j, res.size())
  {
    int i = res[j];
    printf("%d %d %I64d\n", p[i].y + 1, p[i].x + 1, f[p[i].y][p[i].x]);
  }
  return 0;
}