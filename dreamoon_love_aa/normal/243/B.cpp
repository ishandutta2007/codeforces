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
int tt,s[SIZE];
int h,t;
void check(int x,int y){
    if(SZ(e[x])<=h||SZ(e[y])<=t)return;
    int same=0;
    tt++;
    int bb1=min(SZ(e[x]),205);
    REP(i,bb1)
        s[e[x][i]]=tt;
    VI ker[3];
    int bb2=min(SZ(e[y]),205);
    REP(i,bb2){
        if(e[y][i]==x)continue;
        if(s[e[y][i]]==tt){
            ker[1].PB(e[y][i]);
            same++;
            s[e[y][i]]=-1;
        }
        else ker[2].PB(e[y][i]);
    }
    REP(i,bb1){
        if(s[e[x][i]]!=-1&&e[x][i]!=y)ker[0].PB(e[x][i]);
    }
    if(SZ(ker[0])+SZ(ker[1])+SZ(ker[2])>=h+t){
        puts("YES");
        printf("%d %d\n",x,y);
        VI res[2];
        REP(i,SZ(ker[0])){
            if(h>0){
                h--;
                res[0].PB(ker[0][i]);
            }
            else break;
        }
        REP(i,SZ(ker[2])){
            if(t>0){
                t--;
                res[1].PB(ker[2][i]);
            }
            else break;
        }
        REP(i,SZ(ker[1])){
            if(t>0){
                t--;
                res[1].PB(ker[1][i]);
            }
            else if(h>0){
                h--;
                res[0].PB(ker[1][i]);
            }
            else break;
        }
        REP(i,2){
            REP(j,SZ(res[i]))printf("%d ",res[i][j]);
            puts("");
        }
        exit(0);
    }
}
int main(){
    DRII(n,m);
    RII(h,t);
    REP(i,m){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    REPP(i,1,n+1){
        REP(j,SZ(e[i])){
            check(i,e[i][j]);
        }
    }
    puts("NO");
    return 0;
}