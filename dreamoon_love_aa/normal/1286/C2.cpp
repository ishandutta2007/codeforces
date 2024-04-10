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
int cnt[101][26];
char an[101];
pair<PII,pair<char,char>>e[10000];
int en;
void query(int l,int r){
    W("?",l,r);
    fflush(stdout);
    int num=(r-l+1);
    MS0(cnt);
    FOR(i,1,num*(num+1)/2){
        string s;
        R(s);
        if(SZ(s)<=(num+1)/2){
            for(char c:s){
                cnt[SZ(s)][c-'a']++;
            }
        }
    }
    int m=(num+1)/2;
    for(int i=m-1;i>=1;i--){
        REP(j,26)cnt[i+1][j]-=cnt[i][j];
    }
    for(int i=1;i<m;i++){
        REP(j,26)cnt[i][j]-=cnt[i+1][j];
    }
    string ret;
    FOR(i,1,m){
        REP(j,26){
            if(cnt[i][j]){
                cnt[i][j]--;
                ret+='a'+j;
                break;
            }
        }
    }
    for(int i=m;i>=1;i--){
        REP(j,26){
            if(cnt[i][j]){
                cnt[i][j]--;
                ret+='a'+j;
                break;
            }
        }
    }
    int ll=0,rr=num-1;
    while(ll<=rr){
        if(ll==rr){
            an[l]=ret[ll];
        }
        else{
            e[en++]=MP(MP(l,r),MP(ret[ll],ret[rr]));
        }
        ll++;
        rr--;
        l++;
        r--;
    }
}
int main(){
    int n;
    R(n);
    if(n==1){
        query(1,1);
    }
    else if(n%2==0){
        query(1,n-1);
        query(n/2,n-1);
        query(n/2,n);
    }
    else{
        query(1,n);
        query(1,n/2);
        query(1,n/2+1);
    }
    REP(i,1000){
        REP(j,en){
            if(an[e[j].F.F]){
                an[e[j].F.S]=(int)e[j].S.S+(int)e[j].S.F-an[e[j].F.F];
            }
            if(an[e[j].F.S]){
                an[e[j].F.F]=(int)e[j].S.S+(int)e[j].S.F-an[e[j].F.S];
            }
        }
    }
    W("!",string(an+1));
    return 0;
}