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
/*  n  a 
 * 
 * 1.  1  x  v
 * 2.  x  y  v
 * 3.  x 
 * 
 */
struct BIT2{
    vector<long long> _d;
    int _n;
    //  n  BIT
    void init(int __n) {
        _n=__n;
        _d.resize(_n + 1);
        memset(_d.data(), 0, sizeof(long long) * (_n + 1));
    }
    //  x  v
    void ins(int x, long long v) {
        for(; x; x -= x & -x) { _d[x] += v; }
    }
    //  x  y  v
    void ins_range(int x, int y, long long v) {
        ins(y, v);
        if(x>1) { ins( x - 1, -v); }
    }
    //  x 
    long long qq(int x) {
        long long res = 0;
        if(x <= 0 || x > _n) { return 0; }
        for(; x <= _n; x += x & -x) { res += _d[x]; }
        return res;
    }
}bit;
LL col_val[SIZE];
int n,q;
void ins(map<int, int> &AA, int l, int r, int c) {
    auto it_l = AA.find(l);
    auto it_r = AA.find(r);
    for(auto it = it_l; it != it_r; it++) {
        bit.ins_range(it->F,next(it)->F-1,col_val[it->S]-col_val[c]);
    }
    AA.erase(it_l, it_r);
    AA[l] = c;
}
void split(map<int, int> &AA, int pos) {
    auto it = AA.lower_bound(pos);
    if(it->first != pos) {
        int tmp = prev(it)->second;
        AA[pos] = tmp;
    }
}
void solve() {
    map<int,int>AA{{1,1},{n+1,0}};
    bit.init(n);
    string s;
    REP(i,q){
        R(s);
        if(s[0]=='C'){
            int l,r,c;
            R(l,r,c);
            split(AA,l);
            split(AA,r+1);
            ins(AA,l,r+1,c);
        }else if(s[0]=='A'){
            int c,x;
            R(c,x);
            col_val[c]+=x;
        }else if(s[0]=='Q'){
            int i;
            R(i);
            auto it=AA.lower_bound(i);
            if(it->F>i)it--;
            W(bit.qq(i)+col_val[it->S]);
        }
    }
}
void input() {
    R(n,q);
}
int main(){
    input();
    solve();
    return 0;
}