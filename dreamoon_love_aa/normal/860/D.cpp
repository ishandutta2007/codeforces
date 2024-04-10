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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
bool pu[SIZE],eu[SIZE];
VPII e[SIZE];
VI an;
int dfs(int x){
    if(pu[x])return x;
    pu[x]=1;
    int lt=-1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int eid=e[x][i].S;
        if(eu[eid])continue;
        eu[eid]=1;
        int ret=dfs(y);
        if(ret!=-1){
            if(lt==-1)lt=ret;
            else{
                an.PB(lt);
                an.PB(x);
                an.PB(ret);
                lt=-1;
            }
        }
        else{
            an.PB(x);
        }
    }
    if(lt!=-1){
        an.PB(lt);
        an.PB(x);
        return -1;
    }
    return x;
}
int main(){
    DRII(N,M);
    REP(i,M){
        DRII(x,y);x--;y--;
        e[x].PB(MP(y,i));
        e[y].PB(MP(x,i));
    }
    REP(i,SIZE){
        if(!pu[i]){
            dfs(i);
            an.resize(SZ(an)/3*3);
        }
    }
    printf("%d\n",SZ(an)/3);
    REP(i,SZ(an)){
        printf("%d %d %d\n",an[i]+1,an[i+1]+1,an[i+2]+1);
        i+=2;
    }
    return 0;
}