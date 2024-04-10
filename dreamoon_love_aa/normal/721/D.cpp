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
LL an[SIZE];
int main(){
    DRIII(n,k,x);
    priority_queue<PLL>neg,pos;
    REP(i,n){
        DRI(v);
        an[i]=v;
        if(v>0)pos.push(MP(-v,i));
        else neg.push(MP(v,i));

    }
    while(k--){
        if(SZ(neg)%2==0){
            if(SZ(pos)&&(SZ(neg)==0||pos.top().F>neg.top().F)){
                PLL me=pos.top();pos.pop();
                an[me.S]=-me.F-x;
                if(an[me.S]<=0)neg.push(MP(an[me.S],me.S));
                else pos.push(MP(-an[me.S],me.S));
            }
            else{
                PLL me=neg.top();neg.pop();
                an[me.S]=me.F+x;
                if(an[me.S]<=0)neg.push(MP(an[me.S],me.S));
                else pos.push(MP(-an[me.S],me.S));
            }
        }
        else{
            if(SZ(pos)!=0&&pos.top().F>neg.top().F){
                PLL me=pos.top();pos.pop();
                an[me.S]=-me.F+x;
                if(an[me.S]<=0)neg.push(MP(an[me.S],me.S));
                else pos.push(MP(-an[me.S],me.S));
            }
            else{
                PLL me=neg.top();neg.pop();
                an[me.S]=me.F-x;
                if(an[me.S]<=0)neg.push(MP(an[me.S],me.S));
                else pos.push(MP(-an[me.S],me.S));
            }
        }
    }
    REP(i,n)printf("%I64d ",an[i]);
    return 0;
}