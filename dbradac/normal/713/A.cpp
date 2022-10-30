#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int KOL = 1<<20;

int ima[KOL];

void Stavi(ll x, int st)
{
  int val = 0, mul = 1;
  for (; x; x /= 10, mul *= 2)
    val += mul * ((int) ((x % 10) % 2));

  ima[val] += st;
}

int main()
{
  int q;

  scanf("%d", &q);

  for (; q--; ) {
    char s[3];
    scanf("%s", s);
    if (s[0] == '+' || s[0] == '-') {
      ll n;
      scanf("%lld", &n);
      Stavi(n, (s[0] == '+' ? 1 : -1));
    }
    else {
      char pat[20];
      scanf("%s", pat);
      int len = (int) strlen(pat);
      int val = 0;
      for (int i=0; i<len; i++)
        val = 2 * val + pat[i] - '0';

      printf("%d\n", ima[val]);
    }
  }

  return 0;
}