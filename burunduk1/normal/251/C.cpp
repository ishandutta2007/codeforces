/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.12.06
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int L = 360360;

int u[L];
ll x[L], cnt[L];
ll a, b, res = 0;
int k;

void makeMove()
{
  int opt = 1;
  for (int i = 2; i <= k; i++)
  {
    int r = a % i;
    if (a - r >= b && r > opt)
      opt = r;
  }
  a -= opt, res++;
  //printf("opt = %d\n", opt);
}

int main()
{
  while (cin >> a >> b >> k)
  {
    res = 0;
    memset(u, 0, sizeof(u));

    while (a > b + 15 * L)
    {
      int st = a % L;
      if (!u[st])
      {
        u[st] = 1, x[st] = a, cnt[st] = res;
        makeMove();
      }
      else
      {
        ll da = x[st] - a;
        ll dres = res - cnt[st];
        ll num = (a - b) / da;
        //printf("da = %I64d, dres = %I64d, num = %I64d\n", da, dres, num);
        a -= da * num;
        res += dres * num;
        //printf("a = %I64d, res = %I64d\n", a, res);
      }
    }
    while (a > b)
      makeMove();
    cout << res << endl;
  }

/*
  int lca = 1;
  for (int i = 2; i <= k; i++)
    lca = lca * (i / __gcd(lca, i));
  printf("lca = %d\n", lca);
*/
  return 0;
}