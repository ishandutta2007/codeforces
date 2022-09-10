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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e5+10;
// template end here
VPII e[SIZE],emp;
// a*x+b*y=z
struct gcd_t {long long x,y,z;};
gcd_t gcd(long long a,long long b) {
    if(b==0)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
int N,M;
int ten[SIZE];
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
LL an;
vector<int>qq;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void build(int st){
    bfs[0]=st;
    tt2--;
    used[st]=tt2;
    int i=0,j=1;
    for(;i<j;i++){
        int x=bfs[i];
        sons[x]=1;
        REP(k,SZ(e[x])){
            int y=e[x][k].F;
            if(used[y]==tt||used[y]==tt2)continue;
            father[y]=x;
            used[y]=tt2;
            bfs[j++]=y;
        }
    }
    int num=j;
    for(i=j-1;i>=0;i--){
        int x=bfs[i];
        if(sons[x]*2>=num){
            qq.PB(x);
            used[x]=tt;
            REP(k,SZ(e[x])){
                int y=e[x][k].F;
                if(used[y]!=tt)build(y);
            }
            return;
        }
        sons[father[x]]+=sons[x];
    }
}
void init(){
    tt++;
    qq.clear();
    build(0);
}
int step[SIZE],r[SIZE][2];
map<int,int>H,revH,rev_h[SIZE];
VPII h[SIZE];
void add(int st,int v){
    bfs[0]=st;
    r[st][0]=r[st][1]=v%M;
    step[st]=1;
    int i=0,j=1;
    tt2--;
    used[st]=tt2;
    for(;i<j;i++){
        int x=bfs[i];
        REP(k,SZ(e[x])){
            int y=e[x][k].F;
            if(used[y]==tt||used[y]==tt2)continue;
            used[y]=tt2;
            step[y]=step[x]+1;
            r[y][0]=(r[x][0]*10LL+e[x][k].S)%M;
            r[y][1]=(e[x][k].S*(LL)ten[step[x]]+r[x][1])%M;
            bfs[j++]=y;
        }
    }
    REP(k,i){
        int y=bfs[k];
        h[st].PB(MP(r[y][0],step[y]));
        rev_h[st][r[y][1]]++;
        H[r[y][0]]++;
        revH[r[y][1]]++;
    }
}
void go(){
    tt++;
    REP(i,SZ(qq)){
        VI all;
        int me=qq[i];
        used[me]=tt;
        H.clear();revH.clear();
        REP(j,SZ(e[me])){
            int you=e[me][j].F;
            if(used[you]!=tt){
                all.PB(you);
                h[you].clear();rev_h[you].clear();
                add(you,e[me][j].S);
            }
        }
        an+=H[0]+revH[0];
        REP(k,SZ(all)){
            int id=all[k];
            REP(j,SZ(h[id])){
                gcd_t gg=gcd(M,ten[h[id][j].S]);
                if(gg.y<0)gg.y+=M;
                int need=(LL)(M-h[id][j].F)%M*gg.y%M;
                an+=revH[need]-rev_h[id][need];
            }
        }
    }
}
int main(){
    {
        tt++;
        RII(N,M);
        if(M==1){
            printf("%I64d\n",N*(N-1LL));
            return 0;
        }
        ten[0]=1;
        REPP(i,1,SIZE){
            ten[i]=ten[i-1]*10LL%M;
        }
        REP(i,N)e[i]=emp;
        REPP(i,1,N){
            DRIII(x,y,v);
            e[x].PB(MP(y,v));
            e[y].PB(MP(x,v));
        }
        init();
        go();
        printf("%I64d\n",an);
    }
    return 0;
}