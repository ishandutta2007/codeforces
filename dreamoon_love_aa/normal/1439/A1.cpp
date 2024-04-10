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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int n,m;
string s[SIZE];
void flip(VI AA){
    REP(j,6){
        s[AA[j]][AA[j+1]]^=1;
        j++;
    }
}
VI base[4]={
    {0,0,0,1,1,0},
    {1,1,0,1,1,0},
    {0,0,1,1,1,0},
    {0,0,0,1,1,1},
};
int get_bit(long long x, int v) { return (x >> v) & 1; }
int ty[16];
void build(){
    REP(i,16){
        int me=0;
        REP(j,4){
            if(get_bit(i,j)){
                for(int k=0;k<6;k+=2){
                    me^=1<<(2*base[j][k]+base[j][k+1]);
                }
            }
        }
        ty[me]=i;
    }
}
void solve() {
    FOR(i,1,n){
        R(s[i]);
        s[i]=" " + s[i];
    }
    vector<VI>an;
    if(m%2){
        for(int i=n;i>1;i--){
            if(s[i][m]=='1'){
                an.PB({i,m,i,m-1,i-1,m-1});
                flip(an.back());
            }
        }
        if(s[1][m]=='1'){
            an.PB({1,m,1,m-1,2,m-1});
            flip(an.back());
        }
    }
    if(n%2){
        FOR(i,1,m-m%2-1){
            if(s[n][i]=='1'){
                an.PB({n,i,n-1,i,n-1,i+1});
                flip(an.back());
            }
        }
        if(s[n][m-m%2]=='1'){
            an.PB({n,m-m%2,n-1,m-m%2,n-1,m-m%2-1});
            flip(an.back());
        }
    }
    for(int i=1;i+1<=n;i+=2){
        for(int j=1;j+1<=m;j+=2){
            int me=(s[i][j]-'0')+(s[i][j+1]-'0')*2+(s[i+1][j]-'0')*4+(s[i+1][j+1]-'0')*8;
            REP(k,4){
                if(get_bit(ty[me],k)){
                    an.PB(base[k]);
                    for(int r=0;r<6;r+=2){
                        an.back()[r]+=i;
                        an.back()[r+1]+=j;
                    }
                }
            }
        }
    }
    W(SZ(an));
    REP(i,SZ(an))W(an[i]);
}
void input() {
    R(n,m);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    build();
    CASET {
        input();
        solve();
    }
    return 0;
}