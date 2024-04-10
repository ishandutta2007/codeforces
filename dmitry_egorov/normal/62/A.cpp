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

bool check (int g, int b)
{
  if (g-1<=b && (b/2)+(b%2)<=g+1)
    return 1;
  return 0;
}

int main() {
  int a1, a2, b1, b2;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
  if (check(a1,b2) || check(a2,b1))
    puts("YES");
  else
    puts("NO");
  return 0;
}