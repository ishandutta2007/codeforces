#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

int y, m, d;

int check(int a, int b, int c)
{
  int ans;
  ans=0;
  if (b<=12 && (((b==2) && c%4==0 && a==29)  || (a<=28 && b==2) || (b!=2 && (a<31 || (a==31 && (b==1 || b==3 || b==5 || b==7 || b==8 || b==12 || b==10))))))
  {
    if (c+18<y || ((c+18)==y && b<m) || ((c+18)==y && b==m && a<=d))
      ans=1;
  }
  return ans;
}

int main()
{
  int x1, x2, x3, ans;
  scanf("%d", &d);
  m=getc(stdin);
  scanf("%d", &m);
  y=getc(stdin);
  scanf("%d", &y);
  scanf("%d", &x1);
  x2=getc(stdin);
  scanf("%d", &x2);
  x3=getc(stdin);
  scanf("%d", &x3);
  //cout<<d<<' '<<m<<' '<<y<<' ';
  ans=0;
  ans=max(ans,check(x1,x2,x3));
  ans=max(ans,check(x1,x3,x2));
  ans=max(ans,check(x2,x1,x3));
  ans=max(ans,check(x2,x3,x1));
  ans=max(ans,check(x3,x2,x1));
  ans=max(ans,check(x3,x1,x2));
  if (ans==0)
    printf("NO\n");
  else
    printf("YES\n");
  return 0;
}