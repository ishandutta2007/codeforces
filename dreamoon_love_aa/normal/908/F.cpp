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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const int INF = 1e9+7;
int p[SIZE];
int c[SIZE];
int main(){
    int n;
    R(n);
    VI gg;
    REP(i,n){
        R(p[i]);
        char s[4];
        RS(s);
        if(s[0]=='G')c[i]=0;
        else if(s[0]=='R')c[i]=1;
        else c[i]=2;
        if(c[i]==0)gg.PB(i);
    }
    if(SZ(gg)==0){
        int mi[3],ma[3];
        REP(i,3)mi[i]=INF;
        REP(i,3)ma[i]=-INF;
        REP(i,n){
            mi[c[i]]=min(mi[c[i]],p[i]);
            ma[c[i]]=max(ma[c[i]],p[i]);
        }
        int an=0;
        FOR(i,1,2){
            if(mi[i]!=INF)an+=ma[i]-mi[i];
        }
        W(an);
    }
    else{
        LL an=0;
        {
            bool u[3]={};
            REP(i,gg[0]){
                if(!u[c[i]]){
                    an+=p[gg[0]]-p[i];
                }
                u[c[i]]=1;
            }
        }
        {
            bool u[3]={};
            for(int i=n-1;i>gg.back();i--){
                if(!u[c[i]]){
                    an+=p[i]-p[gg.back()];
                }
                u[c[i]]=1;
            }
        }
        REPP(i,1,SZ(gg)){
            int lt[3]={-1,p[gg[i-1]],p[gg[i-1]]};
            int ma[3]={-1,-1,-1};
            REPP(j,gg[i-1]+1,gg[i]){
                if(lt[c[j]]!=-1){
                    ma[c[j]]=max(ma[c[j]],p[j]-lt[c[j]]);
                }
                lt[c[j]]=p[j];
            }
            FOR(j,1,2){
                ma[j]=max(ma[j],p[gg[i]]-lt[j]);
            }
            LL len=p[gg[i]]-p[gg[i-1]];
            an+=min({len*3-ma[1]-ma[2],len*2});
        }
        W(an);
    }
    return 0;
}