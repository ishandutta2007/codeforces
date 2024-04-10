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
int a[SIZE],t[SIZE],stop[SIZE];
bool gg[SIZE];
PII ch[SIZE];
int num;
int main(){
    int n,T;R(n,T);
    vector<pair<int,PII>> ppp1,ppp2;
    REP(i,n){
        int x,y;
        R(x,y);
        a[i]=x;t[i]=y;
        ppp1.PB(MP(x,MP(y,i)));
        ppp2.PB(MP(y,MP(x,i)));
    }
    sort(ALL(ppp1));
    sort(ALL(ppp2));
    int it2=0,it1=0;
    int an=0;
    LL need=0;
    FOR(i,1,n){
        while(it1<n&&ppp1[it1].F<i){
            int id=ppp1[it1].S.S;
            stop[id]=1;
            if(gg[id]){
                ch[id].S=i;
                gg[id]=0;
                need-=ppp1[it1].S.F;
                num--;
            }
            it1++;
        }
        while(num<i){
            while(it2<n&&stop[ppp2[it2].S.S])it2++;
            if(it2==n)break;
            ch[ppp2[it2].S.S]=MP(i,n+1);
            gg[ppp2[it2].S.S]=1;
            need+=ppp2[it2++].F;
            num++;
        }
        if(num>=i&&need<=T)an=max(an,i);
    }
    W(an);W(an);
    VI res;
    REP(i,n){
        if(ch[i].F<=an&&ch[i].S>an)res.PB(i+1);
    }
    W(res);
    return 0;
}