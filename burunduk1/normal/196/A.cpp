#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

char s[(int)1e5 + 10];
char r[(int)1e5 + 10];
int rn;

int main()
{
  scanf("%s", s);
  int n = strlen(s);
  char c = 'a';
  while (n--)
    if (s[n] >= c)
      r[rn++] = c = s[n];
  while (rn--)
    putchar(r[rn]);
  return 0;
}