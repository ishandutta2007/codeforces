/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int m,n; 
int bfs[9765625],from[9765625];
PII record[9765625];
int record_dir[9765625];
int step[9765625];
bool Out(int x,int y){return x<0||x>=n||y<0||y>=n;}
int get(PII a[]){
    int ret=0;
    REP(i,m){
        ret=ret*n*n+a[i].F*n+a[i].S;
    }
    return ret;
}
void get2(PII AA[],int now){
    for(int j=m-1;j>=0;j--){
        AA[j].S=now%n;
        now/=n;
        AA[j].F=now%n;
        now/=n;
    }
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void print_small(int id){
    if(!id)return;
    id=bfs[id];
    print_small(from[id]);
    W(record[id].F+1,record[id].S+1,record[id].F+1+dx[record_dir[id]],record[id].S+1+dy[record_dir[id]]);
}
void solve_small(){
    PII st[5];
    PII ed[5];
    REP(i,m){
        R(st[i].F,st[i].S);
        st[i].F--;
        st[i].S--;
    }
    REP(i,m){
        R(ed[i].F,ed[i].S);
        ed[i].F--;
        ed[i].S--;
    }
    int ed_id=get(ed);
    bfs[0]=get(st);
    MS1(from);
    int rr=1;
    REP(i,rr){
        if(bfs[i]==ed_id){
            W(step[i]);
            print_small(i);
            return;
        }
        PII AA[5];
        get2(AA,bfs[i]);
        REP(j,m){
            REP(k,4){
                PII nxt={AA[j].F+dx[k],AA[j].S+dy[k]};
                if(Out(nxt.F,nxt.S))continue;
                bool err=0;
                REP(r,m){
                    if(nxt==AA[r]){
                        err=1;
                        break;
                    }
                }
                if(err)continue;
                swap(nxt,AA[j]);
                int v=get(AA);
                swap(nxt,AA[j]);
                if(from[v]==-1){
                    from[v]=i;
                    record[v]=AA[j];
                    record_dir[v]=k;
                    step[rr]=step[i]+1;
                    bfs[rr++]=v;
                }
            }
        }
    }
}
bool u[51][51];
int connect(VPII &ban,PII st,PII ed){
    MS0(u);
    REP(i,SZ(ban)){
        u[ban[i].F][ban[i].S]=1;
    }
    VPII bfs;
    VI v{0};
    bfs.PB(st);
    REP(i,SZ(bfs)){
        if(bfs[i]==ed){
            return v[i];
        }
        REP(j,4){
            PII nxt={bfs[i].F+dx[j],bfs[i].S+dy[j]};
            if(Out(nxt.F,nxt.S))continue;
            if(u[nxt.F][nxt.S])continue;
            u[nxt.F][nxt.S]=1;
            v.PB(v[i]+1);
            bfs.PB(nxt);
        }
    }
    return 1e9;
}
void add(VPII &ban,PII st,PII ed,VPII& res,bool type){
    MS0(u);
    REP(i,SZ(ban)){
        u[ban[i].F][ban[i].S]=1;
    }
    VPII tmp;
    VPII bfs;
    VI lt{0};
    VI v{0};
    bfs.PB(st);
    REP(i,SZ(bfs)){
        if(bfs[i]==ed){
            while(i){
                tmp.PB(bfs[i]);
                tmp.PB(bfs[lt[i]]);
                i=lt[i];
            }
            break;
        }
        REP(j,4){
            PII nxt={bfs[i].F+dx[j],bfs[i].S+dy[j]};
            if(Out(nxt.F,nxt.S))continue;
            if(u[nxt.F][nxt.S])continue;
            u[nxt.F][nxt.S]=1;
            lt.PB(i);
            v.PB(v[i]+1);
            bfs.PB(nxt);
        }
    }
    if(!type){
        for(auto x:tmp)res.PB(x);
    }
    else{
        reverse(ALL(tmp));
        for(auto x:tmp)res.PB(x);
    }
}
bool go(VPII st,VPII &target,VPII &res,bool type){
    VPII tmp;
    vector<VPII>gg(SZ(st));
    int it=0;
    while(st!=target){
        int mi=1e9;
        int id;
        REP(i,SZ(st)){
            if(st[i]==target[i])continue;
            int need_step=connect(st,st[i],target[i]);
            if(need_step<mi){
                id=i;
                mi=need_step;
            }
        }
        if(mi>1e8)return 0;
        if(type){
            add(st,st[id],target[id],res,type);
        }
        else{
            add(st,st[id],target[id],gg[it++],type);
        }
        st[id]=target[id];
    }
    if(!type){
        for(int i=SZ(gg)-1;i>=0;i--){
            for(auto x: gg[i])res.PB(x);
        }
    }
    return 1;
}
bool big_go(VPII &st,VPII &target,VPII &ed){
    VPII res;
    if(!go(st,target,res,1))return 0;
    if(!go(ed,target,res,0))return 0;
    W(SZ(res)/2);
    for(auto& x:res)x.F++,x.S++;
    for(int i=0;i<SZ(res);i+=2){
        W(res[i],res[i+1]);
    }
    return 1;
}
void solve_big(){
    VPII st(m);
    VPII ed(m);
    REP(i,m){
        R(st[i].F,st[i].S);
        st[i].F--;
        st[i].S--;
    }
    REP(i,m){
        R(ed[i].F,ed[i].S);
        ed[i].F--;
        ed[i].S--;
    }
    VPII target(m);
    VPII ker;
    int it=0;
    REPP(i,1,n-2){
        if(i%3&&it<m){
            ker.PB({0,i});
        }
        if(i%3&&it<m){
            ker.PB({i,n-1});
        }
        if(i%3&&it<m){
            ker.PB({n-1,n-1-i});
        }
        if(i%3&&it<m){
            ker.PB({n-1-i,0});
        }
    }
    while(1){
        random_shuffle(ALL(ker));
        REP(i,m)target[i]=ker[i];
        if(big_go(st,target,ed))return;
    }
}
int main(){
    R(n,m);
    if(n<5)solve_small();
    else solve_big();
    return 0;
}