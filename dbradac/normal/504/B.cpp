#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 200005, TOUR = 1<<18;

int sum[MAX];
int fen[MAX];
int rje[MAX];
int t[2*TOUR];
int p[2][MAX];
int n;

void StaviF(int pos, int val)
{
  for (pos++; pos<MAX; pos += pos & -pos)
    fen[pos] += val;
}

int VratiF(int pos)
{
  int r=0;

  for (pos++; pos; pos -= pos & -pos)
    r += fen[pos];
  return r;
}

void StaviT(int pos, int val)
{
  for (t[pos+TOUR] += val, pos = (pos + TOUR) / 2; pos; pos /= 2)
    t[pos] = t[2*pos] + t[2*pos+1];
}

int VratiT(int pos, int lo, int hi, int k)
{
  if (lo == hi - 1)
    return pos - TOUR;
  if (t[2*pos] < k)
    return VratiT(2*pos+1, (lo+hi)/2, hi, k - t[2*pos]);
  return VratiT(2*pos, lo, (lo+hi)/2, k);
}

void Sumiraj(int a[MAX])
{
  memset(fen, 0, sizeof fen);

  for (int i=0; i<n; i++) {
    int k = a[i] - VratiF(a[i]);
    sum[i] += k;
    StaviF(a[i], 1);
  }
}

void Rjesenje()
{
  for (int i=n-1, dalje=0; i>=0; i--) {
    int tmp = sum[i] + dalje;
    dalje = tmp / (n - i);
    sum[i] = tmp % (n - i);
  }

  for (int i=0; i<n; i++)
    StaviT(i, 1);

  for (int i=0; i<n; i++) {
    rje[i] = VratiT(1, 0, TOUR, sum[i]+1);
    StaviT(rje[i], -1);
  }
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<2; i++) {
    for (int j=0; j<n; j++)
      scanf("%d", &p[i][j]);
    Sumiraj(p[i]);
  }

  Rjesenje();

  for (int i=0; i<n; i++)
    printf("%d ", rje[i]);
  printf("\n");

  return 0;
}