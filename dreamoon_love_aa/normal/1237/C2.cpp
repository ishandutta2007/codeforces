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
const int SIZE = 1e5+10;
int d[SIZE][3];
bool u[SIZE];
int TY;
bool cmp(int x,int y){
    return d[x][TY]<d[y][TY];
}
int divide(VI& ker,int ty){
    if(SZ(ker)==0)return -1;
    if(SZ(ker)==1)return ker[0];
    if(SZ(ker)==2){
        W(ker[0],ker[1]);
        return -1;
    }
    TY=ty;
    sort(ALL(ker),cmp);
    if(d[ker[0]][ty]==d[ker.back()][ty]){
        return divide(ker,(ty+1)%3);
    }
    else{
        int mid=d[ker[(SZ(ker)-1)/2]][ty];
        if(d[ker.back()][ty]==mid)mid--;
        int cnt=0;
        REP(i,SZ(ker)){
            if(d[ker[i]][ty]<=mid)cnt++;
        }
        VI d1(ker.begin(),ker.begin()+cnt),d2(ker.begin()+cnt,ker.end());
        int v1=divide(d1,(ty+1)%3);
        int v2=divide(d2,(ty+1)%3);
        if(v1!=-1&&v2!=-1){
            W(v1,v2);
            v1=-1;
            v2=-1;
            return -1;
        }
        if(v1!=-1)return v1;
        return v2;
    }
}
int main(){
    int n; R(n);
    FOR(i,1,n){
        REP(j,3)R(d[i][j]);
    }
    VI ker;
    FOR(i,1,n)ker.PB(i);
    divide(ker,0);
    return 0;
}