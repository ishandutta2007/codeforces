#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int mlen = (int)1e6 + 10;

char s[mlen];
int b[mlen], n[mlen];
int c;

void read( int *a )
{
  int len = 0;
  scanf(" ");
  while (isdigit(s[len] = getc(stdin)))
    len++;
  forn(i, len)
    a[len - i - 1] = s[i] - '0';
}

void dec( int *a )
{
  a[0]--;
  for (int i = 0; a[i] < 0; i++)
  {
    //assert(i < mlen);
    a[i] += 10, a[i + 1]--;
  }
}

int mod( int *a, int c )
{
  int r = 0;
  for (int i = mlen - 1; i >= 0; i--)
    r = ((ll)r * 10 + a[i]) % c;
  return r;
}

int Phi( int c )
{
  int r = 1;
  for (int i = 2; i * i <= c; i++)
  {  
    //assert(i <= 32000 && c != 0 && i != 1);
    if (c % i == 0)
    {
      c /= i, r *= i - 1;
      while (c % i == 0)
        c /= i, r *= i;
    }
  }
  if (c > 1)
    r *= c - 1;
  return r;
}

const int inf = (int)1e8;

int val( int *a )
{
  int r = 0;
  for (int i = mlen - 1; i >= 0; i--)
    r = min(inf, r * 10 + a[i]);
  return r;
}

int Mul( int a, int b )
{
  return ((ll)a * b) % c;
}

int Pow( int a, int b)
{
  int r = 1, cnt = 0;
  while (b)
  {
    //assert(++cnt < 100);
    if (b & 1)
      r = Mul(r, a);
    a = Mul(a, a);
    b >>= 1;
  }
  return r;
}

int gcd( int a, int b )
{
  return b ? gcd(b, a % b) : a;
}

int main()
{
  read(b);
  read(n);
  scanf("%d", &c);

  int x, y, z, phi;
  x = mod(b, c);
  dec(b), y = mod(b, c);
  dec(n), z = mod(n, phi = Phi(c));
  assert(phi > 0);
  if (gcd(x, c) != 1)
  {
    int t = val(n);
    if (t < inf)
      z = t;
    else 
      while (z < (int)1e7)
        z += phi;
  }

  //printf("x=%d y=%d z=%d\n", x, y, z);

  int res = Mul(y, Pow(x, z));
  if (!res)
    res = c;
  printf("%d\n", res);
  return 0;
}