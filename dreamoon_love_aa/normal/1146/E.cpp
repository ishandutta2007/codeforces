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
const int MAX_N = 100005;
char ty[SIZE],r[SIZE],fp[SIZE];
int AA[SIZE];
void push(int id){
    int d[2]={id*2,id*2+1};
    if(fp[id]){
        for(int nxt:d){
            if(r[nxt])r[nxt]=-r[nxt];
            else fp[nxt]^=1;
        }
    }
    else if(r[id]){
        for(int nxt:d){
            r[nxt]=r[id];
            fp[nxt]=0;
        }
    }
    fp[id]=r[id]=0;
}
void update(int L,int R,int id,int ll,int rr,int v){
    if(L>rr||R<ll)return;
    if(L>=ll&&R<=rr){
        r[id]=v;
        fp[id]=0;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    update(L,mm,id*2,ll,rr,v);
    update(mm+1,R,id*2+1,ll,rr,v);
}
void flip(int L,int R,int id,int ll,int rr){
    if(L>rr||R<ll)return;
    if(L>=ll&&R<=rr){
        if(r[id])r[id]=-r[id];
        else fp[id]^=1;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    flip(L,mm,id*2,ll,rr);
    flip(mm+1,R,id*2+1,ll,rr);
}
void calc(int L,int R,int id){
    if(L==R){
        if(r[id]==1)ty[L]=3;
        else if(r[id]==-1)ty[L]=0;
        else if(fp[id])ty[L]=1;
        else ty[L]=2;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    calc(L,mm,id*2);
    calc(mm+1,R,id*2+1);
}
int main(){
    int n,q; R(n,q);
    REP(i,n)R(AA[i]);
    REP(i,q){
        char c[4]; RS(c);
        int v; R(v);
        if(c[0]=='>'){
            v++;
            if(v>=0){
                v=max(v,1);
                update(1,MAX_N,1,v,MAX_N,-1);
            }
            else
            {
                v=-v;
                update(1,MAX_N,1,v+1,MAX_N,-1);
                flip(1,MAX_N,1,1,v);
            }
        }
        else{
            v--;
            if(v<=0){
                v=min(v,-1);
                update(1,MAX_N,1,-v,MAX_N,1);
            }
            else
            {
                update(1,MAX_N,1,v+1,MAX_N,1);
                flip(1,MAX_N,1,1,v);
            }
        }
    }
    calc(1,MAX_N,1);
    VI res;
    REP(i,n){
        if(AA[i]>=0){
            if(ty[AA[i]]&2)res.PB(AA[i]);
            else res.PB(-AA[i]);
        }
        else{
            if(ty[-AA[i]]&1)res.PB(-AA[i]);
            else res.PB(AA[i]);
        }
    }
    W(res);
    return 0;
}