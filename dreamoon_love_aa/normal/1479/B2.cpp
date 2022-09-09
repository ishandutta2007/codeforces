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
struct Seg{
    int ma[SIZE];
    void pull(int id){
        ma[id]=min(ma[id*2],ma[id*2+1]);
    }
    void init(int L,int R,int id){
        if(L==R){
            if(!L)ma[id]=0;
            else ma[id]=SIZE;
            return;
        }
        int mm=(L+R)/2;
        init(L,mm,id*2);
        init(mm+1,R,id*2+1);
        pull(id);
    }
    int qq(int L,int R,int id,int l,int r){
        if(L>r||R<l)return INT_MAX;
        if(L>=l&&R<=r)return ma[id];
        int mm=(L+R)/2;
        return min(qq(L,mm,id*2,l,r),qq(mm+1,R,id*2+1,l,r));
    }
    void edit(int L,int R,int id,int p,int v){
        if(L==R){
            ma[id]=min(ma[id],v);
            return;
        }
        int mm=(L+R)/2;
        if(p<=mm)edit(L,mm,id*2,p,v);
        else edit(mm+1,R,id*2+1,p,v);
        pull(id);
    }
}seg;
int added_all;
int n;
int a[SIZE];
void solve() {
    seg.init(0,n,1);
    FOR(i,1,n){
        int v=seg.qq(0,n,1,0,a[i]-1)+1;
        if(a[i]<n)v=min(v,seg.qq(0,n,1,a[i]+1,n)+1);
        v=min(v,seg.qq(0,n,1,a[i],a[i]));
        v+=added_all;
        if(a[i]!=a[i-1]){
            added_all++;
        }
        seg.edit(0,n,1,a[i-1],v-added_all);
    }
    W(seg.qq(0,n,1,0,n)+added_all);
}
void input() {
    R(n);
    FOR(i,1,n)R(a[i]);
}
int main(){
    input();
    solve();
    return 0;
}