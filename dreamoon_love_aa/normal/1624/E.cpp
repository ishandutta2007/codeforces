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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<10;
int n,m;
char s[SIZE][SIZE];
string t;
pair<PII,int> two[SIZE],three[SIZE];
int from[SIZE];
void print(int x, int lv){
    if(!x){
        W(lv);
        return;
    }
    print(from[x], lv+1);
    if(from[x]==x-2){
        int v=(t[x-2]-'0')*10+(t[x-1]-'0');
        W(two[v]);
    }else{
        int v=(t[x-3]-'0')*100+(t[x-2]-'0')*10+(t[x-1]-'0');
        W(three[v]);
    }
}
void solve() {
    REP(i,100)two[i]=MP(MP(-1,-1),-1);
    REP(i,1000)three[i]=MP(MP(-1,-1),-1);
    REP(i,n){
        REP(j,m){
            if(j+2<=m){
                two[(s[i][j]-'0')*10+(s[i][j+1]-'0')]=MP(MP(j+1,j+2),i+1);
            }
            if(j+3<=m){
                three[(s[i][j]-'0')*100+(s[i][j+1]-'0')*10+(s[i][j+2]-'0')]=MP(MP(j+1,j+3),i+1);
            }
        }
    }
    FOR(i,1,SZ(t)){
        from[i]=-1;
        if(i>=2){
            int v=(t[i-2]-'0')*10+(t[i-1]-'0');
            if(two[v].S!=-1&&from[i-2]!=-1){
                from[i]=i-2;
            }
        }
        if(i>=3){
            int v=(t[i-3]-'0')*100+(t[i-2]-'0')*10+(t[i-1]-'0');
            if(three[v].S!=-1&&from[i-3]!=-1){
                from[i]=i-3;
            }
        }
    }
    if(from[SZ(t)]==-1)W(-1);
    else{
        print(SZ(t),0);
    }
}
void input() {
    R(n,m);
    REP(i,n)RS(s[i]);
    R(t);

}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}