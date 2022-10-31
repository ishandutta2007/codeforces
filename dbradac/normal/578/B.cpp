#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAX = 200100;

ll p[MAX];
int kol[MAX];
int n, k, x;

ll Eval(int ind)
{
  ll tmp=p[ind];

  for (int i=0; i<k; i++)
    tmp *= x;

  ll ret = tmp;

  for (int i=0; i<30; i++)
    if (kol[i] > 1 || (kol[i] == 1 && !((1<<i) & p[ind])))
      ret |= (1<<i);
  
  return ret;
}

int main()
{
  scanf("%d%d%d", &n, &k, &x);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d", &tmp);
    p[i] = tmp;
    for (int j=0; j<30; j++)
      if ((1<<j) & p[i])
        kol[j]++;
  }

  ll rje=0;

  for (int i=0; i<n; i++)
    rje = max(rje, Eval(i));

  cout << rje << endl;

  return 0;
}