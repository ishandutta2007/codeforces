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
#define SS second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
void fix(vector<pair<char,LL> >&a){
    int it=0;
    REP(i,SZ(a)){
        if(it&&a[it-1].F==a[i].F)a[it-1].SS+=a[i].SS;
        else a[it++]=a[i];
    }
    a.resize(it);
}
int far[SIZE];
int main(){
    DRII(n,m);
    vector<pair<char,LL> >S,T;
    REP(i,n){
        char s[24];
        RS(s);
        int it=0;
        while(s[it]!='-')it++;
        s[it]=0;
        S.PB(MP(s[it+1],atoi(s)));
    }
    REP(i,m){
        char s[24];
        RS(s);
        int it=0;
        while(s[it]!='-')it++;
        s[it]=0;
        T.PB(MP(s[it+1],atoi(s)));
    }
    fix(S);
    fix(T);
    LL an=0;
    if(SZ(T)==1){
        REP(i,SZ(S)){
            if(S[i].F==T[0].F)
                an+=max(0LL,S[i].SS-T[0].SS+1);
        }
    }
    else if(SZ(T)==2){
        REPP(i,1,SZ(S)){
            if(S[i-1].F==T[0].F&&S[i].F==T[1].F&&S[i-1].SS>=T[0].SS&&S[i].SS>=T[1].SS)an++;
        }
    }
    else{
        int rr=1,ll=1;
        REPP(i,2,SZ(T)-1){
            int now=0;
            if(i<rr)now=min(far[i-ll+1],rr-i);
            while(i+now<SZ(T)-1&&T[i+now]==T[1+now])now++;
            far[i]=now;
            if(i+now>rr){
                ll=i;
                rr=i+now;
            }
        }
        ll=1,rr=1;
        REPP(i,1,SZ(S)-1){
            int now=0;
            if(i<rr)now=min(far[i-ll+1],rr-i);
            while(i+now<SZ(S)-1&&now<SZ(T)-2&&S[i+now]==T[1+now])now++;
            if(now==SZ(T)-2){
                if(S[i-1].F==T[0].F&&S[i-1].SS>=T[0].SS&&S[i+SZ(T)-2].F==T.back().F&&S[i+SZ(T)-2].SS>=T.back().SS)an++;
            }
            if(i+now>rr){
                rr=i+now;
                ll=i;
            }
        }
    }
    cout<<an;
    return 0;
}