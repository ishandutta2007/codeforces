#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>

//#define taskname ""

using namespace std;

int main() 
{
  int x, y, i;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d", &x, &y);
  for (i=0; ; i++)
  {
    if (i*i==x*x+y*y)
    {
      printf("black\n");
      return 0;
    }
    if (i*i<x*x+y*y && (i+1)*(i+1)>x*x+y*y)
      break; 
  } 
  if ((i%2==1 && x*y<0) || (i%2==0 && x*y>0))
    printf("black\n");
  else
    printf("white\n"); 
  return 0;
}