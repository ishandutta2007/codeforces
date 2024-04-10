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
struct JellyFish{
    int jellyfish_id[SIZE],jn,cycle_len[SIZE];
    int lv[SIZE],ma_lv[SIZE],father[SIZE];
    LL sum[SIZE];
    VPII e0[SIZE];
    VI e[SIZE];
    int u[SIZE],qq[SIZE];
    void build_tree(int x){
        jellyfish_id[x]=jn;
        sum[jn]+=x+1;
        ma_lv[jn]=max(ma_lv[jn],lv[x]);
        REP(i,SZ(e0[x])){
            int y=e0[x][i].F;
            if(lv[y]==-1){
                father[y]=x;
                e[x].PB(y);
                lv[y]=lv[x]+1;
                build_tree(y);
            }
        }
    }
    bool dfs(int x,int uid,int from_eid){
        u[x]=uid;
        qq[uid]=x;
        REP(i,SZ(e0[x])){
            if(e0[x][i].S==from_eid)continue;
            int y=e0[x][i].F;
            if(u[y]>=0){
                cycle_len[jn]=uid-u[y]+1;
                REPP(j,u[y],uid+1){
                    lv[qq[j]]=0;
                }
                REPP(j,u[y],uid+1){
                    build_tree(qq[j]);
                }
                return 1;
            }
            else{
                if(dfs(y,uid+1,e0[x][i].S))return 1;
            }
        }
        return 0;
    }
    //id from 0 to n-1
    void build(int _p[],int n){
        REP(i,n){
            lv[i]=u[i]=jellyfish_id[i]=-1;
            e0[i].PB(MP(_p[i],i));
            if(_p[i]!=i){
                e0[_p[i]].PB(MP(i,i));
            }
        }
        jn=0;
        REP(i,n){
            if(jellyfish_id[i]==-1){
                dfs(i,0,-1);
                jn++;
            }
        }
    }
}fish;
int v[SIZE],AA[SIZE];
VI ker[SIZE];
int main(){
    int n; R(n);
    REP(i,n)R(v[i]);
    REP(i,n){
        R(AA[i]);
        AA[i]--;
    }
    fish.build(AA,n);
    REP(i,n){
        if(!fish.lv[i])ker[fish.jellyfish_id[i]].PB(v[i]);
    }
    LL an=0;
    REP(i,n){
        if(SZ(ker[i])){
            an+=*min_element(ALL(ker[i]));
        }
    }
    W(an);
    return 0;
}