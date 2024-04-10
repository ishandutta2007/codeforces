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
const int SIZE = 1010;
PII a[SIZE][SIZE];
char an[SIZE][SIZE];
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char c[5]="ULDR";
bool out(int x,int y){
    return x<1||y<1||x>n||y>n;
}
void dfs(int x,int y){
    REP(i,4){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(out(nx,ny)||an[nx][ny])continue;
        if(a[nx][ny]==a[x][y]){
            an[nx][ny]=c[i];
            dfs(nx,ny);
        }
    }
}
void solve(){
    R(n);
    FOR(i,1,n)FOR(j,1,n){
        R(a[i][j].F,a[i][j].S);
    }
    FOR(i,1,n)FOR(j,1,n){
        if(MP(i,j)==a[i][j]){
            an[i][j]='X';
            dfs(i,j);
        }
    }
    FOR(i,1,n)FOR(j,1,n){
        if(!an[i][j]){
            if(a[i][j]==MP(-1,-1)){
                REP(k,4){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(out(nx,ny))continue;
                    if(a[nx][ny]==MP(-1,-1)){
                        if(!an[nx][ny]){
                            an[i][j]=c[k^2];
                            an[nx][ny]=c[k];
                        }
                        else{
                            an[i][j]=c[k^2];
                        }
                        break;
                    }
                }
            }
            if(!an[i][j]){
                W("INVALID");
                return;
            }
        }
    }
    W("VALID");
    FOR(i,1,n)W(an[i]+1);
}
int main(){
    solve();
    return 0;
}