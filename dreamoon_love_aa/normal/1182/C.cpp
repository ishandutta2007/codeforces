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
bool vowel(char c){
    return c=='a'
        or c=='e'
        or c=='i'
        or c=='o'
        or c=='u';
}
map<pair<char,int>,VI>A;
map<int,VI>AA;
string words[SIZE];
VPII d[2];
int main(){
    int n;
    R(n);
    REP(i,n){
        R(words[i]);
        int cnt=0;
        char lt_char;
        REP(j,SZ(words[i])){
            if(vowel(words[i][j])){
                cnt++;
                lt_char=words[i][j];
            }
        }
        A[MP(lt_char,cnt)].PB(i);
    }
    int p1=0,p2=0;
    for(auto x:A){
        p1+=SZ(x.S)/2;
        int lt=-1;
        for(int v:x.S){
            if(lt==-1)lt=v;
            else{
                d[0].PB({lt,v});
                lt=-1;
            }
        }
        if(lt!=-1)AA[x.F.S].PB(lt);
    }
    for(auto x:AA){
        p2+=SZ(x.S)/2;
        int lt=-1;
        for(int v:x.S){
            if(lt==-1)lt=v;
            else{
                d[1].PB({lt,v});
                lt=-1;
            }
        }
    }
    W(min(p1,(p1+p2)/2));
    while(SZ(d[0])>SZ(d[1])+1){
        d[1].PB(d[0].back());
        d[0].pop_back();
    }
    if(SZ(d[0])>SZ(d[1]))d[0].resize(SZ(d[1]));
    REP(i,SZ(d[0])){
        W(words[d[1][i].F],words[d[0][i].F]);
        W(words[d[1][i].S],words[d[0][i].S]);
    }
    return 0;
}