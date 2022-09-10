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
const int SIZE = 1e3+10;
struct Union_Find{
    int d[SIZE];
    void init(int n){
        REP(i,n+1)d[i]=i;
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
vector<int>gg[SIZE],oo[SIZE];
int p[SIZE],an[SIZE];
bool compare(int x,int y){
    return p[x]<p[y];
}
char s[SIZE];
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(p[i]);
    U.init(n);
    REP(i,n){
        RS(s);
        REP(j,n)
            if(s[j]=='1')U.uu(i+1,j+1);
    }
    REPP(i,1,n+1){
        gg[U.find(i)].PB(i);
        oo[U.find(i)].PB(i);
    }
    REPP(i,1,n+1){
        if(SZ(gg[i])){
            sort(ALL(gg[i]),compare);
            REP(j,SZ(gg[i]))an[oo[i][j]]=p[gg[i][j]];
        }
    }
    REPP(i,1,n+1){
        if(i!=1)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}