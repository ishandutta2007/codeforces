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
int n;
int cnt[SIZE],two;
void add(set<int>&d,int i){
    cnt[i]++;
    if(i!=two)d.insert(i);
}
void del(set<int> &d, int i){
    cnt[i]--;
    if(!cnt[i]){
        d.erase(i);
    }
}
bool valid(int x, int y){
    if(x==y)return cnt[x]>=2;
    return cnt[x]>=1&&cnt[y]>=1;
}
void solve() {
    if(n==2){
        W(-1);
        return;
    }
    set<int> d;
    two=1;
    while(two<n)two*=2;
    FOR(i,0,two)cnt[i]=0;
    FOR(i,1,n){
        add(d,i);
    }
    VPII an;
    while(SZ(d)){
        bool done=0;
        for(auto it=d.rbegin();it!=d.rend();it++){
            int x=*it;
            if(!x){
                break;
            }
            int m=1<<__lg(x);
            int y=m*2-x;
            if(valid(x,y)){
                del(d,x);
                del(d,y);
                add(d,x+y);
                add(d,abs(x-y));
                an.PB(MP(x,y));
                DEBUG(2,":",x,y);
                done=1;
                break;
            }
        }
        if(done)continue;
        for(auto it=d.begin();it!=d.end();it++){
            int x=*it;
            if(x==0)continue;
            if(valid(x,0)){
                add(d,x);
                del(d,0);
                an.PB(MP(x,0));
                DEBUG(3,":",x,0);
                done=1;
                break;
            }
        }
        if(done)continue;
        del(d,0);
        an.PB(MP(0,two));
    }
    W(SZ(an));
    for(auto &x: an)W(x);
}
void input() {
    R(n);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}