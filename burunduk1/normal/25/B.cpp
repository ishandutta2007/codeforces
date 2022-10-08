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

const int maxn = 103;

int n, i = 0;
char s[maxn];

string substr( int i, int len )
{
  return string(s + i).substr(0, len);
}

int main()
{
  scanf("%d%s", &n, s);
  while (n >= 5)
  {
    printf("%s-", substr(i, 3).c_str());
    n -= 3, i += 3;
  }
  if (n == 4)
    printf("%s-%s\n", substr(i, 2).c_str(), substr(i + 2, 2).c_str());
  else
    printf("%s\n", s + i);
  return 0;
}