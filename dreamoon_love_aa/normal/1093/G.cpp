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
int N,K;
struct Seg{
    int d[1<<19];
    void init(int L,int R,int id){
        d[id]=INT_MIN;
        if(L==R)return;
        int mm=(L+R)/2;
        init(L,mm,id*2);
        init(mm+1,R,id*2+1);
    }
    void ins(int L,int R,int id, int x,int v){
        int mm=(L+R)/2;
        if(L==R){
            d[id]=v;
            return;
        }
        if(x<=mm)ins(L,mm,id*2,x,v);
        else ins(mm+1,R,id*2+1,x,v);
        d[id]=max(d[id*2],d[id*2+1]);
    }
    int qq(int L,int R,int id,int ll,int rr){
        if(R<ll||L>rr)return INT_MIN;
        if(L>=ll&&R<=rr)return d[id];
        int mm=(L+R)/2;
        return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
    }
}ma[32];
int main(){
    R(N,K);
    REP(i,1<<K)ma[i].init(1,N,1);
    FOR(i,1,N){
        int v[5];
        REP(j,K)R(v[j]);
        REP(j,1<<K){
            int now=0;
            REP(k,K){
                if((j>>k)&1)now+=v[k];
                else now-=v[k];
            }
            ma[j].ins(1,N,1,i,now);
        }
    }
    int q; R(q);
    int mask=(1<<K)-1;
    while(q--){
        int ty; R(ty);
        if(ty==1){
            int id; R(id);
            int v[5];
            REP(j,K)R(v[j]);
            REP(j,1<<K){
                int now=0;
                REP(k,K){
                    if((j>>k)&1)now+=v[k];
                    else now-=v[k];
                }
                ma[j].ins(1,N,1,id,now);
            }
        }
        else{
            int l,r; R(l,r);
            int an=0;
            REP(i,1<<(K-1)){
                an=max(an,abs(ma[i].qq(1,N,1,l,r)+ma[i^mask].qq(1,N,1,l,r)));
            }
            W(an);
        }
    }
    return 0;
}