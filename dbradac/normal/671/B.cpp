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

const int MAX = 1<<19, INF = 0x3f3f3f3f;

int p[MAX];
int n, k;
ll sum = 0;

ll KolkoPreko(int x)
{
  ll ret = 0;

  for (int i=0; i<n; i++)
    ret += max(0, p[i] - x);

  return ret;
}

ll KolkoIspod(int x)
{
  ll ret = 0;

  for (int i=0; i<n; i++)
    ret += max(0, x - p[i]);

  return ret;
}

int Max()
{
  int lo = (int) ((sum - 1) / n + 1), hi = INF;

  for (; lo<hi; ) {
    int mid = (lo + hi) / 2;
    if (KolkoPreko(mid) <= k)
      hi = mid;
    else
      lo = mid + 1;
  }

  return lo;
}

int Min()
{
  int lo = 0, hi = (int) (sum / n);

  for (; lo<hi; ) {
    int mid = (lo + hi + 1) / 2;
    if (KolkoIspod(mid) <= k)
      lo = mid;
    else
      hi = mid - 1;
  }

  return lo;
}

int main()
{
  scanf("%d%d", &n, &k);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    sum += p[i];
  }

  printf("%d\n", Max() - Min());

  return 0;
}