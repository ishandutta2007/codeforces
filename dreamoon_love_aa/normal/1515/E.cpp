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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int N, M;
LL C[401][401];
void pre() {
    FOR(i,0,N){
        C[i][0]=1;
        FOR(j,1,i){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=M)C[i][j]-=M;
        }
    }
}
void input() {
    R(N,M);
    MOD=M;
}
LL dp2[4][401][2][401];
void my_add(LL tmp[],LL v,int l,int r){
    ADD(tmp[l],v);
    ADD(tmp[r+1],-v);
}
void solve2(){
    int now=0;
    dp2[now][1][0][1]=1;
    FOR(i,1,N){
        if(i!=1){
            FOR(j,1,i){
                REP(k,2){
                    REPP(l,1,i){
                        ADD(dp2[now][j][k][l+1],dp2[now][j][k][l]);
                    }
                }
            }
        }
        if(i==N){
            break;
        }
        FOR(j,1,i){
            FOR(k,1,j){
                my_add(dp2[(now+2)&3][j+1][0],dp2[now][j][0][k]+dp2[now][j][1][k],1,i+1);
                my_add(dp2[(now+1)&3][j+1][0],dp2[now][j][0][k],1,k);
                my_add(dp2[(now+1)&3][j+1][1],dp2[now][j][0][k],k+1,j+1);
                my_add(dp2[(now+1)&3][j+1][1],dp2[now][j][1][k],k+1,j+1);
            }
        }
        MS0(dp2[now]);
        now=(now+1)&3;
    }
    LL an=0;
    FOR(i,1,N){
        REP(j,2)FOR(k,1,i){
            ADD(an,dp2[now][i][j][k]);
        }
    }
    W(an);
}
int main(){
    input();
    solve2();
    return 0;
}