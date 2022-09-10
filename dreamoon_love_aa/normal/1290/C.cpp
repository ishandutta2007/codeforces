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
const int SIZE = 3e5+10;
int NOW;
struct Union_Find{
    int d[SIZE],num[SIZE],v[SIZE],cnt[SIZE][2],known[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,cnt[i][0]=1,cnt[i][1]=0,known[i]=-1;
    }
    bool is_root(int x){return d[x]==x;}
    void find(int &x,int &ty){
        while(x!=d[x]){
            ty^=v[x];
            x=d[x];
        }
    }
    int get(int x){
        if(known[x]==-1) return min(cnt[x][0], cnt[x][1]);
        return cnt[x][1^known[x]];
    }
    void assign(int x,int ty){
        find(x,ty);
        NOW -= get(x);
        known[x] = ty;
        NOW += get(x);
    }
    bool uu(int x,int y,int ty){
        find(x,ty);
        find(y,ty);
        if(x==y)return 0;
        NOW -= get(x);
        NOW -= get(y);
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        REP(i,2)cnt[y][i]+=cnt[x][i^ty];
        if(known[x]!=-1)known[y]=known[x]^ty;
        v[x]=ty;
        d[x]=y;
        NOW += get(y);
        return 1;
    }
}U;
char s[SIZE];
VI AA[SIZE];
int main(){
    int n,k;
    R(n,k);
    RS(s+1);
    REP(i,k){
        int m;
        R(m);
        REP(j,m){
            int x;
            R(x);
            AA[x].PB(i);
        }
    }
    U.init(k);
    FOR(i,1,n){
        if(SZ(AA[i])==1){
            U.assign(AA[i][0],'1'-s[i]);
        }
        else if(SZ(AA[i])==2){
            U.uu(AA[i][0],AA[i][1],'1'-s[i]);
        }
        W(NOW);
    }
    return 0;
}