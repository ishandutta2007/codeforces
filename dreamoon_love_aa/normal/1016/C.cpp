/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
LL a[2][SIZE];
LL dp1[2][SIZE],dp2[2][SIZE];
int n;
LL f1(){
    LL an=0;
    LL x=0;
    REP(i,n)an+=(x++)*a[0][i];
    for(int i=n-1;i>=0;i--)an+=(x++)*a[1][i];
    return an;
}
LL f2(){
    LL an=0;
    LL x=1;
    REP(i,n)an+=(x++)*a[1][i];
    for(int i=n-1;i>0;i--)an+=(x++)*a[0][i];
    return an;
}
LL get(int ty,int r,int x,int y){
    if(ty==1){
        if(!x)return dp1[r][y];
        return dp1[r][y]-dp1[r][x-1];
    }
    else{
        if(!x)return dp2[r][y];
        return dp2[r][y]-dp2[r][x-1]-get(1,r,x,y)*x;
    }
}
LL get1(LL x,LL r,LL c){
    return get(2,r,c,n-1)+get(1,r,c,n-1)*x;
}
LL get2(LL x,LL r,LL c){
    return get(1,r,c,n-1)*(x+n-1-c)-get(2,r,c,n-1);
}
LL f3(){
    LL an=0;
    LL ret=0;
    LL x=0;
    REP(i,n){
        if(i%2==0){
            an+=(x++)*a[0][i];
            an+=(x++)*a[1][i];
            if(i+1<n)ret=max(ret,an+get1(x,1,i+1)+get2(x+n-1-i,0,i+1));
        }
        else{
            an+=(x++)*a[1][i];
            an+=(x++)*a[0][i];
            if(i+1<n)ret=max(ret,an+get1(x,0,i+1)+get2(x+n-1-i,1,i+1));
        }
    }
    ret=max(ret,an);
    return ret;
}
int main(){
    R(n);
    REP(i,2)REP(j,n){
        R(a[i][j]);
        dp1[i][j]+=a[i][j];
        dp2[i][j]+=a[i][j]*j;
        if(j){
            dp1[i][j]+=dp1[i][j-1];
            dp2[i][j]+=dp2[i][j-1];
        }
    }
    LL an=max({f1(),f2(),f3()});
    W(an);
    return 0;
}