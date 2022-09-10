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
void NO(){puts("NO");}
void eq0(int N){
    if(N%2){
        NO();
        return;
    }
    if(N<12){
        VI d;
        FOR(i,1,N)d.PB(i);
        bool suc=0;
        do{
            bool fail=0;
            REP(i,SZ(d)){
                if(d[i]==i+1||(d[i]&(i+1))!=0){
                    fail=1;
                    break;
                }
            }
            if(!fail){
                suc=1;
                break;
            }
        }while(next_permutation(ALL(d)));
        if(suc){
            puts("YES");
            W(d);
        }
        else NO();
    }
    else{
        puts("YES");
        VI an(N);
        while(N){
            int two=1;
            while(two<=N)two<<=1;
            int low=(two-1)^N;
            FOR(i,low,N)an[i-1]=low+N-i;
            N=low-1;
        }
        W(an);
        //REP(i,SZ(an))assert(((i+1)&an[i])==0);
        return;
    }
}
void neq0(int N){
    if((N&(N-1))==0){
        NO();
        return;
    }
    if(N<10){
        VI d;
        FOR(i,1,N)d.PB(i);
        bool suc=0;
        do{
            bool fail=0;
            REP(i,SZ(d)){
                if((d[i]==i+1)||(d[i]&(i+1))==0){
                    fail=1;
                    break;
                }
            }
            if(!fail){
                suc=1;
                break;
            }
        }while(next_permutation(ALL(d)));
        if(suc){
            puts("YES");
            W(d);
        }
        else NO();
    }
    else{
        VI an(N);
        VI bit[20];
        FOR(i,1,N){
            int ma=0;
            if(i==7){
                bit[0].PB(i);
                continue;
            }
            REP(j,20){
                if((i>>j)&1)ma=j;
            }
            bit[ma].PB(i);
        }
        REP(i,20){
            REP(j,SZ(bit[i])){
                an[bit[i][j]-1]=bit[i][(j+1)%SZ(bit[i])];
            }
        }
        puts("YES");
        W(an);
        //REP(i,N)assert((an[i]&(i+1))&&an[i]!=i+1);
    }
}
int main(){
    int N;R(N);
    eq0(N);
    neq0(N);
    return 0;
}