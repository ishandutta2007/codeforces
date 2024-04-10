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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char na[2][101];
int main(){
    RS(na[0]);
    RS(na[1]);
    DRI(n);
    map<pair<int,int>,int>ker;
    set<pair<int,int> >H;
    while(n--){
        DRI(t);
        char ha[4],yr[4];
        RS(ha);
        DRI(m);
        RS(yr);
        int x,s;
        if(ha[0]=='h')x=0;
        else x=1;
        if(yr[0]=='y')s=1;
        else s=2;
        ker[MP(x,m)]+=s;
        if(ker[MP(x,m)]>=2&&H.count(MP(x,m))==0){
            H.insert(MP(x,m));
            printf("%s %d %d\n",na[x],m,t);
        }
    }
    return 0;
}