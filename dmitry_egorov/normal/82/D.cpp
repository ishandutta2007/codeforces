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

#define taskname "d"
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int n, A[1100], D[1100][1100], Prev[1100][1100][2];

void write (int v, int w)
{
  int i;
  //cerr<<v<<" "<<w<<endl;
  if (v==0 && w==1)
    return;
  write(Prev[v][w][0],Prev[v][w][1]);
  int C[5];
  C[0]=Prev[v][w][0];
  for (i=1; i<5; i++)
    C[i]=Prev[v][w][1]+i-1;
  int cnt=2, cc=0;
  while (cnt>0)
  {
    if (C[cc]!=v && C[cc]<w)
    {
      cnt--, printf("%d", C[cc]+1);
      if (cnt==1)
        printf(" ");
    }
    cc++;
  }
  printf("\n");
}

int main() {
  int i, j;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  if (n==1)
  {
    printf("%d\n1\n", A[0]);
    return 0;
  }
  //cerr<<inf<<endl;
  for (i=0; i<1100; i++)
    for (j=0; j<1100; j++)
      D[i][j]=inf;
  D[0][1]=0, Prev[0][1][0]=-1, Prev[0][1][1]=-1;
  for (i=0; i<=n+5; i++)
    for (j=i+1; j<=n+10; j++)
    {
      if (D[i][j]==inf)
        continue;
      //cout<<i<<" "<<j<<" "<<D[i][j]<<" "<<Prev[i][j][0]<<" "<<Prev[i][j][1]<<endl;
      if (D[j+1][j+2]>D[i][j]+max(A[i],A[j]))
      {
        D[j+1][j+2]=D[i][j]+max(A[i],A[j]);
        Prev[j+1][j+2][0]=i, Prev[j+1][j+2][1]=j;
      }
      if (D[j][j+2]>D[i][j]+max(A[i],A[j+1]))
      {
        D[j][j+2]=D[i][j]+max(A[i],A[j+1]);
        Prev[j][j+2][0]=i, Prev[j][j+2][1]=j;
      }
      if (D[i][j+2]>D[i][j]+max(A[j+1],A[j]))
      {
        D[i][j+2]=D[i][j]+max(A[j+1],A[j]);
        Prev[i][j+2][0]=i, Prev[i][j+2][1]=j;
      }
    }
  //cerr<<"!!!"<<endl;
  if (n%2==0)
  {
    //cerr<<"!!!!"<<" "<<n<<" "<<D[n][n+1]<<endl;
    printf("%d\n", D[n][n+1]);
    write(n,n+1);
    return 0;
  }
  int t=inf, bb=-1;
  for (i=0; i<n; i++)
    if (t>D[i][n]+A[i])
      t=D[i][n]+A[i], bb=i;
  printf("%d\n", t);
  write(bb,n);
  printf("%d\n", bb+1);
  return 0;
}