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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+2;
VL d;
VI fac[SIZE];
int main(){
    REPP(i,1,SIZE){
        d.PB((LL)i*i*i);
    }
    REPP(i,2,SIZE){
        if(!SZ(fac[i])){
            for(int j=i;j<SIZE;j+=i){
                fac[j].PB(i);
            }
        }
    }
    DRI(n);
    REP(i,n){
        DRII(x,y);
        LL v=x*(LL)y;
        int it=lower_bound(ALL(d),v)-d.begin();
        if(d[it]==v){
            v=it+1;
            bool err=0;
            REP(i,SZ(fac[v])){
                int p=fac[v][i];
                int c[2]={};
                while(x%p==0){
                    c[0]++;
                    x/=p;
                }
                while(y%p==0){
                    c[1]++;
                    y/=p;
                }
                if(c[0]>c[1]*2||c[1]>c[0]*2){
                    err=1;
                    break;
                }
            }
            if(err)puts("No");
            else puts("Yes");
        }
        else puts("No");
    }
    return 0;
}