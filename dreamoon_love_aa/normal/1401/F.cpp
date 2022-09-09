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
int a[SIZE];
int n,q;
int rev[20];
int sw[20];
LL s[SIZE];
void build(int L,int R,int id){
    if(L+1==R){
        s[id]=a[L];
        return;
    }
    int mm=(L+R)/2;
    build(L,mm,id*2);
    build(mm,R,id*2+1);
    s[id]=s[id*2]+s[id*2+1];
}
void edit(int L,int R,int id,int x,int k,int lv){
    if(L+1==R){
        s[id]=k;
        return;
    }
    int mm=(L+R)/2;
    if(rev[lv])x=L+R-1-x;
    if(sw[lv-1]){
        if(x<mm)x=mm+x-L;
        else x=L+x-mm;
    }
    if(x<mm)edit(L,mm,id*2,x,k,lv-1);
    else edit(mm,R,id*2+1,x,k,lv-1);
    s[id]=s[id*2]+s[id*2+1];
}
LL qq(int L,int R,int id,int l,int r,int lv){
    if(L>=l&&R-1<=r)return s[id];
    int mm=(L+R)/2;
    if(rev[lv])tie(l,r)=MP(L+R-1-r,L+R-1-l);
    LL ret=0;
    if(l<mm){
        int now_r=min(r,mm-1);
        if(sw[lv-1]){
            ret+=qq(mm,R,id*2+1,l-L+mm,now_r-L+mm,lv-1);
        }
        else{
            ret+=qq(L,mm,id*2,l,now_r,lv-1);
        }
    }
    if(r>=mm){
        int now_l=max(l,mm);
        if(sw[lv-1]){
            ret+=qq(L,mm,id*2,now_l-mm+L,r-mm+L,lv-1);
        }
        else{
            ret+=qq(mm,R,id*2+1,now_l,r,lv-1);
        }
    }
    return ret;
}
void solve() {
    R(n,q);
    REP(i,1<<n)R(a[i]);
    build(0,(1<<n),1);
    REP(i,q){
        int ty;
        R(ty);
        if(ty==1){
            int x,k;
            R(x,k);
            x--;
            edit(0,1<<n,1,x,k,n);
        }
        else if(ty==2){
            int k;
            R(k);
            rev[k]^=1;
        }
        else if(ty==3){
            int k;
            R(k);
            sw[k]^=1;
        }
        else{
            int l,r;
            R(l,r);
            l--,r--;
            W(qq(0,1<<n,1,l,r,n));
        }
    }
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}