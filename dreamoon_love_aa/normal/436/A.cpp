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
vector<pair<int,int> >d[2];
bool used[2][2000];
int go(int now,LL h){
    int an=0;
    MS0(used);
    while(1){
        int ma=-1,id=-1;
        REP(i,SZ(d[now])){
            if(d[now][i].F<=h){
                if(used[now][i]==0&&d[now][i].S>ma){
                    id=i;
                    ma=d[now][i].S;
                }
            }
        }
        if(id==-1)return an;
        an++;
        used[now][id]=1;
        h+=d[now][id].S;
        now^=1;
    }
}
int main(){
    DRII(n,v);
    REP(i,n){
        DRIII(x,y,z);
        d[x].PB(MP(y,z));
    }
    cout<<max(go(0,v),go(1,v));
    return 0;
}