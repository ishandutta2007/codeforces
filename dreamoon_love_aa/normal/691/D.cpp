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
int p[SIZE],an[SIZE],d[SIZE],t[SIZE],tn,u[SIZE];
VI e[SIZE];
void dfs(int x){
  if(u[x])return;
  u[x]=1;
  d[tn]=x;t[tn++]=p[x];
  REP(i,SZ(e[x])){
    dfs(e[x][i]);
  }
}
int main(){
  DRII(n,m);
  REP(i,n)RI(p[i+1]);
  REP(i,m){
    DRII(x,y);
    e[x].PB(y);
    e[y].PB(x);
  }
  REP(i,n)
    if(u[i+1]==0){
tn=0;
      dfs(i+1);
      sort(t,t+tn);
      sort(d,d+tn);
      REP(j,tn)an[d[j]]=t[tn-1-j];
    }
  REP(i,n)printf("%d ",an[i+1]);
  return 0;
}