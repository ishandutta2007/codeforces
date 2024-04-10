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
string s[SIZE];
void cal(string &t,char &lc,char&rc,bool &same,int &ll,int &rr){
    ll=1,rr=1;
    while(ll<SZ(t)&&t[ll]==t[0])ll++;
    while(rr<SZ(t)&&t[SZ(t)-1-rr]==t[SZ(t)-1])rr++;
    same=0;
    if(ll==SZ(t))same=1;
    lc=t[0];
    rc=t.back();
}
int main(){
    int n; R(n);
    REP(i,n)R(s[i]);
    char lc, rc;
    bool same;
    int ll,rr;
    cal(s[n-1],lc,rc,same,ll,rr);
    int an=0;
    for(int j=0,k;j<SZ(s[n-1]);j=k){
        for(k=j+1;k<SZ(s[n-1])&&s[n-1][k]==s[n-1][j];k++);
        an=max(an,k-j);
    }
    for(int i=n-2;i>=0;i--){
        int m=SZ(s[i]);
        char nxt_lc, nxt_rc;
        bool nxt_same;
        int nxt_ll,nxt_rr;
        cal(s[i],nxt_lc,nxt_rc,nxt_same,nxt_ll,nxt_rr);
        if(same){
            if(nxt_same){
                if(lc==nxt_lc){
                    ll=rr=ll*(nxt_ll+1)+nxt_ll;
                    an=max(an,ll);
                }
                else{
                    same=0;
                }
            }
            else{
                same=0;
                for(int j=0,k;j<m;j=k){
                    if(s[i][j]!=lc){
                        k=j+1;
                        continue;
                    }
                    for(k=j+1;k<m&&s[i][k]==s[i][j];k++);
                    an=max(an,(k-j)+ll*(k-j+1));
                }
                if(nxt_lc==lc){
                    ll=ll*(nxt_ll+1)+nxt_ll;
                }
                if(nxt_rc==rc){
                    rr=rr*(nxt_rr+1)+nxt_rr;
                }
            }
        }
        else{
            REP(j,m){
                if(s[i][j]==lc&&s[i][j]==rc){
                    an=max(an,ll+rr+1);
                }
                else if(s[i][j]==lc){
                    an=max(an,ll+1);
                }
                else if(s[i][j]==rc){
                    an=max(an,rr+1);
                }
            }
        }
    }
    W(an);
    return 0;
}