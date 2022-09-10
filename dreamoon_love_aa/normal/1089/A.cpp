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
int max_score[5]={25,25,25,25,15};
PII dp[6][4][201][201];
void pre(){
    REP(i,6)REP(win,4)REP(j,201)REP(k,201)dp[i][win][j][k].F=-1;
    dp[0][0][0][0]={0,0};
    REP(i,5)REP(win,4)REP(j,201)REP(k,201){
        if(dp[i][win][j][k].F==-1)continue;
        if(win==3||i-win==3)continue;
        if(i-win<3&&k+max_score[i]<=200){
            FOR(score,0,max_score[i]-2){
                if(j+score<=200){
                    dp[i+1][win][j+score][k+max_score[i]]={score,max_score[i]};
                }
            }
        }
        
        if(win<3&&j+max_score[i]<=200){
            FOR(score,0,max_score[i]-2){
                if(k+score<=200){
                    dp[i+1][win+1][j+max_score[i]][k+score]={max_score[i],score};
                }
            }
        }
        FOR(score,max_score[i]+1,200){
            int good=0;
            if(i-win<3&&j+score-2<=200&&k+score<=200){
                good=1;
                dp[i+1][win][j+score-2][k+score]={score-2,score};
            }
            if(win<3&&j+score<=200&&k+score-2<=200){
                good=1;
                dp[i+1][win+1][j+score][k+score-2]={score,score-2};
            }
            if(!good)break;
        }
    }
}
void print(int i,int win,int j,int k){
    printf("%d:%d\n",win,i-win);
    VPII AA;
    while(i){
        AA.PB(dp[i][win][j][k]);
        i--;
        if(AA.back().F>AA.back().S)win--;
        j-=AA.back().F;
        k-=AA.back().S;
    }
    reverse(ALL(AA));
    REP(i,SZ(AA)){
        if(i)printf(" ");
        printf("%d:%d",AA[i].F,AA[i].S);
    }
    W("");
}
void solve(int a,int b){
    FOR(lose,0,2){
        if(dp[lose+3][3][a][b].F!=-1){
            print(lose+3,3,a,b);
            return;
        }
    }
    for(int win=2;win>=0;win--){
        if(dp[win+3][win][a][b].F!=-1){
            print(win+3,win,a,b);
            return;
        }
    }
    W("Impossible");
}
int main(){
    pre();
    CASET{
        int a,b;
        R(a,b);
        solve(a,b);
    }
    return 0;
}