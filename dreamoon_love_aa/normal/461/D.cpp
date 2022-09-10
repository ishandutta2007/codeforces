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
#define V(X) ((X)+MID)
const int MOD = 1e9+7;
const int SIZE = 1e6;
vector<pair<int,int> >e[SIZE];
int bb,used[SIZE],N;
void join(int x,int y,int v){
    int xx=x+y-1;
    int yy=x-y+N+(2*N+1);
    e[xx].PB(MP(yy,v));
    e[yy].PB(MP(xx,v));
}
bool dfs(int x){
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(!used[y]){
            used[y]=used[x]*e[x][i].S;
            if(!dfs(y))return false;
        }
        else{
            if(used[y]!=used[x]*e[x][i].S)return false;
        }
    }
    return true;
}
int main(){
    DRII(n,K);
    N=n;
    if(n==1){
        if(K==0)puts("2");
        else puts("1");
        return 0;
    }
    bb=4*n+2;
    REPP(i,1,n+1){
        join(0,i,1);
        join(n+1,i,1);
        join(i,0,1);
        join(i,n+1,1);
    }
    REP(i,K){
        DRII(x,y);
        char cc[4];
        RS(cc);
        join(x,y,cc[0]=='x'?1:-1);
    }
    LL an=1;
    int sub=2;
    REP(i,bb){
        if(!used[i]){
            used[i]=1;
            if(!dfs(i)){
                puts("0");
                return 0;
            }
            if(sub>0)sub--;
            else{
                an*=2;
                an%=MOD;
            }
        }
    }
    cout<<an<<endl;
    return 0;
}