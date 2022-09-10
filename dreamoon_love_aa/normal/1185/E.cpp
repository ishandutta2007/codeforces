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
char s[2024][2024];
int n,m;
PII mm[26][2];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void err(){
    W("NO");
}
void solve(){
    R(n,m);
    REP(i,n)RS(s[i]);
    REP(i,26){
        mm[i][0]=MP(n,m);
        mm[i][1]={-1,-1};
    }
    int ma=-1;
    REP(i,n){
        REP(j,m){
            if(s[i][j]!='.'){
                int v=s[i][j]-'a';
                maa(mm[v][1].F,i);
                maa(mm[v][1].S,j);
                mii(mm[v][0].F,i);
                mii(mm[v][0].S,j);
                ma=max(ma,v);
            }
        }
    }
    for(int i=ma;i>=0;i--){
        if(mm[i][0].F<mm[i][1].F&&mm[i][0].S<mm[i][1].S){
            err();
            return;
        }
        FOR(j,mm[i][0].F,mm[i][1].F)FOR(k,mm[i][0].S,mm[i][1].S){
            if(s[j][k]=='.'||s[j][k]<i+'a'){
                err();
                return;
            }
        }
    }
    W("YES");
    W(ma+1);
    FOR(i,0,ma){
        if(mm[i][1].F==-1){
            REP(j,2)mm[i][j]=mm[ma][j];
        }
        REP(j,2){
            mm[i][j].F++;
            mm[i][j].S++;
        }
        W(mm[i][0],mm[i][1]);
    }
}
int main(){
    CASET{
        solve();
    }
    return 0;
}