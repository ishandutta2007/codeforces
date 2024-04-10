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
VL d[15];
LL sum[15];
LL all=0;
map<LL,int>ids;
int _id;
PLL v[5000*15];
VPLL tag[1<<15];
int u[5000*15];
int get_bit(int x,int _v){return (x>>_v)&1;}
int dp[1<<15],from[1<<15];
bool solve(){
    int n; R(n);
    REP(i,n){
        int m; R(m);
        REP(j,m){
            int x;
            R(x);
            d[i].PB(x);
            sum[i]+=x;
            all+=x;
            v[_id]={i,x};
            ids[x]=_id++;
        }
    }
    if(all%n){
        return 0;
    }
    LL need=all/n;
    REP(i,n){
        for(LL x:d[i]){
            int me=ids[x];
            int mask=0;
            int now=me;
            bool fail=0;
            VPLL gg;
            while(!u[now]){
                gg.PB(v[now]);
                mask|=1<<v[now].F;
                LL nxt_v=v[now].S+need-sum[v[now].F];
                if(nxt_v==x){
                    break;
                }
                if(!ids.count(nxt_v)){
                    fail=1;
                    break;
                }
                int nxt=ids[nxt_v];
                if(get_bit(mask,v[nxt].F)){
                    fail=1;
                    break;
                }
                now=nxt;
            }
            if(fail)continue;
            if(!tag[mask].empty())continue;
            tag[mask]=gg;
        }
    }
    dp[0]=1;
    REPP(i,1,1<<n){
        for(int j=i;j>=i-j;j=(j-1)&i){
            if(SZ(tag[j])&&dp[i^j]){
                from[i]=i^j;
                dp[i]=1;
                break;
            }
        }
    }
    if(!dp[(1<<n)-1]){
        return 0;
    }
    PLL an[15];
    {
        int me=(1<<n)-1;
        while(me){
            int use=me^from[me];
            REP(i,SZ(tag[use])){
                //W(tag[use][i].S,need,sum[tag[use][i].F]);
                an[tag[use][i].F]={tag[use][i].S,tag[use][(i-1+SZ(tag[use]))%SZ(tag[use])].F+1};
            }
            me=from[me];
        }
    }
    W("Yes");
    REP(i,n){
        W(an[i]);
    }
    return 1;
}
int main(){
    if(!solve())W("No");
    return 0;
}