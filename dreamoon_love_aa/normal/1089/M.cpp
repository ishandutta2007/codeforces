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
const int WoD = 100;
char s[30][4][WoD];
int cnt[10];
int AA[10][10];
VI d[10];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int lv[10];
int main(){
    int row=28;
    memset(s,'.',sizeof(s));
    REP(i,row){
        if(i%3==2){
            REP(k,4)REP(j,WoD)s[i][k][j]='#';
        }
    }
    int n; R(n);
    U.init(n+1);
    FOR(i,1,n)FOR(j,1,n){
        R(AA[i][j]);
    }
    FOR(i,1,n)AA[i][i]=1;
    FOR(k,1,n){
        FOR(i,1,n)FOR(j,1,n){
            AA[i][j]|=AA[i][k]&AA[k][j];
        }
    }
    FOR(i,1,n){
        REPP(j,1,i){
            if(AA[i][j]&&AA[j][i])U.uu(i,j);
        }
    }
    VPII pp;
    FOR(i,1,n){
        FOR(j,1,n){
          cnt[i]+=AA[i][j];
        }
        if(U.is_root(i)){
            pp.PB({cnt[i],i});
        }
    }
    sort(ALL(pp));
    FOR(i,1,n){
        REP(j,SZ(pp)){
            if(U.find(i)==pp[j].S){
                lv[i]=j+1;
                d[lv[i]].PB(i);
                break;
            }
        }
    }
    FOR(i,1,n){
        REP(j,SZ(d[i])){
            s[i*3][0][j]='0'+d[i][j];
        }
    }
    int col=1;
    FOR(i,1,n)REPP(j,1,i){
        if(SZ(d[i])==0||SZ(d[j])==0)continue;
        if(AA[d[i][0]][d[j][0]]){
            s[i*3-1][2][col]='.';
            REPP(rr,j*3+2,i*3){
                FOR(dx,-1,1)FOR(dy,-1,1){
                    if(dx==0&&dy==0)s[rr][2+dx][col+dy]='.';
                    else s[rr][2+dx][col+dy]='#';
                }
            }
            col+=2;
        }
    }
    W(WoD,4,row);
    for(int i=row-1;i>=0;i--){
        if(i!=row-1)W("");
        REP(j,4){
            REP(k,WoD)putchar(s[i][j][k]);
            W("");
        }
    }
    return 0;
}