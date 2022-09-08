#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, l, i, ans;
char s[2222];

int main()
{
  scanf("%d\n", &n);
  gets(s);
  l = strlen(s);
  for (i = 3; i < l; i++)
  {
    if (i % n == 0)
    {
      if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) ans++;
    }
  }
  printf("%d", ans);
}