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
#include <utility>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int main() {
  int n, i, j;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  //cerr<<(int)('p'-'a')<<endl;
  if (n==1)
  {
    printf("a\na\nb\nb\n");
    return 0;
  }
  if (n==2)
  {
    printf("aa\nbb\ncc\ndd\n");
    return 0;
  }
  if (n%2==1)
  {
    for (i=0; i<2; i++)
    {
      printf("a");
      for (j=0; j<n/2; j++)
        printf("%c%c", 'b'+((i+j+5)%10), 'b'+((i+j+5)%10));
      printf("\n");
    }
    for (i=0; i<2; i++)
    {
      for (j=0; j<n/2; j++)
        printf("%c%c", 'p'+((i+j+5)%5), 'p'+((i+j+5)%5));
      printf("a");
      printf("\n");
    }
    return 0;
  }
  for (i=0; i<2; i++)
  {
    printf("a");
    for (j=0; j<(n/2)-1; j++)
      printf("%c%c", 'b'+((i+j+5)%5), 'b'+((i+j+5)%5));
    printf("a\n");
  }
  for (i=0; i<2; i++)
  {
    for (j=0; j<(n/2); j++)
      printf("%c%c", 'p'+((i+j+5)%5), 'p'+((i+j+5)%5));
    printf("\n");
  }
  return 0;
}