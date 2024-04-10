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
const int SIZE = 1<<20;
double dp[1<<20],s[1<<20];
double p[22],an[22];
int d[SIZE];
int main(){
 DRII(N,K);
 int it=0,cc=0;
 REP(i,N){
  cin>>p[i];
  if(p[i]>1e-9)cc++;
 }
 if(cc<K){
  REP(i,N)printf("%d ",p[i]>1e-9?1:0);
  return 0;
 }
 REPP(i,1,1<<N){
  int b=i&-i;
  d[i]=d[i-b]+1;
  if(d[i]==1){s[i]=p[it];dp[i]=p[it++];}
  else{
   s[i]=s[i-b]+s[b];
   REP(j,N)
    if((i>>j)&1){
     if(p[j]>1e-9)dp[i]+=dp[i-(1<<j)]*(p[j]/(1-s[i]+p[j]));
    }
  }
  if(d[i]==K)REP(j,N)an[j]+=dp[i]*((i>>j)&1);
 }
 REP(i,N)printf("%.12f ",an[i]);
 return 0;
}