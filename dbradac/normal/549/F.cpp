#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 300100, MAX = 1000100;

int n, k;
int p[MAXN];
int maxx[MAXN];
int imal[MAX], imar[MAX];
ll pref[MAXN];
ll rje=0;

int Sum(int l, int r)
{
  return (int) ((pref[r] - pref[l-1]) % k);
}

void Rek(int lo, int hi)
{
  if (lo >= hi)
    return;

  int mid = (lo + hi) / 2;
  
  maxx[mid] = p[mid];
  for (int i=mid-1; i>=lo; i--)
    maxx[i] = max(maxx[i+1], p[i]);

  maxx[mid+1] = p[mid+1];
  for (int i=mid+2; i<=hi; i++)
    maxx[i] = max(maxx[i-1], p[i]);

  int l = mid, r = mid + 1, tmax = 0;
  for (; l >= lo || r <= hi; ) {
    if (r > hi || (l >= lo && maxx[l] < maxx[r])) {
      tmax = max(tmax, maxx[l]);
      int sum = Sum(l, mid);
      rje += imar[(tmax - sum + k) % k];
      imal[sum]++;
      l--;
    }
    else {
      tmax = max(tmax, maxx[r]);
      int sum = Sum(mid + 1, r);
      rje += imal[(tmax - sum + k) % k];
      imar[sum]++;
      r++;
    }
  }
  
  for (int i=lo; i<=mid; i++)
    imal[Sum(i, mid)]--;

  for (int i=mid+1; i<=hi; i++)
    imar[Sum(mid+1, i)]--;

  Rek(lo, mid);
  Rek(mid+1, hi);
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=1; i<=n; i++) {
    scanf("%d", &p[i]);
    pref[i] = pref[i-1] + p[i];
  }

  Rek(1, n);
  cout << rje << endl;

  return 0;
}