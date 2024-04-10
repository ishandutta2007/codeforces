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
const int SIZE = 5001;
int cnt[SIZE][SIZE];
int a[SIZE],f[SIZE],h[SIZE];
VI pos[SIZE];
VI need[SIZE];
PLL an;
int main(){
    an=MP(0,0);
    int n,m;
    R(n,m);
    FOR(i,1,n){
        R(a[i]);
        pos[a[i]].PB(i);
    }
    FOR(i,1,n){
        FOR(j,1,n)cnt[j][i]=cnt[j][i-1];
        cnt[a[i]][i]++;
    }
    FOR(i,1,m){
        R(f[i],h[i]);
        need[f[i]].PB(h[i]);
    }
    FOR(i,1,n)sort(ALL(need[i]));
    FOR(i,1,m){
        if(h[i]>SZ(pos[f[i]]))continue;
        int mm = pos[f[i]][h[i]-1];
        PLL res={1,1};
        FOR(j,1,n){
            if(!SZ(need[j])||!SZ(pos[j]))continue;
            if(j!=f[i]){
                int x=cnt[j][mm];
                int y=cnt[j][n]-cnt[j][mm];
                if(x>y)swap(x,y);
                int num1=upper_bound(ALL(need[j]),x)-need[j].begin();
                int num2=upper_bound(ALL(need[j]),y)-need[j].begin();
                int v2=num1*(num2-1);
                if(v2){
                    res.F+=2;
                    res.S = res.S * v2 % MOD;
                }
                else if(num1+num2){
                    res.F++;
                    res.S = res.S * (num1 + num2) % MOD;
                }

            }
            else{
                int y=cnt[j][n]-cnt[j][mm];
                int num=upper_bound(ALL(need[j]),y)-need[j].begin();
                num -= (h[i]<=y);
                if(num) {
                    res.F++;
                    res.S = res.S * num % MOD;
                }
            }
        }
        if(res.F==an.F)ADD(an.S,res.S);
        else if(res.F>an.F)an=res;
    }
    {
        PLL res=MP(0,1);
        FOR(j,1,n){
            int y=cnt[j][n];
            int num=upper_bound(ALL(need[j]),y)-need[j].begin();
            if(num) {
                res.F++;
                res.S = res.S * num % MOD;
            }
        }
        if(res.F==an.F)ADD(an.S,res.S);
        else if(res.F>an.F)an=res;
    }
    W(an);
    return 0;
}