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
const int SIZE = 71;
int get_bit(int x,int v){return (x>>v)&1;}
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int dis[SIZE][SIZE];
VI e[SIZE];
void add_edge(PII _){
    int x=_.F;
    int y=_.S;
    e[x].PB(y);
    e[y].PB(x);
}
VPII e0[SIZE];
int n,m,a,b;
int sp_id[SIZE];
int sp_num;
VPII ee0;
int dp[SIZE][1<<18];
bitset<(1<<18)>used[SIZE];
int an[SIZE];
bool update(int &x,int v){
    if(x>v||x==-1){
        x=v;
        return 1;
    }
    return 0;
}
int main(){
    MS1(an);
    MS1(dp);
    MS1(sp_id);
    R(n,m,a,b);
    U.init(n);
    REP(i,n)REP(j,n)dis[i][j]=MOD;
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        if(v==a){
            U.uu(x,y);
            dis[x][y]=dis[y][x]=v;
        }
        else{
            ee0.PB({x,y});
        }
    }
    REP(k,n)REP(i,n)REP(j,n){
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    }
    REP(i,SZ(ee0)){
        if(U.find(ee0[i].F)!=U.find(ee0[i].S)){
            add_edge(ee0[i]);
        }
    }
    REP(i,n){
        REP(j,n){
            if(dis[i][j]<MOD){
                e0[i].PB({j,dis[i][j]});
            }
        }
    }
    {
        REP(i,n){
            if(sp_id[i]==-1&&U.num[U.find(i)]>3){
                REP(j,n){
                    if(U.find(j)==U.find(i))sp_id[j]=sp_num;
                }
                sp_num++;
            }
        }
    }
    priority_queue<pair<int,PII>,vector<pair<int,PII>>,greater<pair<int,PII>>>pq;
    an[0]=0;
    dp[0][(sp_id[0]==-1)?0:(1<<sp_id[0])]=0;
    pq.push({0,{0,(sp_id[0]==-1)?0:(1<<sp_id[0])}});
    while(!pq.empty()){
        auto now=pq.top(); pq.pop();
        int v=now.F;
        int id=now.S.F;
        int mask=now.S.S;
        if(used[id][mask])continue;
        update(an[id],v);
        used[id][mask]=1;
        for(auto y:e0[id]){
            if(update(dp[y.F][mask],v+y.S)){
                pq.push({dp[y.F][mask],{y.F,mask}});
            }
        }
        for(int y: e[id]){
            if(sp_id[y]!=-1&&get_bit(mask,sp_id[y]))continue;
            int nxt_mask=mask;
            if(sp_id[y]!=-1)nxt_mask=mask|(1<<sp_id[y]);
            if(update(dp[y][nxt_mask],v+b)){
                pq.push({dp[y][nxt_mask],{y,nxt_mask}});
            }
        }
    }
    W(VI(an,an+n));
    return 0;
}