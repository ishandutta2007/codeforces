#include <bits/stdc++.h>

using namespace std;

struct SegTree_Max
{
  const int INF = (int) 2e9 + 100;
  vector <int> t;
  int len;

  void init(int __len)
  {
    len = __len;
    t.resize(4 * len + 1);
    for (int i = 0; i < 4 * len + 1; i++) t[i] = -INF;
  }

  void upd(int v, int tl, int tr, int p, int x)
  {
    if (tr < p || p < tl) return;
    if (tl == tr)
      t[v] = x;
    else
    {
      int tm = (tl + tr) / 2;
      upd(2 * v, tl, tm, p, x);
      upd(2 * v + 1, tm + 1, tr, p, x);
      t[v] = max(t[2 * v], t[2 * v + 1]);
    }
  }

  int get(int v, int tl, int tr, int l, int r)
  {
    if (r < tl || tr < l) return -INF;
    if (l <= tl && tr <= r)
      return t[v];
    else
    {
      int tm = (tl + tr) / 2;
      return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
  }

  void upd(int p, int x)
  {
    upd(1, 1, len, p, x);
  }

  int get(int l, int r)
  {
    return get(1, 1, len, l, r);
  }

};


struct SegTree_Min
{
  const int INF = (int) 2e9 + 100;
  vector <int> t;
  int len;

  void init(int __len)
  {
    len = __len;
    t.resize(4 * len + 1);
    for (int i = 0; i < 4 * len + 1; i++) t[i] = +INF;
  }

  void upd(int v, int tl, int tr, int p, int x)
  {
    if (tr < p || p < tl) return;
    if (tl == tr)
      t[v] = x;
    else
    {
      int tm = (tl + tr) / 2;
      upd(2 * v, tl, tm, p, x);
      upd(2 * v + 1, tm + 1, tr, p, x);
      t[v] = min(t[2 * v], t[2 * v + 1]);
    }
  }

  int get(int v, int tl, int tr, int l, int r)
  {
    if (r < tl || tr < l) return +INF;
    if (l <= tl && tr <= r)
      return t[v];
    else
    {
      int tm = (tl + tr) / 2;
      return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
  }

  void upd(int p, int x)
  {
    upd(1, 1, len, p, x);
  }

  int get(int l, int r)
  {
    return get(1, 1, len, l, r);
  }

};

const int N = (int) 1e5 + 7;
int a[N];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, maxDif, len;
  cin >> n >> maxDif >> len;
  for (int i = 1; i <= n; i++) cin >> a[i];
  SegTree_Max mx;
  SegTree_Min mn;
  mx.init(n);
  mn.init(n);

  for (int i = 1; i <= n; i++) mn.upd(i, a[i]);
  for (int i = 1; i <= n; i++) mx.upd(i, a[i]);

  SegTree_Min dp;
  dp.init(n);

  const int INF = (int) 1e9;

  for (int i = 1; i <= n; i++)
  {
    int lo = 1, hi = i, pos;
    while (lo <= hi)
    {
      int mid = (lo + hi) / 2;
      int Dif = mx.get(mid, i) - mn.get(mid, i);
      if (Dif <= maxDif)
      {
        pos = mid;
        hi = mid - 1;
      }
      else
        lo = mid + 1;
    }
    int St = pos, Dr = i - len + 1;
    int now_dp;
    if (St > Dr)
      now_dp = INF;
    else
    {
      if (St == 1)
        now_dp = 1;
      else
        now_dp = dp.get(St - 1, Dr - 1) + 1;
    }
    dp.upd(i, now_dp);
  }
  
  int now_dp = dp.get(n, n);
  if (now_dp >= INF)
    cout << "-1\n";
  else
    cout << now_dp << "\n";


  return 0;
}