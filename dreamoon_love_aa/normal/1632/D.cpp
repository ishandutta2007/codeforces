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
template<class T>
T rmqfunc(T a, T b) {
    return __gcd(a, b);
}
template <class T,T RmqFunc(T,T)>
class RMQ{
    public:
        vector<vector<T>> values;

        template<class IterType> void build(IterType begin, IterType end) {
            assert(begin != end);
            int n = end - begin;
            int h = __lg(n);
            values.resize(h + 1);
            auto it = begin;
            values[0].assign(begin, end);
            for(int i = 1, len = 1; i <= h; i++, len <<= 1) {
                values[i].resize(n);
                for(int j = 0; j + len * 2 <= n; j++) {
                    values[i][j] = RmqFunc(values[i-1][j], values[i-1][j + len]);
                }
            }
        }
        T query(int ll,int rr) {
            int lv = __lg(rr - ll);
            return RmqFunc(values[lv][ll], values[lv][rr - (1 << lv)]);
        }
};
/*
void test() {
    vector<int> AA {1, 5, 3, 9, 7};
    
    rmq.build(AA.begin(), AA.end());

    cout<<rmq.query(0,3)<<endl;
    cout<<rmq.query(3,5)<<endl;
    cout<<rmq.query(1,5)<<endl;
    cout<<rmq.query(3,4)<<endl;
}
*/
int n;
VI AA;
void solve() {
    RMQ<int,rmqfunc> rmq;
    rmq.build(ALL(AA));
    int ll=0;
    int now=0;
    REP(i,n){
        int g;
        while(1){
            g=rmq.query(ll,i+1);
            if(g<i-ll+1)ll++;
            else break;
        }
        if(g==i-ll+1){
            now++;
            ll=i+1;
        }
        W(now);
    }
}
void input() {
    R(n);
    AA.resize(n);
    REP(i,n)R(AA[i]);
}
int main(){
    input();
    solve();
    return 0;
}