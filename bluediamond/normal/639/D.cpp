#include <bits/stdc++.h>;I am the coolest guy in the Universe, I am Blue Diamond

using namespace std;

#define int long long

int get_ant(int x, int r)
{
  while (x % 5 != r)
  {
    x--;
  }
  return x;
}


const int N = (int) 2e5 + 7;
int n, k, b, c, a[N], sol = (int) 1e18, specif[5];
vector<int> id[5];
set<int> test[5];

deque<int> act[5];
int cnt, CUR;

int eval(int val)
{
  val = CUR - val;
  return (val / 5) * b + (val % 5) * c;
}

int complete()
{
  int sol = 0;
  for (int r = 0; r < 5; r++)
  {
    int val = get_ant(CUR, r);
    sol += val * b * (int) act[r].size();
    sol -= specif[r];
  }
  sol /= 5;
  for (int r = 0; r < 5; r++)
  {
    sol += ((CUR - r) % 5) * c * (int) act[r].size();
  }
  return sol;
}

void ins(int p)
{
  act[a[p] % 5].push_back(a[p]);
  specif[a[p] % 5] += a[p] * b;
  cnt++;

  if (cnt == k + 1)
  {
    cnt--;
    vector<pair<int, int>> possible;
    for (int r = 0; r < 5; r++)
    {
      if (!act[r].empty())
      {
        possible.push_back({eval(act[r].front()), r});
      }
    }
    sort(possible.rbegin(), possible.rend());
    assert(!possible.empty());
    specif[possible[0].second] -= act[possible[0].second].front() * b;
    act[possible[0].second].pop_front();
  }
}

signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k >> b >> c;
  b = min(b, 5 * c);
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += (int) 1e9 + 7;
  }
  sort(a + 1, a + n + 1);
  set<int> want;
  for (int i = 1; i <= n; i++)
  {
    want.insert(a[i]);
    want.insert(a[i] + 1);
    want.insert(a[i] + 2);
    want.insert(a[i] + 3);
    want.insert(a[i] + 4);
  }
  for (auto &x : want)
  {
    test[x % 5].insert(x);
  }
  int sol = (int) 1e18;
  for (int q = 0; q < 5; q++)
  {
    cnt = 0;
    for (int r = 0; r < 5; r++)
    {
      specif[r] = 0;
      act[r].clear();
    }
    int p = 1;
    for (auto &x : test[q])
    {
      CUR = x;
      while (p <= n && a[p] <= x)
      {
        ins(p++);
      }
      if (cnt == k)
      {
        sol = min(sol, complete());
      }
    }
  }
  cout << sol << "\n";
  return 0;
}