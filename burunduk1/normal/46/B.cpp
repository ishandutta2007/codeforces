/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

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

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }

int main()
{
  int k, n[5];
  forn(i, 5)
    scanf("%d", &n[i]);
  scanf("%d", &k);
  forn(i, k)
  {
    const char *str[] = {"S", "M", "L", "XL", "XXL"};
    char s[9];
    scanf("%s", s);
    int i = 0;
//    printf("s = %s\n", s);
    while (strcmp(str[i], s) != 0)
      i++;
//    printf("i = %d\n", i);
    for (int r = 0; r <= 5; r++)
      for (int dx = 1; dx >= -1; dx -= 2)
      {
        int j = i + r * dx;
        if (0 <= j && j < 5 && n[j] > 0)
        {
          n[j]--;
          puts(str[j]);
          r = 10;
          break;
        }
      }
  }
  return 0;
}