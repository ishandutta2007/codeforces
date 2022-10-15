#include <bits/stdc++.h>

using namespace std;

string sort_str(string s)
{
  sort(s.begin(), s.end());
  return s;
}

vector<int> v, ret;

void op(int len)
{
  if (!len)
  {
    return;
  }
  assert(1 <= len && len <= (int) v.size());
  ret.push_back(len);
  vector<int> alpha, beta;
  for (int i = 0; i < (int) v.size() - len; i++)
  {
    alpha.push_back(v[i]);
  }
  for (int i = (int) v.size() - len; i < (int) v.size(); i++)
  {
    beta.push_back(v[i]);
  }
  reverse(beta.begin(), beta.end());
  v = beta;
  for (auto &x : alpha)
  {
    v.push_back(x);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s, t;
  int n;
  cin >> n >> s >> t;

  if (sort_str(s) != sort_str(t))
  {
    cout << "-1\n";
    return 0;
  }
  vector<bool> taken(n, 0);
  for (int i = 0; i < n; i++)
  {
    int pos = -1;
    for (int j = 0; j < n; j++)
    {
      if (s[i] == t[j] && !taken[j])
      {
        pos = j;
        break;
      }
    }
    assert(pos != -1);
    taken[pos] = 1;
    v.push_back(pos);
  }
  for (int i = 0; i < n; i++)
  {
    if (v[i] == 0)
    {
      op(n - i - 1);
      break;
    }
  }
  for (int l = 2; l <= n; l++)
  {
    for (int i = 0; i < n; i++)
    {
      if (v[i] == l - 1)
      {
        op(n - i - 1);
        break;
      }
    }
    op(1);
    op(n);
  }
  cout << (int) ret.size() << "\n";
  for (auto &i : ret)
  {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}