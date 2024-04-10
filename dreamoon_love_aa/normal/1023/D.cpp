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
LL ma[SIZE];
LL qq(int L,int R,int id,int x){
    if(L==R)return ma[id];
    int mm=(L+R)/2;
    if(x<=mm)return max(ma[id],qq(L,mm,id*2,x));
    else return max(ma[id],qq(mm+1,R,id*2+1,x));
}
void ins(int L,int R,int id,int ll,int rr,LL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        ma[id]=v;
        return;
    }
    int mm=(L+R)/2;
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
}
int a[SIZE],b[SIZE];
int l[SIZE],r[SIZE];
int main(){
    int  n,q; R(n,q);
    bool contain_zero=false,contain_q=false;
    FOR(i,1,n){
        R(a[i]);
        if(a[i]){
            if(!l[a[i]]){
                l[a[i]]=r[a[i]]=i;
            }
            else{
                l[a[i]]=min(l[a[i]],i);
                r[a[i]]=max(r[a[i]],i);
            }
        }
        else contain_zero=true;
        if(a[i]==q)contain_q=true;
    }
    if(!contain_zero&&!contain_q){
        W("NO");
        return 0;
    }
    FOR(i,1,q){
        if(l[i]){
            ins(1,n,1,l[i],r[i],i);
        }
    }
    FOR(i,1,n){
        b[i]=qq(1,n,1,i);
        if(a[i]&&a[i]!=b[i]){
            W("NO");
            return 0;
        }
    }
    FOR(i,1,n){
        if(!b[i])b[i]=1;
    }
    if(!contain_q){
        FOR(i,1,n){
            if(!a[i]){
                b[i]=q;
                break;
            }
        }
    }
    W("YES");
    W(VI(b+1,b+1+n));
    return 0;
}