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
const int MAX_N = 200005;
const int MAX_BIT_NUM = 18;
struct BIT{
    int _n;
    vector<long long> _a, _b;
    //  n  BIT 4  2^x x  2^x > n 
    void init(int __n) {
        _n = __n + 1;
        _a.resize(_n + 1);
        _b.resize(_n + 1);
        memset(_a.data() + 1, 0, sizeof(long long) * _n);
        memset(_b.data() + 1, 0, sizeof(long long) * _n);
    }
    //  n  BIT
    BIT(int __n) {
        init(__n);
    }
    //  x  v
    void ins(int x, long long v1, long long v2) {
        for(; x <= _n; x += x & -x) { _a[x] += v1; _b[x] += v2; }
    }
    void ins_range(int l, int r, long long v) {
        ins(l, v, v * (-l + 1));
        ins(r + 1, -v, v * r);
    }
    //  x 
    long long qq(int x) {
        if(x <= 0) {
            return 0;
        }
        int c = x;
        long long res = 0;
        for(; x; x -= x & -x) {
            res += c * _a[x] + _b[x];
        }
        return res;
    }
    //  x  y 
    long long qq_range(int x, int y) {
        if(x > y) {
            return 0;
        }
        long long ret = qq(y);
        if(x)ret -= qq(x - 1);
        return ret;
    }
};
vector<VI>add[MAX_N];
VI ql[MAX_N],qr[MAX_N];
int p[MAX_N],l[SIZE],r[SIZE],pos[MAX_N];
int n,q;
VI fac[SIZE];
LL an[SIZE];
void solve() {
    FOR(i,1,n)pos[p[i]]=i;
    FOR(i,1,n){
        for(int j=i;j<=n;j+=i)fac[j].PB(i);
    }
    set<int>ban{0,n+1};
    for(int i=n;i>0;i--){
        int my_pos=pos[i];
        auto it=ban.insert(my_pos).first;
        int lb=*prev(it),rb=*next(it);
        VPII seg;
        for(int j=0;j<SZ(fac[i])-j-1;j++){
            int x=fac[i][j];
            int y=fac[i][SZ(fac[i])-j-1];
            int ll=min({pos[x],pos[y],my_pos});
            int rr=max({pos[x],pos[y],my_pos});
            if(ll<=lb||rr>=rb)continue;
            seg.PB({ll,rr});
        }
        int lt_l=my_pos;
        int lt_r=rb;
        sort(ALL(seg),greater<PII>());
        int ff=-1;
        REP(i,SZ(seg)){
            if(seg[i].F<=lt_l){
                if(lt_r<rb){
                    add[lt_r].PB({seg[i].F+1,lt_l,1});
                    if(ff==-1)ff=lt_l;
                    //add[rb].PB({seg[i].F+1,lt_l,-1});
                }
                lt_l=seg[i].F;
            }
            lt_r=min(lt_r,seg[i].S);
        }
        if(SZ(seg)){
            add[lt_r].PB({lb+1,lt_l,1});
            if(ff==-1)ff=lt_l;
            add[rb].PB({lb+1,ff,-1});
        }
    }
    REP(i,q){
        ql[l[i]].PB(i);
        qr[r[i]].PB(i);
    }
    BIT bit_a(n), bit_b(n);
    FOR(i,1,n){
        for(auto id: ql[i]){
            an[id]-=bit_a.qq_range(l[id],r[id])*i+bit_b.qq_range(l[id],r[id]);
        }
        for(auto &vi:add[i]){
            bit_a.ins_range(vi[0],vi[1],vi[2]);
            bit_b.ins_range(vi[0],vi[1],-(LL)vi[2]*i);
        }
        for(auto id: qr[i]){
            an[id]+=bit_a.qq_range(l[id],r[id])*(i+1)+bit_b.qq_range(l[id],r[id]);
        }
    }
    REP(i,q)cout << an[i] << '\n';
}
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch) && ch !='-') ch = gc();
        bool neg = 0;
        if(ch == '-') { neg = 1; ch = gc(); }
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
        if(neg) { x = -x; }
    }
} using io::read;
void input() {
    read(n);
    read(q);
    FOR(i,1,n) read(p[i]);
    REP(i,q){
        read(l[i]);
        read(r[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}