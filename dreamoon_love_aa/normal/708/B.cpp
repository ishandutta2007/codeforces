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
int main(){
 DRII(a00,a01);
 DRII(a10,a11);
 LL  s=0;
 s+=a00+a01;
 s+=a10+a11;
 if(s==0)return 0*puts("0");
 int n=0;
 for(;n*(n-1LL)/2<s;n++);
 if(n*(n-1LL)!=2*s)return 0*puts("Impossible");
 int z=0;
 for(;z*(z-1LL)/2<a00||(n-z)*(n-z-1LL)/2>a11;z++);
 if(z*(z-1LL)!=a00*2||(n-z)*(n-z-1LL)!=a11*2||(n-z)*(n-z-1LL)!=a11*2||(!z&&a11!=s))return 0*puts("Impossible");
 if(!z){
  REP(i,n)printf("1");
  return 0*puts("");
 }
int l=a10/z,r=a10%z;
 REP(i,l)printf("1");
 REP(i,z-r)printf("0");
 if(l!=n-z)printf("1");
 REP(i,r)printf("0");
 REP(i,n-z-l-1)printf("1");
 puts("");
 return 0;
}