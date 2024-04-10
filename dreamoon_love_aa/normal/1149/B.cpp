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
int n,q;
char s[SIZE];
int nxt[SIZE][26];
string AA[3];
int dp[251][251][251];
void update(int &x,int v){
    if(x==-1||x>v)x=v;
}
void update(int x,int y,int z){
    dp[x][y][z]=n+1;
    if(x&&dp[x-1][y][z]!=n+1)update(dp[x][y][z],nxt[dp[x-1][y][z]+1][AA[0][x-1]-'a']);
    if(y&&dp[x][y-1][z]!=n+1)update(dp[x][y][z],nxt[dp[x][y-1][z]+1][AA[1][y-1]-'a']);
    if(z&&dp[x][y][z-1]!=n+1)update(dp[x][y][z],nxt[dp[x][y][z-1]+1][AA[2][z-1]-'a']);
}
int main(){
    R(n,q);
    RS(s+1);
    REP(i,26)nxt[n+1][i]=n+1;
    for(int i=n;i>0;i--){
        REP(j,26)nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i]-'a']=i;
    }
    REP(cs,q){
        int id;
        string op,c;
        R(op,id);
        id--;
        if(op=="+"){
            R(c);
            AA[id]+=c;
            if(!id){
                REP(j,SZ(AA[1])+1)REP(k,SZ(AA[2])+1){
                    update(SZ(AA[0]),j,k);
                }
            }
            else if(id==1){
                REP(i,SZ(AA[0])+1)REP(k,SZ(AA[2])+1){
                    update(i,SZ(AA[1]),k);
                }
            }
            else{
                REP(i,SZ(AA[0])+1)REP(j,SZ(AA[1])+1){
                    update(i,j,SZ(AA[2]));
                }
            }
        }
        else if(op=="-"){
            AA[id].pop_back();
        }
        //W(dp[SZ(AA[0])][SZ(AA[1])][SZ(AA[2])]);
        W(dp[SZ(AA[0])][SZ(AA[1])][SZ(AA[2])]<=n?"YES":"NO");
    }
    return 0;
}