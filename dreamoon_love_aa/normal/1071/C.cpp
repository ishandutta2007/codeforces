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
int a[SIZE];
int n;
VI an;
void big_one(int x){
    if(x<=6){
        an.PB(x);
        an.PB(x+3);
        an.PB(x+6);
        
        an.PB(x+3);
        an.PB(x+4);
        an.PB(x+5);

        an.PB(x+4);
        an.PB(x+5);
        an.PB(x+6);
    }
    else{
        an.PB(x-6);
        an.PB(x-3);
        an.PB(x);
        
        an.PB(x-6);
        an.PB(x-5);
        an.PB(x-4);

        an.PB(x-5);
        an.PB(x-4);
        an.PB(x-3);
    }
}
void solve_big(){
    VI ones;
    int r=n/3+12;
    for(int j=1;j+2<=n;j++){
        FOR(dd,1,1000){
            if(j-dd<1||j+dd>n)break;
            if(a[j]&&a[j-dd]&&a[j+dd]){
                a[j-dd]=0;
                a[j]=0;
                a[j+dd]=0;
                r--;
                an.PB(j-dd);
                an.PB(j);
                an.PB(j+dd);
            }
        }
    }
    FOR(i,1,n){
        if(a[i]==1)ones.PB(i);
    }
    set<int>H(ALL(ones));
    while(SZ(H)){
        if(SZ(H)*3<=r){
            for(int x: H){
                big_one(x);
            }
            break;
        }
        else{
            int x=*H.begin();
            int y=*next(H.begin());
            int z=y*2-x;
            if(z<=n){
                an.PB(x);
                an.PB(y);
                an.PB(z);
                r--;
                H.erase(x);
                H.erase(y);
                if(H.count(z)){
                    H.erase(z);
                }
                else H.insert(z);
            }
            else{
                z=n;
                if(n%2!=x%2)z--;
                y=(x+z)/2;
                an.PB(x);
                an.PB(y);
                an.PB(z);
                r--;
                H.erase(x);
                if(H.count(y)){
                    H.erase(y);
                }
                else H.insert(y);
                if(H.count(z)){
                    H.erase(z);
                }
                else H.insert(z);
            }
        }
    }
    W("YES");
    W(SZ(an)/3);
    for(int i=0;i<SZ(an);i+=3){
        W(an[i],an[i+1],an[i+2]);
    }
}
int gg[15][100],gg_r[15];
void solve_small(){
    VI mask;
    int gn=0;
    VI ker[100];
    FOR(dd,1,12){
        for(int j=1;j+dd*2<=n;j++){
            gg[j][gn]=1;
            gg[j+dd][gn]=1;
            gg[j+dd*2][gn]=1;
            ker[gn]={j,j+dd,j+dd*2};
            gn++;
        }
    }
    FOR(i,1,n){
        if(a[i]){
            gg_r[i]=1;
        }
    }
    int st=1;
    for(int i=0;i<gn;i++){
        int now=-1;
        for(int j=st;j<=n;j++){
            if(gg[j][i]){
                now=j;
                break;
            }
        }
        if(now==-1)continue;
        if(now!=st){
            REP(j,gn)swap(gg[now][j],gg[st][j]);
            swap(gg_r[now],gg_r[st]);
        }
        FOR(j,1,n){
            if(j==st)continue;
            if(gg[j][i]){
                REP(k,gn)gg[j][k]^=gg[st][k];
                gg_r[j]^=gg_r[st];
            }
        }
        st++;
    }
    FOR(i,st,n){
        if(gg_r[i]){
            W("NO");
            return;
        }
    }
    W("YES");
    for(int i=st-1;i>=1;i--){
        if(!gg_r[i])continue;
        for(int j=0;j<gn;j++){
            if(gg[i][j]){
                for(int x:ker[j]){
                    an.PB(x);
                }
                break;
            }
        }
    }
    W(SZ(an)/3);
    for(int i=0;i<SZ(an);i+=3){
        W(an[i],an[i+1],an[i+2]);
    }
}
int main(){
    R(n);
    FOR(i,1,n) R(a[i]);
    if(n<=12){
        solve_small();
    }
    else{
        solve_big();
    }
    return 0;
}