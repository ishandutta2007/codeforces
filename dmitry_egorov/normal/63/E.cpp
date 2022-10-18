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

int Cell[19][2], RCell[20][20];
int Move[19][3];
int D[(1<<19)+5];

bool solve (int p)
{
  int i, j, tmp, k;
  if (D[p]==-1)
  {
    D[p]=0;
    for (i=0; i<19; i++)
      if ((p&(1<<i))!=0)
        for (j=0; j<3; j++)
        {
          tmp=p;
          tmp=p^(1<<i);
          if (!solve(tmp))
          {
            D[p]=1;
            return 1;
          }
          k=Move[i][j];
          while (k!=-1 && (p&(1<<k))!=0)
          {
            tmp^=(1<<k);
            if (!solve(tmp))
            {
              D[p]=1;
              return 1;
            }
            k=Move[k][j];
          }
        }
  }
  return (D[p]==1);
}

int main() {
  int i, j, k, x, y;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  for (i=j=k=0; i<19; i++)
  {
    Cell[i][0]=j, Cell[i][1]=k;
    RCell[j][k]=i;
    if (k+abs(j-2)<4)
      k++;
    else
      j++, k=0;
  }
  for (i=0; i<19; i++)
    for (j=0; j<3; j++)
    {
      y=Cell[i][0], x=Cell[i][1];
      if (j==0)
      {
        if (y<2)
          Move[i][0]=RCell[y+1][x+1];
        else
        {
          if (x+abs(y-1)<5 && y!=4)
            Move[i][0]=RCell[y+1][x];
          else
            Move[i][0]=-1;
        }
      }
      if (j==1)
      {
        if (x+abs(y-2)>=4)
          Move[i][1]=-1;
        else
          Move[i][1]=RCell[y][x+1];
      }
      if (j==2)
      {
        if (y>=3)
          Move[i][2]=RCell[y-1][x+1];
        else
        {
          if (x+abs(y-3)<5 && y!=0)
            Move[i][2]=RCell[y-1][x];
          else
            Move[i][2]=-1;
        }
      }
    }
  //for (i=0; i<19; i++)
 //   printf("%d %d    %d\n", Cell[i][0], Cell[i][1], RCell[Cell[i][0]][Cell[i][1]]);

 // puts("");

/*  for (i=0; i<19; i++)
  {
    for (j=0; j<3; j++)
    {
      if (Move[i][j]!=-1)
        printf("%d %d    j=%d     %d %d\n", Cell[i][0], Cell[i][1], j, Cell[Move[i][j]][0], Cell[Move[i][j]][1]);
      else
        printf("%d %d    j=%d      -1\n", Cell[i][0], Cell[i][1], j);
    }
    puts("");
  } */

  char tmp;
  int st=0;
  memset(D,-1,sizeof(D));
  for (i=0; i<19; i++)
  {
    scanf(" %c", &tmp);
    if (tmp!='.')
      st+=(1<<i);
  }
  if (solve(st))
    puts("Karlsson");
  else
    puts("Lillebror");
  return 0;
}