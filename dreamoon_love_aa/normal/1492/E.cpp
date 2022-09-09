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
#define PB emplace_back
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
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<18;
int get_bit(int x, int v) { return (x >> v) & 1; }
VI a[SIZE];
int n,m;
void check(VI an){
    REP(i,n){
        int v=0;
        REP(j,m){
            v+=(a[i][j]!=an[j]);
        }
        if(v>2)return;
    }
    W("Yes");
    W(an);
    exit(0);
}
void solve() {
    int compare_row=-1;
    REPP(i,1,n){
        int diff_num=0;
        REP(j,m){
            diff_num+=(a[0][j]!=a[i][j]);
        }
        if(diff_num>4){
            W("No");
            return;
        }
        if(diff_num>2){
            compare_row=i;
        }
    }
    if(compare_row==-1){
        W("Yes");
        W(a[0]);
        return;
    }else{
        VI sp;
        REP(i,m){
            if(a[0][i]!=a[compare_row][i]){
                sp.PB(i);
            }
        }
        REP(i,1<<SZ(sp)){
            if(__builtin_popcount(i)!=2){continue;}
            VI d;
            REP(j,SZ(sp)){
                if(get_bit(i,j)){
                    d.PB(sp[j]);
                }
            }
            bool suc=1;
            VI an=a[0];
            VPII gg;
            REP(x,n){
                int v=0;
                REP(y,m){
                    if(y!=d[0]&&y!=d[1]){
                        v+=(an[y]!=a[x][y]);
                    }
                }
                if(v==2){
                    an[d[0]]=a[x][d[0]];
                    an[d[1]]=a[x][d[1]];
                    check(an);
                    suc=0;
                    break;
                }
                if(v==1){
                    gg.PB(MP(a[x][d[0]],a[x][d[1]]));
                }
            }
            if(suc&&SZ(gg)==0){
                W("Yes");
                W(an);
                return;
            }else if(suc){
                int res=-1;
                REPP(i,1,SZ(gg)){
                    if(gg[i].F!=gg[0].F){
                        if(res==-1||res==gg[i].S){res=gg[i].S;}
                        else res=-2;
                    }
                }
                if(res!=-2){
                    an[d[0]]=gg[0].F;
                    if(res!=-1)an[d[1]]=res;
                    W("Yes");
                    W(an);
                    return;
                }
                res=-1;
                REPP(i,1,SZ(gg)){
                    if(gg[i].S!=gg[0].S){
                        if(res==-1||res==gg[i].F){res=gg[i].F;}
                        else res=-2;
                    }
                }
                if(res!=-2){
                    an[d[1]]=gg[0].S;
                    if(res!=-1)an[d[0]]=res;
                    W("Yes");
                    W(an);
                    return;
                }
            }
        }
        W("No");
    }
}
void input() {
    R(n,m);
    REP(i,n){
        a[i].resize(m);
        REP(j,m)R(a[i][j]);
    }
}
int main(){
    input();
    solve();
    return 0;
}