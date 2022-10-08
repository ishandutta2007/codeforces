/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.16
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int MOD = (int)1e9 + 9;

typedef int matrix[2][2];

matrix a, e, tmp;

void add( int &a, int b )
{
  if ((a += b) >= MOD)
    a -= MOD;
}

int mul( int a, int b )
{
  return ((ll)a * b) % MOD;
}

void out( matrix a )
{
  forn(i, 2)
    forn(j, 2)
      printf("%d%c", a[i][j], " \n"[j ==1]);
}

void mul( matrix a, matrix b )
{
  memset(tmp, 0, sizeof(tmp));
  forn(i, 2)
    forn(j, 2)
      forn(k, 2)
        add(tmp[i][j], mul(a[i][k], b[k][j]));
  memcpy(a, tmp, sizeof(tmp));
}

void getPow( int m )
{
  while (m)
  {
    if (m & 1)
      mul(e, a);
    mul(a, a);
    m >>= 1;
  }
}

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int r = n % k, q = n / k;
  m -= q * (k - 1) + r;
  if (m <= 0)
    printf("%d\n", q * (k - 1) + r + m);
  else
  {
    //puts("do it!");
    //printf("m = %d,  k = %d, add = %d\n", m, k, (q - m) * (k - 1) + r);
    a[0][0] = 2, a[0][1] = mul(2, k);
    a[1][0] = 0, a[1][1] = 1;
    e[0][0] = e[1][1] = 1;
    //out(a);
    getPow(m);
    //out(e);
    int ans = e[0][1];
/*
    ans = 0;
    forn(i, m)
      ans = (((ans + k) % MOD) * 2) % MOD;
*/
    add(ans, (q - m) * (k - 1) + r);
    printf("%d\n", ans);
  }
  return 0;
}