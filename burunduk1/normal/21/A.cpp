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

int n = 0;
char s[(int)1e6 + 10];

void Fail()
{
  puts("NO");
  exit(0);
}

int Good( char ch )
{
  return isdigit(ch) || isalpha(ch) || ch == '_';
}

int SkipName()
{
  int len = 0;
  while (Good(s[n]))
    n++, len++;
  if (!(1 <= len && len <= 16))
    Fail();
  return len;
}

void Skip( char ch )
{
  if (s[n] != ch)
    Fail();
  n++;
}

void SkipHost()
{
  int sum = SkipName();
  while (s[n] == '.')
  {
    sum++, n++;
    sum += SkipName();
  }
  if (!(1 <= sum && sum <= 32))
    Fail();
}

int main()
{
  gets(s);
  SkipName();
  Skip('@');
  SkipHost();
  if (s[n] == '/')
  {
    Skip('/');
    SkipName();
  }
  Skip(0);
  puts("YES");
  return 0;
}