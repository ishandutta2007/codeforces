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
#define mask ((1<<30)-1)

using namespace std;

vector <int> Pr;
int Ans[126000];
int C[50][50][50][17];
int u[50];
map <pair <int, int>, int> M[400];
map <int, int> U[400];
double tt=clock();

bool isprime (int p)
{
  for (int i=2; i*i<=p; i++)
    if (p%i==0)
      return 0;
  return 1;
}

long long go (int a, int b, int c, int p)
{
  if (a<Pr[p] && b<Pr[p] && c<Pr[p])
    return 1;                   
  if (a<Pr[p])
    a=1;
  if (b<Pr[p])
    b=1;
  if (c<Pr[p])
    c=1;   
  if (a<50 && b<50 && c<50)      
    return C[a][b][c][p];       
  if (c>a)
    swap(a,c);
  if (c>b)
    swap(b,c);
  if (a<b)
    swap(a,b);
  if (b==1 && U[p].count(a))
    return U[p][a];
  if (c==1 && M[p].count(mp(a,b)))
    return M[p][mp(a,b)];
  long long res=0;
  int cnta=0, cntb, cntc, aa=a, bb, cc;
  while (aa>0)
  {
    cntb=0, bb=b;
    while (bb>0)
    {
      cntc=0, cc=c;
      while (cc>0)
        res+=go(aa,bb,cc,p+1)*((long long)(1+cnta+cntb+cntc)), res&=((long long)mask), cc/=Pr[p], cntc++;
      bb/=Pr[p], cntb++;
    }
    aa/=Pr[p], cnta++;
  }
  if (b==1)
    U[p][a]=res;
  if (c==1)
    M[p][mp(a,b)]=(int)res;
  //cerr<<"!!!  "<<a<<" "<<b<<" "<<c<<" "<<p<<"         "<<res<<endl;
  return res;
}

int main()
{
  int i, ii, j, k, t, cnt, li, lj;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  i=2;
  while (i<2500)
  {
    if (isprime(i))
      Pr.pb(i);
    i++;
  }
  for (i=1; i<126000; i++)
    for (ii=i, Ans[i]=1, j=0; j<(int)Pr.size() && Pr[j]<=ii; j++)
    {
      cnt=1;
      while (ii%Pr[j]==0)
        ii/=Pr[j], cnt++;
      Ans[i]*=cnt;
    }
  for (i=1; i<50; i++)
    for (u[i]=50, j=50; j>=0; j--)
      if (i%Pr[j]==0)
        u[i]=j;
  for (i=1; i<50; i++)
    for (j=1; j<50; j++)
      for (k=1; k<50; k++)
        for (t=0; t<17; t++)
        {
          C[i][j][k][t]=C[i][j][k-1][t];
          if (u[k]>=t)
            for (li=1; li<=i; li++)
              if (u[li]>=t)
                for (lj=1; lj<=j; lj++)
                  if (u[lj]>=t)
                    C[i][j][k][t]+=Ans[li*lj*k];
          C[i][j][k][t]&=mask;  
        }
  //cerr<<(clock()-tt)/CLOCKS_PER_SEC<<endl;
  //for (i=1; i<20; i++)
  //  cerr<<i<<"    !!   "<<Ans[i]<<endl;
  //cerr<<C[2][2][1][0]<<"   "<<u[1]<<endl;
  int A[3];
  cin>>A[0]>>A[1]>>A[2];
  sort(A,A+3); 
  //cerr<<C[A[0]][A[1]][A[2]][0]<<endl;
  cout<<go(A[0],A[1],A[2],0)<<endl;
  //cerr<<(clock()-tt)/CLOCKS_PER_SEC<<endl;
  return 0;
}