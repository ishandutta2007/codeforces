#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1.1e6;
int d[SIZE],g,r;
int n,m;
int bfs[10000];
bitset<1001>now,pre[2],nxt[10000],mask;
const int AA = 1000;
bitset<2001>e[10000];
bitset<10000>u;
int dis[10000];
int used[1001],tt;
int main(){
    R(n,m);
    REP(i,m){
        R(d[i]);
    }
    sort(d,d+m);
    R(g,r);
    FOR(i,0,g)mask[i]=1;
    pre[0][0]=1;
    nxt[m-1][g]=1;
    for(int i=m-2;i>=0;i--){
        int dif=d[i+1]-d[i];
        for(int j=2*dif;j<=g;j+=2*dif){
            nxt[i]|=nxt[i+1]>>j;
        }
        nxt[i][g]=1;
    }
    REP(i,m){
        now=pre[i&1];
        tt++;
        REPP(j,i+1,m){
            if(d[j]-d[i]>g)break;
            int dif=d[j]-d[j-1];
            if(used[dif]!=tt){
                used[dif]=tt;
                for(int k=dif*2,k2=0;k+d[j]-d[i]<=g;k++,k2++){
                    if(now[k2])now[k]=1;
                }
            }
            if((((now<<(d[j]-d[i]))&nxt[j])&mask).any()){
                e[i][AA+j-i]=e[j][AA+i-j]=1;
            }

        }
        if(i+1<m){
            int dif=d[i+1]-d[i];
            int nxt_i=(i+1)&1;
            pre[nxt_i].reset();
            pre[nxt_i][0]=1;
            for(int j=2*dif;j<=g;j+=2*dif){
                pre[nxt_i]|=pre[i&1]<<j;
            }
        }
    }
    int rr=1;
    u[0]=1;
    REP(i,rr){
        int x=bfs[i];
        FOR(j,1,m-1-x){
            if(d[x+j]-d[x]>g)break;
            if(e[x][j+AA]&&!u[x+j]){
                u[x+j]=1;
                bfs[rr++]=x+j;
                dis[x+j]=dis[x]+1;
            }
        }
        FOR(j,1,x){
            if(d[x]-d[x-j]>g)break;
            if(e[x][AA-j]&&!u[x-j]){
                u[x-j]=1;
                bfs[rr++]=x-j;
                dis[x-j]=dis[x]+1;
            }
        }
    }
    int an=1e9;
    REP(i,m-1){
        if(!u[i]){
            continue;
        }
        if(d[i]+g>=n){
            an=min(an,dis[i]*(r+g)+n-d[i]);
        }
    }
    if(an>5e8)W(-1);
    else W(an);
    return 0;
}