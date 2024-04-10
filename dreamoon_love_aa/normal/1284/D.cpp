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
PII a[SIZE],b[SIZE];
int n;
int tn;
int tmp[SIZE];
void read(){
    R(n);
    REP(i,n){
        R(a[i].F,a[i].S);
        R(b[i].F,b[i].S);
        tmp[tn++]=a[i].F;
        tmp[tn++]=a[i].S;
        tmp[tn++]=b[i].F;
        tmp[tn++]=b[i].S;
    }
    sort(tmp,tmp+tn);
    tn=unique(tmp,tmp+tn)-tmp;
    REP(i,n){
        a[i].F=lower_bound(tmp,tmp+tn,a[i].F)-tmp;
        a[i].S=lower_bound(tmp,tmp+tn,a[i].S)-tmp;
        b[i].F=lower_bound(tmp,tmp+tn,b[i].F)-tmp;
        b[i].S=lower_bound(tmp,tmp+tn,b[i].S)-tmp;
    }
}
VI ids[SIZE],ids2[SIZE];
bool evel(PII c[],PII d[]){
    REP(i,tn){
        ids[i].clear();
        ids2[i].clear();
    }
    REP(i,n){
        ids[c[i].F].PB(i);
        ids2[c[i].S].PB(i);
    }
    set<int>ker;
    set<int>AA;
    REP(i,tn)ker.insert(i);
    REP(i,tn){
        for(int id:ids[i]){
            auto it=AA.lower_bound(d[id].F);
            if(it!=AA.end()&&*it<=d[id].S)return 1;
        }
        for(int id:ids2[i]){
            auto it=ker.lower_bound(d[id].F);
            auto it2=it;
            while(it2!=ker.end()&&*it2<=d[id].S){
                AA.insert(*it2);
                it2++;
            }
            ker.erase(it,it2);
        }
    }
    return 0;
}
bool solve(){
    if(evel(a,b))return 0;
    if(evel(b,a))return 0;
    REP(i,n){
        a[i]=MP(tn-1-a[i].S,tn-1-a[i].F);
        b[i]=MP(tn-1-b[i].S,tn-1-b[i].F);
    }
    if(evel(a,b))return 0;
    if(evel(a,b))return 0;
    return 1;
}
int main(){
    read();
    W(solve()?"YES":"NO");
    return 0;
}