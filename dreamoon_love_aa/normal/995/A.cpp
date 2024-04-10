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
int a[4][SIZE];
int n,k; 
bool done(){
    FOR(i,1,2)REP(j,n){
        if(a[i][j])return 0;
    }
    return 1;
}
vector<VI>an;
void move_to_target(){
    REP(i,n){
        if(a[0][i]&&a[0][i]==a[1][i]){
            an.PB({a[0][i],1,i+1});
            a[1][i]=0;
        }
        if(a[3][i]&&a[2][i]==a[3][i]){
            an.PB({a[3][i],4,i+1});
            a[2][i]=0;
        }
    }
}
bool my_rotate(){
    PII sp{-1,-1};
    FOR(i,1,2){
        REP(j,n){
            if(!a[i][j]){
                sp={i,j};
            }
        }
    }
    if(sp==MP(-1,-1))return 0;
    REP(i,2*n-1){
        PII nxt;
        if(sp.F==1){
            if(sp.S+1<n){
                nxt={1,sp.S+1};
            }
            else{
                nxt={2,sp.S};
            }
        }
        else{
            if(sp.S>0){
                nxt={2,sp.S-1};
            }
            else{
                nxt={1,0};
            }
        }
        if(a[nxt.F][nxt.S]){
            an.PB({a[nxt.F][nxt.S],sp.F+1,sp.S+1});
            a[sp.F][sp.S]=a[nxt.F][nxt.S];
            a[nxt.F][nxt.S]=0;
        }
        sp=nxt;
    }
    return 1;
}
int main(){
    R(n,k);
    REP(i,4)REP(j,n){
        R(a[i][j]);
    }
    while(!done()){
        move_to_target();
        if(!my_rotate()){
            W(-1);
            return 0;
        }
    }
    W(SZ(an));
    for(auto& x:an)W(x);
    return 0;
}