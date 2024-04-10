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
VPII e[SIZE];
int col;
int tt,visited[SIZE],v[SIZE],xx[SIZE],yy[SIZE],zz[SIZE];
bool used[SIZE];
VI an1,an2,an;
VI tmp;
bool suc;
bool dfs(int x){
    used[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int me=e[x][i].S;
        if(visited[y]==tt){
            if((v[x]^v[y]^me)!=col){
                suc=0;
                return 0;
            }
        }
        else{
            visited[y]=tt;
            v[y]=me^v[x]^col;
            if(v[y])tmp.PB(y);
            if(!dfs(y))return 0;
        }
    }
    return 1;
}
void check(int x,int y,int cc,VI& mi){
    mi.clear();
    mi.PB(-1);
    bool ker=0;
    suc=1;
    tt++;
    visited[x]=visited[y]=tt;
    v[x]=v[y]=0;
    tmp.clear();
    dfs(x);
    dfs(y);
    if(suc&&(!ker||SZ(tmp)<SZ(mi))){
        ker=1;
        mi=tmp;
    }
    
    suc=1;
    tt++;
    visited[x]=visited[y]=tt;
    v[x]=1;v[y]=0;
    tmp.clear();
    tmp.PB(x);
    dfs(x);
    dfs(y);
    if(suc&&(!ker||SZ(tmp)<SZ(mi))){
        ker=1;
        mi=tmp;
    }
    
    suc=1;
    tt++;
    visited[x]=visited[y]=tt;
    v[x]=0;v[y]=1;
    tmp.clear();
    tmp.PB(y);
    dfs(x);
    dfs(y);
    if(suc&&(!ker||SZ(tmp)<SZ(mi))){
        ker=1;
        mi=tmp;
    }
    
    suc=1;
    tt++;
    visited[x]=visited[y]=tt;
    v[x]=v[y]=1;
    tmp.clear();
    tmp.PB(x);
    tmp.PB(y);
    dfs(x);
    dfs(y);
    if(suc&&(!ker||SZ(tmp)<SZ(mi))){
        ker=1;
        mi=tmp;
    }
}
int main(){
    bool fail1=0,fail2=0;
    DRII(n,m);
    REP(i,m){
        DRII(x,y);
        xx[i]=x;yy[i]=y;
        char c[4];
        RS(c);
        zz[i]=(c[0]=='B')?1:0;
        e[x].PB(MP(y,c[0]=='B'?1:0));
        e[y].PB(MP(x,c[0]=='B'?1:0));
    }
    col=0;
    REP(i,m){
        if(used[xx[i]])continue;
        VI res;
        check(xx[i],yy[i],zz[i],res);
        if(SZ(res)==1&&res[0]==-1){
            fail1=1;
            break;
        }
        REP(i,SZ(res))an1.PB(res[i]);
    }

    MS0(used);
    col=1;
    REP(i,m){
        if(used[xx[i]])continue;
        VI res;
        check(xx[i],yy[i],zz[i],res);
        if(SZ(res)==1&&res[0]==-1){
            fail2=1;
            break;
        }
        REP(i,SZ(res))an2.PB(res[i]);
    }
    if(fail1&&fail2)return 0*puts("-1");
    if(fail1)an=an2;
    else if(fail2)an=an1;
    else{
        if(SZ(an1)<SZ(an2))an=an1;
        else an=an2;
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an))printf("%d ",an[i]);
    return 0;
}