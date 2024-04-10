#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
    v[i]--;
  }
  int r = 0;
  for(int i = 0; i < n;)
  {
    r++;
    int End = v[i];
    for(int j = i; j <= End; j++)
    {
      End = max(End, v[j]);
      i = j + 1;
    }
  }
  cout << r << "\n";
}