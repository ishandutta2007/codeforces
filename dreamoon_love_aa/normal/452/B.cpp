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
int n,m;
bool Out(int x,int y){return x<0||y<0||x>n||y>m;}
double ma;
int used[10000];
vector<pair<int,int> >p;
int qq[4],an[4];
double sqr(double x){return x*x;}
void dfs(int x,double v){
    if(x==4){
        if(v>ma){
            ma=v;
            REP(i,4)an[i]=qq[i];
        }
        return;
    }
    REP(i,SZ(p)){
        if(Out(p[i].F,p[i].S))continue;
        if(used[i])continue;
        used[i]=1;
        qq[x]=i;
        if(x>=1){
            dfs(x+1,v+sqrt(sqr(p[qq[x-1]].F-p[i].F)+sqr(p[qq[x-1]].S-p[i].S)));
        }
        else dfs(x+1,v);
        used[i]=0;
    }
}
int main(){
    RII(n,m);
    REP(i,4)REP(j,4){
        p.PB(MP(i,j));
        p.PB(MP(i,m-j));
        p.PB(MP(n-i,m-j));
        p.PB(MP(n-i,j));
    }
    sort(ALL(p));
    p.resize(unique(ALL(p))-p.begin());
    ma=0;
    dfs(0,0);
    REP(i,4)printf("%d %d\n",p[an[i]].F,p[an[i]].S);
    return 0;
}