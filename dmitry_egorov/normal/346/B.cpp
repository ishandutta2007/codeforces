#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

char str[3][110];
int s[3][110];
int NP[110][26];
int N[2][110][26];
int len[3];
int D[110][110][110], P[110][110][110][3], x, y, z;
                       
void write (int x, int y, int z)
{
  if (x==0)
    return;
  write(P[x][y][z][0],P[x][y][z][1],P[x][y][z][2]);
  printf("%c", str[0][x-1]);
}

int main()
{
  int i, j, k, t, xx, yy, zz;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<3; i++)
  {
    scanf(" %s", str[i]), len[i]=strlen(str[i]);
    for (j=0; j<len[i]; j++)
      s[i][j]=(int)(str[i][j]-'A');
  }
  for (i=0; i<len[2]; i++)
    for (j=0; j<26; j++)
      for (k=1; k<=i+1; k++)
        if (s[2][k-1]==j)
        {
          bool fl=1;
          for (t=0; t<k-1; t++)
            if (s[2][t]!=s[2][t+i-k+1])
            {
              fl=0;
              break;
            }
          if (fl)
            NP[i][j]=k;
        }

  /*cerr<<s[2][0]<<" "<<s[2][1]<<endl;
  for (i=0; i<len[2]; i++)
    for (j=0; j<26; j++)
      if (NP[i][j]>0)
        cerr<<i<<" "<<j<<"  "<<((char)(j+'A'))<<"     "<<NP[i][j]<<endl; */


  for (i=0; i<2; i++)
  {
    for (j=0; j<26; j++)
      N[i][len[i]][j]=len[i]+1;
    for (j=len[i]-1; j>=0; j--)
    {
      for (k=0; k<26; k++)
        N[i][j][k]=N[i][j+1][k];
      N[i][j][s[i][j]]=j+1;
    }
  }
  for (i=0; i<110; i++)
    for (j=0; j<110; j++)
      for (k=0; k<110; k++)
        D[i][j][k]=-1;
  D[0][0][0]=0;
  for (i=0; i<=len[0]; i++)
    for (j=0; j<=len[1]; j++)
      for (k=0; k<len[2]; k++)
        if (D[i][j][k]!=-1)
        {
          //cerr<<i<<" "<<j<<"  "<<k<<"       "<<D[i][j][k]<<endl;
          if (D[i][j][k]>D[x][y][z])
            x=i, y=j, z=k;
          for (t=0; t<26; t++)
            if (NP[k][t]!=len[2])
            {
              xx=N[0][i][t], yy=N[1][j][t], zz=NP[k][t];
              if (xx==len[0]+1 || yy==len[1]+1 || D[xx][yy][zz]>D[i][j][k]+1)
                continue;
              //cerr<<"???  "<<t<<"    "<<((char)(t+'A'))<<"   "<<xx<<" "<<yy<<endl;
              D[xx][yy][zz]=D[i][j][k]+1;
              P[xx][yy][zz][0]=i;
              P[xx][yy][zz][1]=j;
              P[xx][yy][zz][2]=k;
            }
        }
  if (D[x][y][z]==0)  
  {
    puts("0");
    return 0;
  }
  write(x,y,z);
  printf("\n");
  TIMESTAMP(end);
  return 0;
}