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
int p[SIZE],t[SIZE];
int d[SIZE],d2[SIZE];
LL ma_need[SIZE],mi_need[SIZE];
bool compare(int x,int y){
    if((LL)p[y]*t[x]!=(LL)p[x]*t[y])
        return (LL)p[y]*t[x]<(LL)p[x]*t[y];
    return p[x]<p[y];
}
bool compare2(int x,int y){
    return MP(p[x],-t[x])>MP(p[y],-t[y]);
}
bool compare3(int x,int y){
    return (LL)p[y]*t[x]<(LL)p[x]*t[y];
}
int main(){
    DRI(n);
    LL T=0;
    REP(i,n){
        RI(p[i]);
        d[i]=i;
        d2[i]=i;
    }
    REP(i,n){
        RI(t[i]);
        T+=t[i];
    }
    sort(d,d+n,compare);
    sort(d2,d2+n,compare2);
    REP(i,n){
        if(i){
            if(compare3(d[i-1],d[i]))mi_need[d[i]]=ma_need[d[i-1]]+t[d[i]];
            else mi_need[d[i]]=mi_need[d[i-1]]-t[d[i-1]]+t[d[i]];
            ma_need[d[i]]=ma_need[d[i-1]];
        }
        else mi_need[d[i]]=t[d[i]];
        ma_need[d[i]]+=t[d[i]];
    }
    for(int i=n-1;i>0;i--){
        if(!compare3(d[i-1],d[i]))ma_need[d[i-1]]=ma_need[d[i]];
    }
    double ll=0,rr=1;
    REP(k,100){
        double c=(ll+rr)*0.5;
        bool err=0;
        double lt=1e18;
        for(int i=0,j;!err&&i<n;i=j){
            double mi=1e18;
            for(j=i;j<n&&p[d2[j]]==p[d2[i]];j++){
                if(lt+1e-12<p[d2[j]]*(1-c*mi_need[d2[j]]/T))err=1;
                mi=min(mi,p[d2[j]]*(1-c*ma_need[d2[j]]/T));
            }
            lt=min(lt,mi);
        }
        if(err)rr=c;
        else ll=c;
    }
    printf("%.12f\n",(ll+rr)*0.5);
    return 0;
}