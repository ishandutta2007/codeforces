#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
const int INF = (int) 1e9;

void place(string &s, int len)
{
  while ((int) s.size() < len)
  {
    s += "0";
  }
  assert((int) s.size() == len);
}

int len, n, cls[N][N], dp[N][N], ini, cost[11], kek[N];
string a, b[N];
vector<int> nums[N];
int what[N];
int fr[22];
int fr2[22];

string num[N];

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> a >> n;
  reverse(a.begin(), a.end());
  len = (int) a.size() + 1;
  ini = (int) a.size();
  for (int i = 1; i <= n; i++)
  {
    cin >> b[i];
    kek[i] = (int) b[i].size();
    reverse(b[i].begin(), b[i].end());
    len = max(len, (int) b[i].size());
  }
  for (int x = 0; x <= 9; x++)
  {
    cin >> cost[x];
  }
  place(a, len);
  for (int i = 1; i <= n; i++)
  {
    place(b[i], len);
  }
  for (int i = 1; i <= n; i++)
  {
    nums[0].push_back(i);
  }
  for (int pos = 1; pos <= len; pos++)
  {
    vector<pair<pair<int, int>, int>> v;
    for (int i = 1; i <= n; i++)
    {
      v.push_back({{b[i][pos - 1] - '0', cls[pos - 1][i]}, i});
    }
    sort(v.begin(), v.end());
    int y = 1;
    cls[pos][v[0].second] = y;
    for (int i = 1; i < n; i++)
    {
      y += (v[i - 1].first != v[i].first);
      cls[pos][v[i].second] = y;
    }
    for (auto &it : v)
    {
      nums[pos].push_back(it.second);
    }
    reverse(nums[pos].begin(), nums[pos].end());
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for (int pos = 0; pos < len; pos++)
  {
    int lo, hi;
    if (a[pos] == '?')
    {
      lo = (pos == ini - 1), hi = 9;
    }
    else
    {
      lo = hi = a[pos] - '0';
    }
    for (int x = 0; x <= 20; x++)
    {
      fr[x] = 0;
      fr2[x] = 0;
    }
    vector<int> carry;
    for (int i = 1; i <= n; i++)
    {
      what[i] = b[i][pos] - '0';
      fr[what[i]]++;
      if (pos < max(ini, kek[i]))
      {
        fr2[what[i]]++;
      }
    }
    for (int i = 0; i <= n; i++)
    {
      if (i)
      {
        fr[what[nums[pos][i - 1]]]--;
        if (pos < max(ini, kek[nums[pos][i - 1]]))
        {
          fr2[what[nums[pos][i - 1]]]--;
        }
        what[nums[pos][i - 1]]++;
        carry.push_back(nums[pos][i - 1]);
        fr[what[nums[pos][i - 1]]]++;
        if (pos < max(ini, kek[nums[pos][i - 1]]))
        {
          fr2[what[nums[pos][i - 1]]]++;
        }
      }
      if (dp[pos][i] != -INF)
      {
        for (int d = lo; d <= hi; d++)
        {
          int relax = dp[pos][i];
          int cnt = 0;
          for (int w = 0; w <= 20; w++)
          {
            int cf = ((w + d) % 10 == 0) ? fr2[w] : fr[w];
            cnt += cf * ((w + d) >= 10);
            relax += cf * cost[(w + d) % 10];
          }
          dp[pos + 1][cnt] = max(dp[pos + 1][cnt], relax);
        }
      }
    }
  }
  int sol = -INF;
  for (int i = 0; i <= n; i++)
  {
    sol = max(sol, dp[len][i]);
  }
  cout << sol << "\n";
  return 0;
}