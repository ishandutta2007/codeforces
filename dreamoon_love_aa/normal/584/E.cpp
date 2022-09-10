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
const int SIZE = 2e3+10;
int from[SIZE],to[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        from[x]=i+1;
    }
    REP(i,n){
        DRI(x);
        to[x]=i+1;
    }
    VPII res;
    int an=0;
    priority_queue<PII>qq;
    REPP(i,1,n+1){
        if(from[i]!=to[i])qq.push(MP(abs(from[i]-to[i]),i));
    }
    while(!qq.empty()){
        PII me=qq.top();qq.pop();
        if(me.F!=abs(from[me.S]-to[me.S])){
            if(from[me.S]!=to[me.S]){
                qq.push(MP(abs(from[me.S]-to[me.S]),me.S));
            }
            continue;
        }
        if(from[me.S]<to[me.S]){
            REPP(i,1,n+1){
                if(from[i]>from[me.S]&&to[i]<=from[me.S]){
                    res.PB(MP(from[me.S],from[i]));
                    an+=abs(from[me.S]-from[i]);
                    swap(from[me.S],from[i]);
                    if(from[me.S]!=to[me.S])
                        qq.push(MP(abs(from[me.S]-to[me.S]),me.S));
                    break;
                }
            }
        }
        else{
            REPP(i,1,n+1){
                if(from[i]<from[me.S]&&to[i]>=from[me.S]){
                    res.PB(MP(from[me.S],from[i]));
                    an+=abs(from[me.S]-from[i]);
                    swap(from[me.S],from[i]);
                    if(from[me.S]!=to[me.S])
                        qq.push(MP(abs(from[me.S]-to[me.S]),me.S));
                    break;
                }
            }
        }
    }
    printf("%d\n%d\n",an,SZ(res));
    REP(i,SZ(res))printf("%d %d\n",res[i].F,res[i].S);
    return 0;
}