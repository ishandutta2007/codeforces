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
#define F first
#define S second
typedef long long LL;
using namespace std;
vector<pair<int,int> >pp;
int ma,an[12],d[12],n,r;
int f(int s[]){
    int res=0;
    REP(i,n)REPP(j,i+1,n){
        res+=(pp[s[i]].F-pp[s[j]].F)*(pp[s[i]].F-pp[s[j]].F)+(pp[s[i]].S-pp[s[j]].S)*(pp[s[i]].S-pp[s[j]].S);
    }
    return res;
}
void go(){
    bool suc=true;
    int now=0;
    while(suc){
        suc=false;
        REP(i,n){
            int nt=d[i];
            REP(j,SZ(pp)){
                d[i]=j;
                int tmp=f(d);
                if(tmp>now){
                    now=tmp;
                    nt=j;
                    suc=true;
                }
            }
            d[i]=nt;
        }
    }
}
int main(){
    srand(514);
    RII(n,r);
    REP(i,r+1){
        REP(j,r+1){
            if(i*i+j*j<=r*r){
                pp.PB(MP(i,j));
                pp.PB(MP(i,-j));
                pp.PB(MP(-i,j));
                pp.PB(MP(-i,-j));
            }
        }
    }
    sort(ALL(pp));
    pp.resize(unique(ALL(pp))-pp.begin());
    REP(k,50){
        REP(i,n){
            d[i]=rand()%SZ(pp);
            go();
            int tmp=f(d);
            if(tmp>ma){
                ma=tmp;
                REP(j,n)an[j]=d[j];
            }
        }
    }
    printf("%d\n",f(an));
    REP(i,n)printf("%d %d\n",pp[an[i]].F,pp[an[i]].S);
    return 0;
}