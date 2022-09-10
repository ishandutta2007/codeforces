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
VI r[SIZE];
int used[SIZE];
int main(){
 int rr=0,an=0,id=0;
 DRII(GGG,N);
 REP(i,N){
  DRII(x,y);
  if(x==1){
   an++;
   r[y].PB(id++);
  }
  else if(x==2){
   REP(j,SZ(r[y])){
    int z=r[y][j];
    if(!used[z])an--;
    used[z]=1;
   }
   r[y].clear();
  }
  else{
   REPP(j,rr,y){
    if(!used[j])an--;
    used[j]=1;
   }
   rr=max(rr,y);
  }
  printf("%d\n",an);
 } 
 return 0;
}