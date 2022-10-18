#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  int i;
  puts("400");
  puts("0 1000000");
  for (i=1; i<399; i++)
    printf("%d %d\n", 50000+i*1000, 400-i);
  printf("1000000 1000000\n");
  return 0;
}