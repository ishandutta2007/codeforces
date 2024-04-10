#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    string s;
    cin >> n >> s;
    bool allequal = 1;
    for(int i = 1; i < n; i++)
    {
      if(s[i] != s[0])
      {
        allequal = 0;
      }
    }
    if(allequal)
    {
      cout << "0\n";
    }
    else
    {
      int p = 0;
      int res;
      while(s[p] != '>')
      {
        p++;
      }
      res = p;
      p = n - 1;
      while(s[p] != '<')
      {
        p--;
      }
      res = min(res, n - 1 - p);
      cout << res << "\n";
    }
  }
}