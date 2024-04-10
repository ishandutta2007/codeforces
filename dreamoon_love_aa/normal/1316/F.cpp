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
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
const int SIZE = 1<<21;
PII p[SIZE],p2[SIZE];
LL res[SIZE],sl[SIZE],sr[SIZE],num[SIZE],NOW,two[SIZE];
void ins(int L,int R,int id,int pos){
    int mm=(L+R)/2;
    if(L==R){
        if(NOW>0){
            num[id]=1;
            sl[id]=sr[id]=NOW;
        }
        else{
            num[id]=0;
            sl[id]=sr[id]=0;
        }
        res[id]=0;
        return;
    }
    if(pos<=mm){
        ins(L,mm,id*2,pos);
    }
    else{
        ins(mm+1,R,id*2+1,pos);
    }
    sl[id]=(sl[id*2]+sl[id*2+1]*two[num[id*2]])%MOD;
    sr[id]=(sr[id*2+1]+sr[id*2]*two[num[id*2+1]])%MOD;
    num[id]=num[id*2]+num[id*2+1];
    res[id]=(res[id*2]*two[num[id*2+1]]+res[id*2+1]*two[num[id*2]]+sl[id*2]*sr[id*2+1])%MOD;
}
int rm_pos[SIZE];
int lt[SIZE];
int main(){
    two[0]=1;
    REPP(i,1,600001)two[i]=two[i-1]*2%MOD;
    int n;
    R(n);
    FOR(i,1,n){
        R(p[i].F);
        p[i].S=i;
        p2[i-1]=p[i];
        lt[i]=i;
    }
    int q;
    R(q);
    FOR(i,n+1,n+q){
        int x;
        R(x,p[i].F);
        rm_pos[i]=lt[x];
        lt[x]=i;
        p[i].S=i;
        p2[i-1]=p[i];
    }
    sort(p2,p2+n+q);
    FOR(i,1,n-1){
        NOW=p[i].F;
        int id=lower_bound(p2,p2+n+q,p[i])-p2;
        ins(0,n+q-1,1,id);
    }
    LL inv=mypow(two[n],MOD-2);
    FOR(i,n,n+q){
        NOW=p[i].F;
        int id=lower_bound(p2,p2+n+q,p[i])-p2;
        ins(0,n+q-1,1,id);
        if(i>n){
            NOW=-p[rm_pos[i]].F;
            id=lower_bound(p2,p2+n+q,p[rm_pos[i]])-p2;
            ins(0,n+q-1,1,id);
        }
        W(res[1]*inv%MOD);
    }
    return 0;
}