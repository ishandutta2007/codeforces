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
const int SIZE = 2e5+10;
// template end here
VPII e[SIZE],emp;
int N,L,R;
int NUM[SIZE];
int d[SIZE],dn;
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
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
int ans_id;
double ans_v;
double tmp_v;
void dfs9(int x,int v,int lt){
    tmp_v+=pow(v,1.5)*NUM[x];
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs9(y,v+e[x][i].S,x);
    }
}
void fresh(int x){
    tmp_v=0;
    dfs9(x,0,x);
    if(tmp_v<ans_v){
        ans_id=x;
        ans_v=tmp_v;
    }
}
double delta[SIZE];
int from;
void dfs5(int x,int lt,int v){
    delta[from]+=sqrt(v)*NUM[x];
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs5(y,x,v+e[x][i].S);
    }
}
void dfs3(int x,int lt){
    if(used[x]==tt)return;
    used[x]=tt;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y!=lt)dfs3(y,x);
    }
}
bool Go(){
    tt++;
    REP(i,SZ(qq)){
        int me=qq[i];
        if(used[me]==tt)continue;
        fresh(me);
        used[me]=tt;
        double sum=0;
        REP(i,SZ(e[me])){
            from=e[me][i].F;
            delta[from]=0;
            dfs5(from,me,e[me][i].S);
            sum+=delta[from];
        }
        REP(i,SZ(e[me])){
            int y=e[me][i].F;
            if(delta[y]*2-sum<1e-12){
                dfs3(y,me);
            }
        }
    }
    return 0;
}
int main(){
    RI(N);
    dn=0;
    REP(i,N)e[i]=emp;
    REP(i,N)RI(NUM[i]);
    REPP(i,1,N){
        DRIII(x,y,v);
        x--;y--;
        e[x].PB(MP(y,v));
        e[y].PB(MP(x,v));
    }
    init();
    ans_v=1e100;
    Go();
    printf("%d %.9f\n",ans_id+1,ans_v);
    return 0;
}