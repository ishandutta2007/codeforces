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
const int SIZE = 1e5+10;
int mat[17];
int MASK;
int AA[17][1<<17];
int nxt[SIZE][17];
int n,p;
char s[SIZE];
int get_bit(int x,int v){return (x>>v)&1;}
void build(){
    FOR(i,1,n){
        int me=s[i]-'a';
        memcpy(nxt[i],nxt[i-1],sizeof(nxt[i]));
        nxt[i][s[i]-'a']=i;
        VPII pp;
        REP(j,p){
            if(nxt[i-1][j]){
                pp.PB({nxt[i-1][j],j});
            }
        }
        sort(ALL(pp),greater<PII>());
        int now=MASK;
        REP(j,SZ(pp)){
            AA[me][now]|=1<<pp[j].S;
            now^=1<<pp[j].S;
        }
    }
}
void build2(){
    REP(i,p){
        for(int j=MASK;j>0;j--){
            AA[i][j]&=j;
            REP(k,p){
                if(get_bit(j,k)){
                    AA[i][j^(1<<k)]|=AA[i][j];
                }
            }
        }
    }
}
int cnt[26];
int bfs[1<<17],v[1<<17],u[1<<17];
bool good[1<<17];
int main(){
    R(n,p);
    MASK=(1<<p)-1;
    RS(s+1);
    REP(i,p){
        REP(j,p){
            int x; R(x);
            if(x)mat[i]|=1<<j;
        }
    }
    FOR(i,1,n)cnt[s[i]-'a']++;
    build();
    reverse(s+1,s+n+1);
    build();
    build2();
    FOR(i,0,MASK){
        good[i]=1;
        REP(j,p){
            if(get_bit(i,j)){
                if((mat[j]&AA[j][i])!=AA[j][i]){
                    good[i]=0;
                    break;
                }
            }
        }
        //if(good[i])W("good",i);
    }
    u[MASK]=1;
    bfs[0]=MASK;
    v[0]=n;
    int an=n;
    int rr=1;
    REP(i,rr){
        int me=bfs[i];
        REP(j,p){
            if(!get_bit(me,j))continue;
            int nxt=me^(1<<j);
            if(u[nxt])continue;
            if(!good[nxt])continue;
            u[nxt]=1;
            v[rr]=v[i]-cnt[j];
            an=min(an,v[rr]);
            bfs[rr++]=nxt;
        }
    }
    W(an);
    return 0;
}