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
const int SIZE = 2001;
char s[SIZE][SIZE];
int deg[SIZE];
int g[SIZE];
int n;
int cnt[SIZE];
bool check(){
    memcpy(g,deg,sizeof(int)*n);
    sort(g,g+n,greater<int>());
    int now=0;
    REP(i,n-1){
        now+=g[i];
        if(now==cnt[i+1])return 0;
    }
    return 1;
}
void rev(int i){
    REP(j,n){
        if(i==j)continue;
        if(s[i][j]=='1'){
            deg[i]--,deg[j]++;
        }
        else deg[i]++,deg[j]--;
        swap(s[i][j],s[j][i]);
    }
}
int main(){
    R(n);
    FOR(i,1,n){
        cnt[i]=i*(i-1)/2+i*(n-i);
    }
    REP(i,n)RS(s[i]);
    REP(i,n)REP(j,n){
        if(s[i][j]=='1')deg[i]++;
    }
    if(check()){
        W(0,1);
        return 0;
    }
    int one=0;
    REP(i,n){
        rev(i);
        if(check())one++;
        rev(i);
    }
    if(one){
        W(1,one);
        return 0;
    }
    int two=0;
    REP(i,n){
        rev(i);
        REPP(j,i+1,n){
            rev(j);
            if(check())two+=2;
            rev(j);
        }
        rev(i);
    }
    if(two){
        W(2,two);
        return 0;
    }
    int three=0;
    REP(i,n){
        rev(i);
        REPP(j,i+1,n){
            rev(j);
            REPP(k,j+1,n){
                rev(k);
                if(check())three+=6;
                rev(k);
            }
            rev(j);
        }
        rev(i);
    }
    if(three)W(3,three);
    else W(-1);
    return 0;
}