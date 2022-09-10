#include <iostream>
#include <cstdio>

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
#include <algorithm>
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[250];


bool is_poisson() {
  int sum=0;
  REP(j, 250) sum += a[j];
  double P = sum/250.;
  double dd=0;

  REP(j,250){
    dd+=(P-a[j])*(P-a[j]);
  }
  dd/=250.;
  if(dd<P*2) return true;
  return false;
}

int main(){
    DRI(V);
    REP(i,V){
        int sum=0;
        REP(j,250){
            RI(a[j]);
            sum+=a[j];
        }
        double P = sum / 250.;
        
        if(is_poisson()) {
          sort(a, a+250);
          sum=0;
          int cnt=0;

            double dd=0;

            REP(j,250){
              dd+=(P-a[j])*(P-a[j]);
            }
            dd/=250.;

          REP(j, 250) {
            if((P-a[j])<=dd && P-a[j]>=-dd) {
              sum += a[j];
              cnt++;
            }
          }
          P = sum/(double)cnt;

          printf("%.0f\n",P);
        }
				else {
				  int x=*min_element(a, a+250);
          int y=*max_element(a, a+250);
          P = (x+y)/2.;
          printf("%.0f\n", P);
        }
        
    }
    return 0;
}