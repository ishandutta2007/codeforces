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
VI e[SIZE];
VPII store[SIZE];
int used[SIZE],tt;
int bfs[SIZE],dis[SIZE];
int can(int st,int V,LL C){
    multiset<PII>now;
    tt++;
    bfs[0]=st;
    used[st]=tt;
    dis[st]=0;
    int rr=1;
    REP(i,rr){
        int x=bfs[i];
        REP(j,SZ(store[x])){
            PII gg=store[x][j];
            if(V>0){
                int mi=min(V,gg.S);
                gg.S-=mi;
                V-=mi;
                now.insert(MP(gg.F,mi));
                C-=(LL)gg.F*mi;
            }
            while(gg.S&&gg.F<now.rbegin()->F){
                PII you=*now.rbegin();
                now.erase(now.find(you));
                int mi=min(gg.S,you.S);
                now.insert(MP(gg.F,mi));
                gg.S-=mi;
                you.S-=mi;
                C+=mi*(LL)(you.F-gg.F);
                if(you.S)now.insert(you);
            }
            if(V==0&&C>=0)return dis[x];
        }
        REP(j,SZ(e[x])){
            int y=e[x][j];
            if(used[y]!=tt){
                used[y]=tt;
                bfs[rr++]=y;
                dis[y]=dis[x]+1;
            }
        }
    }
    return -1;
}
int main(){
    DRII(n,m);
    REP(i,m){
        DRII(x,y);x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    DRI(w);
    REP(i,w){
        DRIII(x,y,z);x--;
        store[x].PB(MP(z,y));
    }
    DRI(q);
    REP(kk,q){
        DRIII(x,y,z);x--;
        printf("%d\n",can(x,y,z));
    }
    return 0;
}