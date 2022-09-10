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
int nn[SIZE],u[SIZE],p[SIZE],d[SIZE],to[SIZE];
LL fac[SIZE];
VI pp,ker[SIZE];
void err(){puts("0");exit(0);}
void fit(int x,int y){
 if(to[x]&&to[x]!=y)err();
 to[x]=y;
}
int main(){
 DRI(n);
 fac[0]=fac[1]=d[1]=1;
 REPP(i,1,n+1)nn[i]=1;
 ker[1].PB(n+1);
 REPP(i,2,n+1){
  d[i]=n/i;
  fac[i]=fac[i-1]*i%MOD;
  if(p[i]==0){
   ker[i].PB(i);
   nn[i]=i;
   pp.PB(i);
   for(int j=i+i;j<=n;j+=i)nn[j]*=i,p[j]=1,ker[j].PB(i);
  }
 }
 pp.PB(n+1);
 d[n+1]=1;
 REPP(i,1,n+1){
  DRI(x);u[x]=1;
  if(!x)continue;
  if(SZ(ker[i])!=SZ(ker[x]))err();
  REP(j,SZ(ker[i])){
   if(d[ker[i][j]]!=d[ker[x][j]])err();
   fit(ker[i][j],ker[x][j]);
  }
 }
 map<int,int>H,G;
 LL an=1;
 REP(i,SZ(pp)){
  if(!to[pp[i]])H[d[pp[i]]]++;
 }
 REPP(i,1,n+1){
  if(!u[i])G[nn[i]]++;
 }
 for(map<int,int>::iterator it=H.begin();it!=H.end();it++)an=an*fac[it->S]%MOD;
 for(map<int,int>::iterator it=G.begin();it!=G.end();it++)an=an*fac[it->S]%MOD;
 cout<<an;
 return 0;
}