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

int main() {
  int n;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  while (n>5)
    n-=5, n=(n+1)/2;
  if (n==1)
    puts("Sheldon");
  if (n==2)
    puts("Leonard");
  if (n==3)
    puts("Penny");
  if (n==4)
    puts("Rajesh");
  if (n==5)
    puts("Howard");
  return 0;
}