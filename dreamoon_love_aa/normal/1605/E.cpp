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

const int SIZE = 1<<20;
int n,a[SIZE];
VI fac[SIZE];
int get_bit(long long x, int v) { return (x >> v) & 1; }
LL an[SIZE];
void solve() {
    FOR(i,2,n){
        if(!SZ(fac[i])){
            for(int j=i;j<=n;j+=i)fac[j].PB(i);
        }
    }
    LL base=0;
    VI pos,neg;
    FOR(i,2,n){
        PII add{0,0};
        REP(j,1<<SZ(fac[i])){
            int np=1;
            int me=i;
            REP(k,SZ(fac[i])){
                if(get_bit(j,k)){
                    np=-np;
                    me/=fac[i][k];
                }
            }
            if(me!=1)add.S+=a[me]*np;
            else add.F+=np;
        }
        if(!add.F)base+=abs(add.S);
        else{
            if(add.F==1)pos.PB(add.S);
            else neg.PB(add.S);
            base-=add.S;
        }
    }
    int q;
    R(q);
    VPII qq;
    REP(i,q){
        int x;
        R(x);
        x+=a[1];
        qq.PB({x,i});
    }
    sort(ALL(qq));
    sort(ALL(pos),greater<int>());
    sort(ALL(neg),greater<int>());
    int pos_it=0,neg_it=0;
    LL now=base;
    REP(i,q){
        while(pos_it<SZ(pos)&&qq[i].F+pos[pos_it]>=0){
            now+=pos[pos_it++]*2;
        }
        while(pos_it>0&&qq[i].F+pos[pos_it-1]<0){
            now-=pos[--pos_it]*2;
        }
        while(neg_it<SZ(neg)&&-qq[i].F+neg[neg_it]>=0){
            now+=neg[neg_it++]*2;
        }
        while(neg_it>0&&-qq[i].F+neg[neg_it-1]<0){
            now-=neg[--neg_it]*2;
        }
        an[qq[i].S]=abs(qq[i].F)+now+(LL)qq[i].F*(pos_it-(SZ(pos)-pos_it)-neg_it+(SZ(neg)-neg_it));
    }
    REP(i,q)W(an[i]);
}
void input() {
    R(n);
    FOR(i,1,n)R(a[i]);
    FOR(i,1,n){
        int x;
        R(x);
        if(x==-1)x=0;
        a[i]=x-a[i];
    }
}
int main(){
    input();
    solve();
    return 0;
}