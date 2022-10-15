#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int add(int a, int b)
{
  a += b;
  if(a >= MOD)
  {
    a -= MOD;
  }
  if(a < 0)
  {
    a += MOD;
  }
  return a;
}

int mul(int a, int b)
{
  return a * (long long)b % MOD;
}

int expow(int a, int b)
{
  int r = 1;
  while(b)
  {
    if(b & 1)
    {
      r = mul(r, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}

const int N = (int)2e5 + 7;
int dp[N][2]; /// dp[len][(v[i]==first)]

int dv(int a, int b)
{
  return mul(a, expow(b, MOD - 2));
}

int get(vector<int>v, int k)
{
  int n = v.size();
  for(int i = 1; i < n; i++)
  {
    if(v[i] != -1 && v[i] == v[i - 1])
    {
      return 0;
    }
  }
  /// all -1
  bool all = 1;
  for(auto &x : v)
  {
    if(x != -1)
    {
      all = 0;
    }
  }
  if(all)
  {
    return mul(k, expow(k - 1, n - 1));
  }
  vector<int>pivot;
  pivot.push_back(-1);
  for(int i = 0; i < n; i++)
  {
    if(v[i] != -1)
    {
      pivot.push_back(i);
    }
  }
  pivot.push_back(n);
  int res = 1;
  for(int i = 0; i + 1 < pivot.size(); i++)
  {
    int st = pivot[i] + 1;
    int dr = pivot[i + 1] - 1;
    if(st > dr) continue;
    int len = dr - st + 1;
    int cur;
    if(st == 0)
    {
      cur = add(dp[len][0], dp[len][1]);
    }
    if(dr == n - 1)
    {
      cur = add(dp[len][0], dp[len][1]);
    }
    if(st > 0 && dr < n - 1)
    {
      int x = v[st - 1];
      int y = v[dr + 1];
      if(x != y)
      {
        cur = add(dp[len][1], mul(dv(k - 2, k - 1), dp[len][0]));
      }
      else
      {
        cur = dp[len][0];
      }
    }
    res = mul(res, cur);
  }
  return res;
}

int n, k;

vector<int>a[2];

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
  {
    int x;
    cin >> x;
    a[i % 2].push_back(x);
  }
  /// let's build DP
  dp[1][0] = k - 1;
  for(int i = 2; i < N; i++)
  {
    dp[i][1] = dp[i - 1][0];
    dp[i][0] = add(expow(k - 1, i), -dp[i][1]);
  }
  cout << mul(get(a[0], k), get(a[1], k)) << "\n";
  return 0;
}