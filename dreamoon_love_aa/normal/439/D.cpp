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
map<int,LL>a,b,res;
int main(){
    LL an=1e18;
    DRII(n,m);
    REP(i,n){
        DRI(x);
        a[x]++;
        res[x]=0;
    }
    REP(i,m){
        DRI(x);
        b[x]++;
        res[x]=0;
    }
    int num=0;
    LL sum=0;
    map<int,LL>::iterator it0=a.begin();
    for(map<int,LL>::iterator it=res.begin();it!=res.end();it++){
        while(it0!=a.end()&&it0->F<=it->F){
            num+=it0->S;
            sum+=(LL)(it0->F)*it0->S;
            it0++;
        }
        it->S+=(LL)num*(it->F)-sum;
    }

    num=0;
    sum=0;
    map<int,LL>::reverse_iterator it2=b.rbegin();
    for(map<int,LL>::reverse_iterator it=res.rbegin();it!=res.rend();it++){
        while(it2!=b.rend()&&it2->F>=it->F){
            num+=it2->S;
            sum+=(LL)(it2->F)*it2->S;
            it2++;
        }
        it->S+=sum-(LL)num*(it->F);
        an=min(an,it->S);
    }
    cout<<an<<endl;
    return 0;
}