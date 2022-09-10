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
char s[SIZE];
const int P_NUM = 7;
LL dp[P_NUM][SIZE];
LL dp2[P_NUM][SIZE];
int p[P_NUM];
bool is_prime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
}
void print(int x,int y,int z){
    FOR(i,1,x)printf("%c",s[i]);
    printf("+");
    FOR(i,x+1,y)printf("%c",s[i]);
    printf("=");
    FOR(i,y+1,z)printf("%c",s[i]);
    W("");
    exit(0);
}
LL get(int x,int y,int id){
    LL ret=(dp[id][y]-dp[id][x-1]*dp2[id][y-x+1])%p[id];
    if(ret<0)ret+=p[id];
    return ret;
}
bool valid2(int x,int y){
    if(x==y)return 1;
    if(s[x]=='0')return 0;
    return 1;
}
bool valid(int x,int y,int z){
    if(!x||x==y)return 0;
    REP(i,P_NUM){
        if((get(1,x,i)+get(x+1,y,i)-get(y+1,z,i))%p[i])return 0;
    }
    if(!valid2(1,x)||!valid2(x+1,y)||!valid2(y+1,z))return 0;
    return 1;
}
int main(){
    p[0]=101000001;
    REPP(i,1,P_NUM){
        p[i]=p[i-1]+200000000;
    }
    RS(s+1);
    int n=LEN(s+1);
    REP(i,P_NUM){
        while(!is_prime(p[i]))p[i]++;
    }
    REP(i,P_NUM){
        dp2[i][0]=1;
        FOR(j,1,n)dp2[i][j]=(dp2[i][j-1]*10)%p[i];
    }
    REP(i,4){
        FOR(j,1,n){
            dp[i][j]=(dp[i][j-1]*10+s[j]-'0')%p[i];
        }
    }
    for(int k=n/2;k>0;k--){
        int x=k,y=n-2*k,z=k;
        if(valid(x,x+y,n))print(x,x+y,n);
        x=k-1,y=n-2*k+1,z=k;
        if(valid(x,x+y,n))print(x,x+y,n);
        y=k,x=n-2*k,z=k;
        if(valid(x,x+y,n))print(x,x+y,n);
        y=k-1,x=n-2*k+1,z=k;
        if(valid(x,x+y,n))print(x,x+y,n);
    }
    return 0;
}