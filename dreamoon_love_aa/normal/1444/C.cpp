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
#define UnionFindSIZE 1234567
int sn;
pair<int*,int>stk[SIZE*25];
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE],v[UnionFindSIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    void pop_all(){
        for(int i=sn-1;i>=0;i--){
            *stk[i].F=stk[i].S;
        }
        sn=0;
    }
    bool uu(int x,int y,bool saved=0){
        int tmp_v=1;
        while(x!=d[x]){
            tmp_v^=v[x];
            x=d[x];
        }
        while(y!=d[y]){
            tmp_v^=v[y];
            y=d[y];
        }
        if(x==y){
            return 1-tmp_v;
        }
        if(num[x]>num[y])swap(x,y);
        if(saved){
            stk[sn++]=MP(&num[y],num[y]);
            stk[sn++]=MP(&d[x],d[x]);
            stk[sn++]=MP(&v[x],v[x]);
        }
        num[y]+=num[x];
        d[x]=y;
        v[x]=tmp_v;
        return 1;
    }
}U;
bitset<SIZE> base_err;
int n,m,K;
int c[SIZE];
int people_num[SIZE];
bool cmp(const PII& x,const PII &y){
    return MP(c[x.F],c[x.S])<MP(c[y.F],c[y.S]);
}
bool my_equl(const PII& x,const PII &y){
    return MP(c[x.F],c[x.S])==MP(c[y.F],c[y.S]);
}
PII pp[SIZE];
int pn;
LL C2(LL x){
    return x*(x-1LL)/2;
}
void solve() {
    sort(pp,pp+pn,cmp);
    int cc[2]={};
    FOR(i,1,K){
        if(!base_err[i]){
            cc[people_num[i]]++;
        }
    }
    LL an=0;
    an+=C2(cc[0]+cc[1]);
    for(int i=0,j;i<pn;i=j){
        bool good=1;
        if(base_err[c[pp[i].F]]||base_err[c[pp[i].S]]){
            good=0;
        }
        bool bad=0;
        for(j=i;j<pn&&my_equl(pp[j],pp[i]);j++){
            if(good&&!bad){
                if(!U.uu(pp[j].F,pp[j].S,1)){
                    bad=1;
                }
            }
        }
        U.pop_all();
        if(good&&bad)an--;
    }
    W(an);
}
void input() {
    R(n,m,K);
    REP(i,n){
        R(c[i]);
        people_num[c[i]]^=1;
    }
    U.init(n);
    REP(i,m){
        int x,y;
        R(x,y);
        x--;
        y--;
        if(c[x]==c[y]){
            if(!U.uu(x,y)){
                base_err[c[x]]=1;
            }
        }
        else{
            if(c[x]>c[y])swap(x,y);
            pp[pn++]=MP(x,y);
        }
    }
}
int main(){
    input();
    solve();
    return 0;
}