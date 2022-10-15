#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r = 0;
  cin >> n;
  for(int i = 2; i < n; i++)
  {
    r += i * (i + 1);
  }
  cout << r << "\n";
}