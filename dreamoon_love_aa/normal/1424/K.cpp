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
#define PB emplace_back
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int N,ss,D;
bitset<1000>swith[30],tmp[30],bfs[1<<16];
int need[1<<16];
int op[30];
int n;
int use[30];
void my_swap(int x,int y){
    swap(swith[x],swith[y]);
    swap(use[x],use[y]);
}
int nxt[65536000][2];
int res[65536000];
int nxt_it;
int add(bitset<1000>&me,int v){
    int now=0;
    REP(i,1000){
        if(!nxt[now][me[i]]){
            nxt[now][me[i]]=++nxt_it;
        }
        now=nxt[now][me[i]];
    }
    if(res[now]==-1){
        res[now]=v;
        return v;
    }
    return -1;
}
int qq(bitset<1000>&me){
    int now=0;
    REP(i,1000){
        if(!nxt[now][me[i]]){
            return -1;
        }
        now=nxt[now][me[i]];
    }
    return res[now];
}
void solve1(){
    MS1(res);
    add(bfs[0],0);
    int rr=1;
    REP(i,rr){
        REP(j,ss){
            bfs[rr]=bfs[i]^tmp[j];
            int ret=add(bfs[rr],need[i]+1);
            if(ret!=need[i]+1)continue;
            need[rr++]=need[i]+1;
            rr++;
        }
    }
    REP(i,D){
        bitset<1000>now;
        int t;
        R(t);
        REP(j,t){
            int x;
            R(x);
            now[x-1]=1;
        }
        W(qq(now));
    }
}
int an;
void dfs(int me,int id){
    if(id==ss){
        an=min(an,__builtin_popcount(me));
        return;
    }
    dfs(me^use[id],id+1);
    dfs(me,id+1);
}
void solve2(){
    REP(i,D){
        bitset<1000>now;
        int t;
        R(t);
        REP(j,t){
            int x;
            R(x);
            now[x-1]=1;
        }
        int me=0;
        REP(j,n){
            if(now[op[j]]){
                now^=swith[j];
                me^=use[j];
            }
        }
        if(now.count()){
            W(-1);
        }else{
            an=30;
            dfs(me,n);
            W(an);
        }
    }
}
void build(){
    n=0;
    REP(i,N){
        int found=-1;
        REPP(j,n,ss){
            if(swith[j][i]){
                found=j;
                break;
            }
        }
        if(found==-1){
            continue;
        }
        op[n]=i;
        if(found!=n){
            my_swap(found,n);
        }
        REP(j,ss){
            if(j==n)continue;
            if(swith[j][i]){
                swith[j]^=swith[n];
                use[j]^=use[n];
            }
        }
        n++;
    }
    if(n<16){
        solve1();
    }else{
        solve2();
    }
}
void input() {
    R(N,ss,D);
    REP(i,ss){
        int C;
        R(C);
        use[i]=1<<i;
        REP(j,C){
            int x;
            R(x);
            swith[i][x-1]=1;
        }
        tmp[i]=swith[i];
    }
}
int main(){
    input();
    build();
    return 0;
}