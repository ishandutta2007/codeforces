#include <bits/stdc++.h>

using namespace std;

int main()
{
  //freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    string s, t;
    cin >> n >> s;
    for (auto &ch : s)
    {
      while (!t.empty() && t.back() == ch)
      {
        t.pop_back();
      }
      t += ch;
    }
    sort(t.begin(), t.end());
    bool good = 1;
    for (int i = 1; i < (int) t.size(); i++)
    {
      if (t[i] == t[i - 1])
      {
        good = 0;
      }
    }
    if (good)
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }
  return 0;
}