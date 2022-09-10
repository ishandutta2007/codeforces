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
const int P_SIZE = 5032108;
int p[P_SIZE];
int ma_pos[P_SIZE][8];
vector<int>pp;
void prime_init(){
    for(int i=2;i<P_SIZE;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<P_SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
const int N_SIZE = 194600;
VPII qq[N_SIZE];
int AA[N_SIZE];
const int Q_SIZE = 1049660;
int an[Q_SIZE];
int read_int(){
    char s[24];
    RS(s);
    int v=0;
    for(int i=0;s[i];i++){
        v=v*10+s[i]-'0';
    }
    return v;
}
int now_prime[10],pn;
void get_prime(int x){
    pn=0;
    while(x!=1){
        int v=p[x];
        if(pn&&v==now_prime[pn-1])pn--;
        else now_prime[pn++]=v;
        x/=v;
    }
}
int ll[15];

template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
int NOW_POS;
void dfs(int x,int now,int v){
    if(x==pn){
        REP(i,8){
            maa(ll[i+v],ma_pos[now][i]);
        }
        ma_pos[now][v]=NOW_POS;
        return;
    }
    dfs(x+1,now,v);
    dfs(x+1,now*now_prime[x],v-1);
}
int main(){
    prime_init();
    int n,q;
    n=read_int();
    q=read_int();
    FOR(i,1,n)AA[i]=read_int();
    REP(i,q){
        int l,r;
        l=read_int();
        r=read_int();
        qq[r].PB({l,i});
    }
    FOR(i,1,n){
        NOW_POS=i;
        get_prime(AA[i]);
        dfs(0,1,pn);
        for(auto& x:qq[i]){
            for(int j=0;;j++){
                if(ll[j]>=x.F){
                    an[x.S]=j;
                    break;
                }
            }
        }
    }
    REP(i,q)W(an[i]);
    return 0;
}