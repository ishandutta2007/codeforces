/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.03
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define all(a) (a).begin(), (a).end()

typedef vector <int> vi;

const int N = (int)5e4 + 1;
const int L = 51;

char s[N], p[L][N];
int ri, rj, n, f[L][N];
vi a[26];

void relax( int i, int j, int F, int P )
{
  if (f[i][j] > F && F <= n)
  {
    ri = i, rj = j;
    f[i][j] = F, p[i][j] = P;
  }
}

string solve( int t )
{
  ri = 0, rj = 0;
  memset(f, 0x30, sizeof(f));
  forn(j, n + 1)
    f[0][j] = j + t;
  forn(i, L - 1 - t)
  {
    fornd(j, n)
      relax(i, j, f[i][j + 1], 0);
    forn(j, n)
      if (f[i][j + 1] <= n)
      {
        vi &v = a[s[j] - 'a'];
        relax(i + 1, j, *lower_bound(all(v), f[i][j + 1]) + 1, 1);
      }
  }

  string res = "";
  while (ri > 0)
  {
    while (rj < n && p[ri][rj] != 1)
      rj++;
    res += s[rj], ri--, rj++;
  }
  string rev = res;
  reverse(all(rev));
  if (t)
    res += s[rj];
  return res += rev;
}

int main()
{
  gets(s);
  n = strlen(s);
  forn(i, n)
    a[s[i] - 'a'].pb(i);
  forn(i, 26)
    a[i].pb(n);

  string a = solve(0), b = solve(1);
  cout << (a.size() > b.size() ? a : b) << endl;
  return 0;
}