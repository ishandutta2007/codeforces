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
char s[SIZE];
int main(){
  RS(s);
  bool t=0,dot=0,ker=1;
  int pn=0,nn=0,v;
  vector<char>d;
  for(int i=0;s[i];i++){
    if(t)pn++;
    if(dot)nn++;
    if(s[i]=='.'){
      if(t&&ker)v=pn-1,ker=0;
      dot=1;
    }
    else if(s[i]!='0'||t){
      if(dot&&ker)v=-nn,ker=0;
      d.PB(s[i]);
      t=1;
    }
  }
  if(!dot)v=pn;
  while(d.back()=='0')d.pop_back();
  printf("%c",d[0]);
  if(SZ(d)>1){printf(".");REPP(i,1,SZ(d))printf("%c",d[i]);}
  if(v)printf("E%d",v);
  return 0;
}