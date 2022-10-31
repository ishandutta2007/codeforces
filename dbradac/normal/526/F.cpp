#include <cstdio>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 300100;

int p[MAX];
int minn[MAX], maxx[MAX];
int ima[2*MAX];
int poz[MAX];
vector <int> V[MAX];
vector <P> T;
ll rje;

void Rijesi(int lo, int mid, int hi) //mid je lijevo
{
  minn[mid] = maxx[mid] = p[mid];
  for (int i=mid-1; i>=lo; i--) {
    minn[i] = min(minn[i+1], p[i]);
    maxx[i] = max(maxx[i+1], p[i]);
  }
  
  minn[mid+1] = maxx[mid+1] = p[mid+1];
  for (int i=mid+2; i<=hi; i++) {
    minn[i] = min(minn[i-1], p[i]);
    maxx[i] = max(maxx[i-1], p[i]);
  }

  T.clear();

  for (int i=lo; i<=mid; i++) {
    poz[i] = maxx[i] - minn[i] + i;
    if (poz[i] <= hi && poz[i] > mid && minn[poz[i]] > minn[i] && maxx[poz[i]] < maxx[i])
      rje++;

    if (poz[i] + 1 <= hi && poz[i] + 1 > mid)
      T.push_back(P(minn[i], i));
  }
  
  int tind = 0;
  for (int i=hi; i>mid; i--) {
    for (; tind < (int) T.size() && T[tind].X < minn[i]; tind++) {
      if (poz[T[tind].Y] + 1 <= i) {
        V[poz[T[tind].Y] + 1].push_back(T[tind].Y - T[tind].X);
        rje -= ima[MAX + T[tind].Y - T[tind].X];
      }
    }

    ima[MAX + i - maxx[i]]++;
    for (int j=0; j<(int) V[i].size(); j++)
      rje += ima[V[i][j] + MAX];
  }

  for (int i=hi; i>mid; i--) {
    ima[MAX + i - maxx[i]]--;
    V[i].clear();
  }
}

void Mirror(int lo, int hi)
{
  for (int i=0; i<(hi-lo+1) / 2; i++)
    swap(p[lo+i], p[hi-i]);
}

void Rek(int lo, int hi)
{
  if (lo == hi) {
    rje++;
    return;
  }
  
  int mid = (lo + hi) / 2;
  Rijesi(lo, mid, hi);
  Mirror(lo, hi);
  if ((lo + hi) & 1)
    Rijesi(lo, mid, hi);
  else
    Rijesi(lo, mid-1, hi);
  Mirror(lo, hi);

  Rek(lo, mid);
  Rek(mid+1, hi);
}

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    int r, c;
    scanf("%d%d", &r, &c); r--; c--;
    p[r] = c;
  }

  Rek(0, n-1);
  printf("%I64d\n", rje);

  return 0;
}