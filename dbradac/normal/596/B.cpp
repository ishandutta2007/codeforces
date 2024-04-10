#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX = 1<<18;

int p[MAX];

int main()
{
  int n;
  
  scanf("%d", &n);

  ll prom = 0, rje = 0;
  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    rje += abs(prom - (ll) tmp);
    prom = tmp;
  }

  cout << rje;

  return 0;
}