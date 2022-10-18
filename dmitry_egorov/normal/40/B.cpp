#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

//#define taskname ""

using namespace std;

int solve (int a)
{
  if (a%2==0)
    return a/2;
  else
    return (a+1)/2;
}

int main() 
{
  int n, m, x;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &x);
  printf("%d\n", solve(max(0,n-2*(x-1))*max(0,m-2*(x-1)))-solve(max(0,n-2*(x))*max(0,m-2*(x))));
  return 0;
}