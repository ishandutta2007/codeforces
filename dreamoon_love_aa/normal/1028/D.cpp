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
int a[SIZE],v[SIZE];
const int ADDD = 0;
const int ACCEPT = 1;
int type[SIZE];
void error(){
    W(0);
    exit(0);
}
int main(){
    int n; R(n);
    char s[16];
    VI d;
    REP(i,n){
        RS(s);
        if(s[1]=='D')a[i]=ADDD;
        else a[i]=ACCEPT;
        R(v[i]);
        d.PB(v[i]);
    }
    SORT_UNIQUE(d);
    REP(i,n)v[i]=GET_POS(d,v[i]);
    set<int>pos,neg;
    VI notyet;
    LL ans=1;
    REP(i,n){
        if(a[i]==ADDD){
            if(pos.size()&&v[i]>=*pos.begin()){
                pos.insert(v[i]);
                type[v[i]]=1;
            }
            else if(neg.size()&&v[i]<=*neg.rbegin()){
                neg.insert(v[i]);
                type[v[i]]=-1;
            }
            else{
                notyet.PB(v[i]);
            }
        }
        else{
            if(pos.size()&&*pos.begin()<v[i]){
                error();
            }
            if(neg.size()&&*neg.rbegin()>v[i]){
                error();
            }
            if(type[v[i]]==0)ans=ans*2%MOD;
            else if(type[v[i]]>0)pos.erase(v[i]);
            else neg.erase(v[i]);
            for(int x:notyet){
                if(x<v[i]){
                    type[x]=-1;
                    neg.insert(x);
                }
                else if(x>v[i]){
                    type[x]=1;
                    pos.insert(x);
                }
            }
            notyet.clear();
        }
    }
    ans=ans*(SZ(notyet)+1)%MOD;
    W(ans);
    return 0;
}