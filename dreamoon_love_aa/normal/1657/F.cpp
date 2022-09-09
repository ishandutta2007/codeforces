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
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<19;

int n,q;
VI e[SIZE];
int par[SIZE];
int lv[SIZE];
vector<tuple<int,char,char>>AA[SIZE];
void dfs0(int x, int lt) {
    par[x]=lt;
    for(int y:e[x]){
        if(y==lt)continue;
        lv[y]=lv[x]+1;
        dfs0(y,x);
    }
}
int must[SIZE][2];
VPII e2[SIZE];
void err() {
    W("NO");
    exit(0);
}
void try_to_match(const tuple<int,char,char>& x, const tuple<int,char,char>& y) {
    //DEBUG(get<0>(x),get<1>(x),get<2>(x));
    //DEBUG(get<0>(y),get<1>(y),get<2>(y));
    if(get<1>(x)==get<2>(x)&&get<1>(y)==get<2>(y)&&get<1>(x)==get<1>(y))return;
    if(get<1>(x)==get<2>(x)){
        if(get<1>(y)==get<1>(x)){
            must[get<0>(y)][0]=1;
        }else if(get<2>(y)==get<1>(x)){
            must[get<0>(y)][1]=1;
        }else{
            err();
        }
    }
    else if(get<1>(y)==get<2>(y)){
        if(get<1>(x)==get<1>(y)){
            must[get<0>(x)][0]=1;
        }else if(get<2>(x)==get<1>(y)){
            must[get<0>(x)][1]=1;
        }else{
            err();
        }
    }else{
        if(get<1>(x)==get<1>(y)&&get<2>(x)==get<2>(y)){
            e2[get<0>(x)].PB(MP(get<0>(y),0));
            e2[get<0>(y)].PB(MP(get<0>(x),0));
        }else if(get<1>(x)==get<2>(y)&&get<2>(x)==get<1>(y)){
            e2[get<0>(x)].PB(MP(get<0>(y),1));
            e2[get<0>(y)].PB(MP(get<0>(x),1));
        }else{
            if(get<1>(x)==get<1>(y)){
                must[get<0>(x)][0]=1;
                must[get<0>(y)][0]=1;
            }else if(get<1>(x)==get<2>(y)){
                must[get<0>(x)][0]=1;
                must[get<0>(y)][1]=1;
            }else if(get<2>(x)==get<1>(y)){
                must[get<0>(x)][1]=1;
                must[get<0>(y)][0]=1;
            }else if(get<2>(x)==get<2>(y)){
                must[get<0>(x)][1]=1;
                must[get<0>(y)][1]=1;
            }else{
                err();
            }
        }
    }
}
int fr[SIZE],bk[SIZE];
bitset<SIZE>visited;
int res[SIZE];
bool dfs_check(int x, int ty){
    res[x]=ty;
    if(must[x][res[x]^1]){
        return 0;
    }
    visited[x]=1;
    REP(i,SZ(e2[x])){
        int y=e2[x][i].F;
        int v=e2[x][i].S;
        if(res[y]==-1){
            if(!dfs_check(y, ty^v))return 0;
        }else{
            if(res[y]!=(res[x]^v))return 0;
        }
    }
    return 1;
}
void solve() {
    dfs0(1,1);
    REP(id,q){
        int x,y;
        string s;
        R(x,y,s);
        int fr_n=0,bk_n=0;
        while(x!=y){
            if(lv[x]>=lv[y]){
                fr[fr_n++]=x;
                x=par[x];
            }else{
                bk[bk_n++]=y;
                y=par[y];
            }
        }
        fr[fr_n++]=x;
        for(bk_n--;bk_n>=0;bk_n--)fr[fr_n++]=bk[bk_n];
        //DEBUG("list:",VI(fr,fr+fr_n));
        //DEBUG("s:",s);
        REP(i,fr_n){
            AA[fr[i]].PB(make_tuple(id,s[i],s[fr_n-1-i]));
        }
    }
    FOR(i,1,n){
        REPP(j,1,SZ(AA[i])){
            try_to_match(AA[i][j],AA[i][j-1]);
        }
    }
    REP(i,q){
        res[i]=-1;
        if(must[i][0]&&must[i][1])err();
    }
    REP(i,q){
        if(must[i][0]||must[i][1]){
            if(!visited[i]){
                if(!dfs_check(i,must[i][0]?0:1)){
                    err();
                }
            }
        }
    }
    REP(i,q){
        if(!visited[i]){
            if(!dfs_check(i,0)){
                err();
            }
        }
    }
    W("YES");
    FOR(i,1,n){
        if(!SZ(AA[i])){
            putchar('a');
        }else{
            if(res[get<0>(AA[i][0])]==0){
                putchar(get<1>(AA[i][0]));
            }else{
                putchar(get<2>(AA[i][0]));
            }
        }
    }
    W("");
}
void input() {
    R(n,q);
    REPP(i,1,n){
        int u,v;
        R(u,v);
        e[u].PB(v);
        e[v].PB(u);
    }
}
int main(){
    input();
    solve();
    return 0;
}