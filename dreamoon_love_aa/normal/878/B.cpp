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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE];
int main(){
    DRIII(N,K,M);
    REP(i,N){
        RI(a[i]);
    }
    VPII pp;
    LL sum=0;
    for(int i=0,j;i<N;i=j){
        for(j=i+1;j<N&&a[j]==a[i];j++);
        if((j-i)%K){
            if(SZ(pp)&&pp.back().F==a[i]){
                pp.back().S+=(j-i);
                pp.back().S%=K;
                if(pp.back().S==0)pp.pop_back();
            }
            else{
                pp.PB(MP(a[i],(j-i)%K));
            }
        }
    }
    REP(i,SZ(pp)){
        sum+=pp[i].S;
    }
    sum*=M;
    if(SZ(pp)==0)puts("0");
    else if(SZ(pp)==1){
        printf("%lld\n",(pp[0].S*(LL)M)%K);
    }
    else{
        int ll=0,rr=SZ(pp)-1;
        while(ll<rr&&pp[ll].F==pp[rr].F){
            sum-=(LL)(pp[ll].S+pp[rr].S)/K*K*(M-1);
            if((pp[ll].S+pp[rr].S)%K==0){
                ll++;rr--;
            }
            else{
                break;
            }
        }
        if(ll==rr){
            if((LL)pp[ll].S*M%K){
                sum-=(LL)pp[ll].S*M/K*K;
            }
            else{
                sum=0;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}