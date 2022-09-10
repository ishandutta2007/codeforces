#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],u[SIZE],in[SIZE],tt;
int main(){
 int r=0;
 DRI(n);
 REPP(i,1,n+1)RI(a[i]);
 VI an;
 REPP(i,1,n+1){
  if(!u[i]){
   tt++;
   int x=i;
   in[x]=tt;u[x]=1;
   for(x=a[x];!u[x];x=a[x])u[x]=1,in[x]=tt;
   if(in[x]==tt){
    if(x==a[x]||!r)r=x;
    an.PB(x);
   }
  }
 }
 int ker=(a[r]==r);
 REP(i,SZ(an))a[an[i]]=r;
 printf("%d\n",SZ(an)-ker);
 REPP(i,1,n+1)printf("%d ",a[i]);
 return 0;
}