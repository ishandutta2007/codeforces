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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
// notice that the gcd part is too slow!
struct Frac{
    LL pp,qq;
    Frac(LL _pp=0,LL _qq=1):pp(_pp),qq(_qq){
        if(!qq)fprintf(stderr,"err!\n");
        if(qq<0){
            qq=-qq;
            pp=-pp;
        }
        if(!pp)qq=1;
    }
    bool operator<(const Frac& b)const{
        return pp*b.qq<b.pp*qq;
    }
    bool operator==(const Frac& b)const{
        return pp*b.qq==qq*b.pp;
    }
    Frac operator+(Frac b){
        LL gg=__gcd(qq,b.qq);
        LL x=pp*(b.qq/gg)+b.pp*(qq/gg);
        LL y=qq/gg*b.qq;
        return Frac(x,y);
    }
    Frac operator-(Frac b){
        b.pp=-b.pp;
        return *this+b;
    }
    Frac operator*(Frac b){
        LL gg1=__gcd(pp,b.qq);
        LL gg2=__gcd(b.pp,qq);
        return Frac(pp/gg1*(b.pp/gg2),qq/gg2*(b.qq/gg1));
    }
    Frac operator/(Frac b){
        swap(b.pp,b.qq);
        return *this*b;
    }
    void print(){
        cout<<pp<<"/"<<qq<<endl;
    }
};
pair<Frac,Frac>pp[SIZE];
struct BIT{
    int _n;
    LL _d[SIZE];
    void init(int __n){
        _n=__n;
        memset(_d,0,sizeof(LL)*(_n+1));
    }
    void ins(int x,LL v){
        for(;x<=_n;x+=x&-x)_d[x]+=v;
    }
    LL qq(int x){
        LL res=0;
        for(;x;x-=x&-x)res+=_d[x];
        return res;
    }
    LL qq_range(int x,int y){
        LL ret=qq(y);
        if(x)ret-=qq(x-1);
        return ret;
    }
}bit;
//TODO init
int main(){
    int n,w; R(n,w);
    REP(i,n){
        int x,v;
        R(x,v);
        pp[i]=MP(Frac(x,-(v-w)),Frac(x,-(v+w)));
    }
    sort(pp,pp+n);
    vector<Frac>ker;
    REP(i,n){
        ker.PB(pp[i].S);
    }
    sort(ALL(ker));
    for(int i=0,j;i<n;i=j){
        for(j=i+1;j<n&&pp[j].F==pp[i].F;j++);
        reverse(pp+i,pp+j);
    }
    int sz=0;
    REP(i,SZ(ker)){
        if(sz&&ker[i]==ker[sz-1])continue;
        ker[sz++]=ker[i];
    }
    bit.init(sz+10);
    ker.resize(sz);
    LL an=0;
    for(int i=n-1;i>=0;i--){
        int x=lower_bound(ALL(ker),pp[i].S)-ker.begin()+1;
        an+=bit.qq(x);
        bit.ins(x,1);
    }
    W(an);
    return 0;
}