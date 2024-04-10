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
int s[10];
queue<PII>qq[10];
char a[1024][1024];
bool u[1024][1024];
int n,m,p;
bool out(int x,int y){
    return x<0||y<0||x>=n||y>=m;
}
int an[10];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    R(n,m,p);
    FOR(i,1,p)R(s[i]);
    REP(i,n)RS(a[i]);
    REP(i,n){
        REP(j,m){
            if(a[i][j]=='#')u[i][j]=1;
            else if(a[i][j]!='.'){
                u[i][j]=1;
                an[a[i][j]-'0']++;
                qq[a[i][j]-'0'].push({i,j});
            }
        }
    }
    while(1){
        bool suc=0;
        FOR(i,1,p){
            REP(j,s[i]){
                queue<PII>tmp;
                if(qq[i].empty())break;
                while(!qq[i].empty()){
                    suc=1;
                    REP(k,4){
                        int nx=qq[i].front().F+dx[k];
                        int ny=qq[i].front().S+dy[k];
                        if(out(nx,ny))continue;
                        if(u[nx][ny])continue;
                        u[nx][ny]=1;
                        an[i]++;
                        tmp.push({nx,ny});
                    }
                    qq[i].pop();
                }
                qq[i]=tmp;
            }
        }
        if(!suc)break;
    }
    W(VI(an+1,an+p+1));
    return 0;
}