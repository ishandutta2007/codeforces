#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

char s[105];
char vow[7] = "AEIOUY";

int isvow(char c)
{
  for (int i=0; i<6; i++)
    if (vow[i] == c)
      return 1;
  return 0;
}

int main()
{
  scanf("%s", s);
  int n = (int) strlen(s);

  int poz = -1;
  int rje = 0;
  for (int i=0; i<n; i++) {
    if (isvow(s[i])) {
      rje = max(rje, i - poz);
      poz = i;
    }
  }

  rje = max(rje, n - poz);

  printf("%d\n", rje);

  return 0;
}