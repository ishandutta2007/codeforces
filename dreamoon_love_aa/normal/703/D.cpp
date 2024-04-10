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
int B[SIZE],a[SIZE],an[SIZE];
void ins(int x,int v){
 for(;x;x-=x&-x)B[x]^=v;
}
int qq(int x){
 int r=0;
 for(;x<SIZE;x+=x&-x)r^=B[x];
 return r;
}
VPII q[SIZE];
int main(){
 DRI(N);
 REPP(i,1,N+1)RI(a[i]);
 DRI(Q);
 REP(i,Q){
  DRII(x,y);
  q[y].PB(MP(x,i));
 }
 map<int,int>lt;
 REPP(i,1,N+1){
  int x=a[i];
  if(lt.count(x)){
   ins(lt[x],x);
  }
  lt[x]=i;
  REP(j,SZ(q[i])){
   an[q[i][j].S]=qq(q[i][j].F);
  }
 }
 REP(i,Q)printf("%d ",an[i]);
 return 0;
}