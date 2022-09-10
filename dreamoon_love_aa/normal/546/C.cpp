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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 4e6+10;
// template end here
set<pair<queue<int>,queue<int> > >H;
pair<queue<int>,queue<int> >now;
int v[SIZE];
int main(){
    DRI(n);
    DRI(k1);
    REP(i,k1){
        DRI(x);
        now.F.push(x);
    }
    DRI(k2);
    REP(i,k2){
        DRI(x);
        now.S.push(x);
    }
    H.insert(now);
    int ans=0;
    while(1){
        if(SZ(now.F)==0){
            printf("%d %d\n",ans,2);
            return 0;
        }
        if(SZ(now.S)==0){
            printf("%d %d\n",ans,1);
            return 0;
        }
        ans++;
        int x=now.F.front();now.F.pop();
        int y=now.S.front();now.S.pop();
        if(x>y){
            now.F.push(y);
            now.F.push(x);
        }
        else{
            now.S.push(x);
            now.S.push(y);
        }
        if(H.count(now)){
            puts("-1");
            return 0;
        }
        H.insert(now);
    }

    return 0;
}