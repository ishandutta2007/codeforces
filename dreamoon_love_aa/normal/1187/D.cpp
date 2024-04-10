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
VI pos[SIZE];
int it[SIZE];
int a[SIZE],b[SIZE];
int A[SIZE];
VPII AA;
struct Seg{
    int N;
    int ma[SIZE];
    void build(int L,int R,int id){
        if(L==R){
            ma[id]=a[L];
            return;
        }
        int mm=(L+R)/2;
        build(L,mm,id*2);
        build(mm+1,R,id*2+1);
        ma[id]=min(ma[id*2],ma[id*2+1]);
    }
    void init(int _N){
        N=_N;
        build(1,N,1);
    }
    void ins(int L,int R,int id,int x,int v){
        int mm=(L+R)/2;
        if(L==R){
            ma[id]=v;
            return;
        }
        if(x<=mm)ins(L,mm,id*2,x,v);
        else ins(mm+1,R,id*2+1,x,v);
        ma[id]=min(ma[id*2],ma[id*2+1]);
    }
    int qq(int L,int R,int id,int ll,int rr){
        if(L>rr||R<ll)return INT_MAX;
        if(L>=ll&&R<=rr)return ma[id];
        int mm=(L+R)/2;
        return min(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
    }
}seg;
bool solve(int n){
    FOR(i,1,n){
        if(SZ(pos[b[i]])<=it[b[i]])return 0;
        int v=pos[b[i]][it[b[i]]++];
        if(seg.qq(1,n,1,1,v)<b[i])return 0;
        seg.ins(1,n,1,v,n+1);
    }
    return 1;
}
int main(){
    CASET{
        int n; R(n);
        FOR(i,1,n){
            pos[i].clear();
            it[i]=0;
        }
        FOR(i,1,n){
            R(a[i]);
            pos[a[i]].PB(i);
        }
        seg.init(n);
        FOR(i,1,n)R(b[i]);
        W(solve(n)?"YES":"NO");
    }
    return 0;
}