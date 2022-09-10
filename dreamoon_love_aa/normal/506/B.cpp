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
const int SIZE = 1e6+10;
vector<int>e[SIZE];
VPII pp;
bool used[SIZE];
int id,order[SIZE],num;
void dfs(int x){
    used[x]=1;
    num++;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        pp.PB(MP(x,y));
        if(used[y])continue;
        dfs(y);
    }
    order[x]=id++;
}
struct Union_Find{
    int d[SIZE];
    void init(int n){
        REP(i,n)d[i]=i;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        d[x]=y;
        return 1;
    }
}U;
vector<int>gg[SIZE];
int main(){
    DRII(n,m);
    U.init(n);
    REP(i,m){
        DRII(x,y);
        x--;y--;
        U.uu(x,y);
        e[x].PB(y);
    }
    REP(i,n)
        gg[U.find(i)].PB(i);
    int an=0;
    REP(i,n){
        if(SZ(gg[i])){
            pp.clear();
            num=0;
            REP(k,SZ(gg[i]))
                if(!used[gg[i][k]])dfs(gg[i][k]);
            an+=num-1;
            bool suc=1;
            REP(i,SZ(pp)){
                if(order[pp[i].F]<order[pp[i].S])suc=0;
            }
            if(!suc)an++;
        }
    }
    printf("%d\n",an);
    return 0;
}