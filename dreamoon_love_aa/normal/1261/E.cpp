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
char ans[1002][1002];
int n; 
VI d[1002];
int a[1002],u[1002],tt;
void solve(){
    int num=1;
    REP(i,n+1)d[0].PB(i);
    REP(i,n){
        int r[2]={n+1-a[i],a[i]};
        int nxt=num;
        tt++;
        REP(j,num){
            if(SZ(d[j])==1)continue;
            u[j]=tt;
            int it=0;
            REP(k,SZ(d[j])){
                int v=k&1;
                if(!r[v])v^=1;
                r[v]--;
                ans[d[j][k]][i]=v+'0';
                if(!v)d[j][it++]=d[j][k];
                else d[nxt].PB(d[j][k]);
            }
            d[j].resize(it);
            if(it==0)swap(d[nxt],d[j]);
            if(SZ(d[nxt]))nxt++;
        }
        REP(j,num){
            if(u[j]==tt)continue;
            int it=0;
            REP(k,SZ(d[j])){
                int v=k&1;
                if(!r[v])v^=1;
                r[v]--;
                ans[d[j][k]][i]=v+'0';
                if(!v)d[j][it++]=d[j][k];
                else d[nxt].PB(d[j][k]);
            }
            d[j].resize(it);
            if(it==0)swap(d[nxt],d[j]);
            if(SZ(d[nxt]))nxt++;
        }
        num=nxt;
    }
}
int main(){
    R(n);
    REP(i,n)R(a[i]);
    solve();
    W(n+1);
    REP(i,n+1)puts(ans[i]);
    return 0;
}