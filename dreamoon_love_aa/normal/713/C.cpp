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
const int SIZE = 3110;
int a[SIZE];
int d[SIZE][SIZE];
LL dp[SIZE][SIZE];
int main(){
 LL an=1e18;
 DRI(N);
 REP(i,N)RI(a[i]);
 REP(i,N){
  REP(j,N)d[i][j]=a[j]+i-j;
  sort(d[i],d[i]+N);
  if(!i)REP(j,N)dp[i][j]=abs(a[i]-d[i][j]);
  else{
   int ll=0;
   LL v=1e18;
   REP(j,N){
    while(ll<N&&d[i-1][ll]<d[i][j])v=min(v,dp[i-1][ll++]);
    dp[i][j]=v+abs(a[i]-d[i][j]);
    if(i==N-1)an=min(an,dp[i][j]);
   }
  }
 }
 if(N==1)an=0;
 cout<<an<<endl;
 return 0;
}