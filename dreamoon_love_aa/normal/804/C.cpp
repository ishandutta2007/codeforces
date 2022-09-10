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
VI cc[SIZE],e[SIZE];
int an[SIZE];
int used[SIZE],tt;
void dfs(int x,int lt){
    tt++;
    REP(i,SZ(cc[x])){
        int c=cc[x][i];
        if(an[c])used[an[c]]=tt;
    }
    int it=1;
    REP(i,SZ(cc[x])){
        int c=cc[x][i];
        if(!an[c]){
            while(used[it]==tt)it++;
            used[it]=tt;
            an[c]=it;
        }
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
    }
}
int main(){
    DRII(n,m);
    int ma=0,root;
    REPP(i,1,n+1){
        DRI(cn);
        REP(j,cn){
            DRI(x);
            cc[i].PB(x);
        }
        if(cn>ma){
            root=i;
            ma=cn;
        }
    }
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    if(ma==0){
        puts("1");
        REPP(i,1,m+1)printf("%d%c",1," \n"[i==n]);
    }
    else{
        REP(i,SZ(cc[root])){
            an[cc[root][i]]=i+1;
        }
        dfs(root,root);
        printf("%d\n",ma);
        REPP(i,1,m+1)printf("%d%c",max(1,an[i])," \n"[i==m]);
    }
    return 0;
}