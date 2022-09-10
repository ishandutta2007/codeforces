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
// template end here
vector<int>e[SIZE];
int used[SIZE],tt;
int ty[SIZE];
int num[2];
bool dfs(int x,int v){
    used[x]=tt;
    ty[x]=v;
    num[v]++;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y]==tt){
            if(!(ty[x]^ty[y]))return 1;
        }
        else if(dfs(y,v^1))return 1;
    }
    return 0;
}
int main(){
    int n,m;
    int add=2;
    LL an=0;
    while(RII(n,m)==2){
        tt++;
        if(!m){
            printf("3 %I64d\n",n*(n-1LL)*(n-2LL)/6);
            continue;
        }
        REP(i,m){
            DRII(x,y);
            x--;y--;
            e[x].PB(y);
            e[y].PB(x);
        }
        bool suc=0;
        REP(i,n){
            if(used[i]!=tt){
                num[0]=num[1]=0;
                if(dfs(i,0))suc=1;
                else{
                    if(num[0]+num[1]>2){
                        if(add==2)an=0;
                        add=1;
                        an+=(num[0]*(num[0]-1LL)+num[1]*(num[1]-1LL))/2;
                    }
                    else if(num[0]+num[1]==2&&add==2){
                        an+=(n-2);
                    }
                }
            }
        }
        if(suc)puts("0 1");
        else{
            printf("%d %I64d\n",add,an);
        }
    }
}