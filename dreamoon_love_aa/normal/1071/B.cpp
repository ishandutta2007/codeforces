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
const int SIZE = 2010;
char s[SIZE][SIZE];
int need[SIZE][SIZE];
int N,K; 
bool Out(int x,int y){
    return x<1||y<1||x>N||y>N;
}
int main(){
    R(N,K);
    REP(i,N) RS(s[i+1]+1);
    FOR(i,2,N)need[0][i]=need[i][0]=K+1;
    int max_ij=1;
    FOR(i,1,N)FOR(j,1,N){
        need[i][j]=min(need[i-1][j],need[i][j-1])+(s[i][j]!='a');
        if(need[i][j]<=K){
            max_ij=max(max_ij,i+j);
        }
    }
    if(need[N][N]<=K){
        REP(i,N*2-1)putchar('a');
        puts("");
    }
    else{
        FOR(i,2,max_ij)putchar('a');
        VI p[2];
        int now=0,nxt=1;
        if(max_ij>1){
            FOR(i,1,N){
                if(i>max_ij)break;
                int j=max_ij-i;
                if(j<1)continue;
                if(need[i][j]<=K){
                    p[now].PB(i);
                }
            }
        }
        else{
            putchar(s[1][1]);
            p[now].PB(1);
            max_ij++;
        }
        REPP(ij,max_ij,2*N){
            p[nxt].clear();
            char mi='z';
            for(int i:p[now]){
                int j=ij-i;
                if(!Out(i+1,j))mi=min(mi,s[i+1][j]);
                if(!Out(i,j+1))mi=min(mi,s[i][j+1]);
            }
            putchar(mi);
            for(int i:p[now]){
                int j=ij-i;
                if(!Out(i+1,j)&&s[i+1][j]==mi)p[nxt].PB(i+1);
                if(!Out(i,j+1)&&s[i][j+1]==mi)p[nxt].PB(i);
            }
            SORT_UNIQUE(p[nxt]);
            swap(now,nxt);
        }
        puts("");
    }
    return 0;
}