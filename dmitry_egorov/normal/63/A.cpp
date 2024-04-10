#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int n;
char s[110][2][110];

int main() {
  int i;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf(" %s %s", s[i][0], s[i][1]);
  for (i=0; i<n; i++)
    if (strcmp(s[i][1],"rat")==0)
      puts(s[i][0]);
  for (i=0; i<n; i++)
    if (strcmp(s[i][1],"woman")==0 || strcmp(s[i][1],"child")==0)
      puts(s[i][0]);

  for (i=0; i<n; i++)
    if (strcmp(s[i][1],"man")==0)
      puts(s[i][0]);

  for (i=0; i<n; i++)
    if (strcmp(s[i][1],"captain")==0)
      puts(s[i][0]);

  return 0;
}