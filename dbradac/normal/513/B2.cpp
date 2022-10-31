#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

vector <int> V;

int main()
{
  int n;
  ll k;

  cin >> n;
  cin >> k;

  V.push_back(n);
  k--;
  for (int i=n-1; i; i--) {
    if (k & (1ll << ((ll) n-i-1)))
      V.push_back(i);
    else
      V.insert(V.begin(), i);
  }
  
  for (int i=0; i<n; i++)
    printf("%d ", V[i]);

  return 0;
}