#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  k--;
  vector <pair <int, int>> v(n);
  for(int i = 0; i < n; i++)
  {
    int t, b;
    cin >> t >> b;
    v[i] = {b, t};
  }
  sort(v.rbegin(), v.rend());
  ll res = 0LL;
  ll curt = 0LL;
  multiset <int> s;
  for(auto &it : v)
  {
    int t = it.second;
    int b = it.first;
    res = max(res, b * (ll)(t + curt));
    curt += t;
    s.insert(t);
    while(s.size() > k)
    {
      curt -= *s.begin();
      s.erase(s.begin());
    }
  }
  cout << res << "\n";
}