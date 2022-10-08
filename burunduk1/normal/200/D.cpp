/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.24
 */

#include <cstdio>
#include <cstring>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxN = 1010;
const int mLen = 105;
const int maxK = 5;

char name[maxN][mLen];
int K, n, m, kk, k[maxN];
char args[maxN][maxK][mLen];
char var_name[maxN][mLen];
char var_type[maxN][mLen];
char f_name[mLen];
char f_arg[maxK][mLen];

int main()
{
  char c;
  scanf("%d", &n);
  forn(i, n)
  {
    scanf("%*s");
    scanf(" %[a-z0-9]s", name[i]);
    while (scanf(" %c", &c) == 1 && c != ')')
      scanf(" %[Ta-z0-9]s", args[i][k[i]++]);
    //printf("name = %s, k = %d\n", name[i], k[i]);
  }
  scanf("%d", &m);
  forn(i, m)
    scanf("%s%s", var_type[i], var_name[i]);
  scanf("%d", &kk);
  forn(i, kk)
  {
    scanf(" %[a-z0-9]s", f_name);
    K = 0;
    while (scanf(" %c", &c) == 1 && c != ')')
    {
      scanf(" %[a-z0-9]s", f_arg[K]);
      int i = 0;
      while (strcmp(var_name[i], f_arg[K]))
        i++;
      strcpy(f_arg[K], var_type[i]);
      K++;
    }

    int res = 0;
    //printf("name = %s, k = %d\n", f_name, K);
    forn(i, n)
      if (!strcmp(f_name, name[i]) && k[i] == K)
      {
        int bad = 0;
        forn(j, K)
          if (strcmp(args[i][j], "T") && strcmp(args[i][j], f_arg[j]))
            bad = 1, j = K;
        res += !bad;
      }
    printf("%d\n", res);
  }
  return 0;
}