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
const int INF = 1e9+7;
const int SIZE = 1e5+10;
// 1-based
int qq[SIZE][3],pos[SIZE];
vector<int>e[SIZE],IDs[SIZE],ker[SIZE];
set<int>an[SIZE];
int jump[17][SIZE],lv[SIZE],N;
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=16;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int root){
    __init(root,root);
    REPP(i,1,17){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
bool in_queue[SIZE];
struct SegTree{
    priority_queue<PII,VPII,greater<PII> >H[SIZE*4];
    int l,r,x,v;
    void ins(int L,int R,int id){
        H[id].push(MP(v,x));
        if(L==R)return;
        int mm=(L+R)>>1;
        if(x<=mm)ins(L,mm,id*2);
        else ins(mm+1,R,id*2+1);
    }
    PII qq(int L,int R,int id){
        if(L>r||R<l)return MP(INF,-1);
        if(L>=l&&R<=r){
            while(!H[id].empty()){
                if(in_queue[H[id].top().F])return H[id].top();
                H[id].pop();
            }
            return MP(INF,-1);
        }
        int mm=(L+R)>>1;
        return min(qq(L,mm,id*2),qq(mm+1,R,id*2+1));
    }
}seg;
void dfs(int x,int lt){
    REP(i,SZ(IDs[x])){
        int me=IDs[x][i];
        seg.x=lv[x];
        seg.v=me;
        seg.ins(0,N-1,1);
        in_queue[me]=1;
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(lt==y)continue;
        dfs(y,x);
    }
    REP(i,SZ(ker[x])){
        int me=ker[x][i];
        int z=lca(x,qq[me][0]+qq[me][1]-x);
        VPII tmp;
        seg.l=lv[z];
        seg.r=lv[x];
        REP(k,qq[me][2]){
            PII now=seg.qq(0,N-1,1);
            if(now.F==INF)break;
            an[me].insert(now.F);
            tmp.PB(now);
            in_queue[now.F]=0;
        }
        REP(k,SZ(tmp)){
            seg.x=tmp[k].S;
            seg.v=tmp[k].F;
            in_queue[tmp[k].F]=1;
            seg.ins(0,N-1,1);
        }
    }
    REP(i,SZ(IDs[x])){
        in_queue[IDs[x][i]]=0;
    }
}
int main(){
    DRIII(n,m,q);
    N=n;
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    build(1);
    REPP(i,1,m+1){
        DRI(x);
        IDs[x].PB(i);
    }
    REPP(i,1,n+1){
        if(SZ(IDs[i])>10)IDs[i].resize(10);
    }
    REP(i,q){
        REP(j,3){
            RI(qq[i][j]);
        }
        ker[qq[i][0]].PB(i);
        ker[qq[i][1]].PB(i);
    }
    dfs(1,1);
    REP(i,q){
        int num=min(qq[i][2],SZ(an[i]));
        printf("%d",num);
        set<int>::iterator it=an[i].begin();
        REP(i,num){
            printf(" %d",*it);
            it++;
        }
        puts("");
    }
    return 0;
}