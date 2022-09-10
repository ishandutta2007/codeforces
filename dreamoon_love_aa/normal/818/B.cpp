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
const int SIZE = 1e6+10;
int a[SIZE],an[SIZE];
bool u[SIZE];
int main(){
    DRII(N,M);
    REP(i,M){
        RI(a[i]);
        a[i]--;
        if(i){
            int v=(a[i]-a[i-1]+N)%N;
            if(v==0)v=N;
            if(an[a[i-1]]!=v&&an[a[i-1]])return 0*puts("-1");
            an[a[i-1]]=v;
            u[v]=1;
        }
    }
    int it=1;
    REP(i,N){
        if(!an[i]){
            while(u[it])it++;
            an[i]=it;
            it++;
        }
    }
    while(u[it])it++;
    if(it<=N)return 0*puts("-1");
    REP(i,N)printf("%d ",an[i]);

    return 0;
}