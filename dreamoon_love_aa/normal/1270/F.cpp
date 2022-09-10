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
const int AA=800;
char s[SIZE];
int n;
int one_cnt;
inline LL g(int m,int d){
    if(m<d)return 0;
    int up=m-d+1;
    int down=up%d;
    return (LL)(up+down)*((up-down)/d+1)/2;
}
inline LL f(int x,int y,int z,int d){
    //W("|",x,y,z,d);
    return g(z,d)-g(y-1,d)-g(z-x-1,d)+g(y-x-2,d);
}
LL an;
int d[SIZE];
void solve_case1(){
    int dn=0;
    d[dn++]=-1;
    REP(i,n){
        if(s[i]=='1')d[dn++]=i;
    }
    d[dn]=n;
    REPP(i,1,dn){
        int bb=min(dn,i+AA);
        REPP(j,i,bb){
            an+=f(d[i]-d[i-1]-1,d[j]-d[i-1],d[j+1]-d[i-1]-1,j-i+1);
            //W(i,j,an);
        }
    }
}
LL tmp[SIZE];
int tmp2[SIZE];
short ccc[400000*500];
int cc[400000*10];
LL C2(LL x){
    return x*(x-1)/2;
}
void solve_case2(){
    int D=n/(AA+1);
    for(int i=0,j;i<n;i=j){
        if(s[i]=='0'){
            j=i+1;
            continue;
        }
        for(j=i+1;s[j]=='1';j++);
        int num=j-i;
        if(num>AA)an+=C2(num-AA+1);
    }
    FOR(mul,2,min(10,D)){
        int now;
        tmp[0]=now=200000*10;
        int tn=1;
        int ll=0;
        REP(i,n){
            now+=(s[i]=='1')?(mul-1):(-1);
            tmp[tn]=now;
            tmp2[tn]=tmp2[i]+(s[i]=='1');
            while(tmp2[tn]-tmp2[ll]>AA){
                cc[tmp[ll]]++;
                ll++;
            }
            an+=cc[tmp[tn++]];
        }
        REP(i,tn)cc[tmp[i]]=0;
    }
    FOR(mul,min(10,D)+1,D){
        int now;
        tmp[0]=now=200000*500;
        int tn=1;
        int ll=0;
        REP(i,n){
            now+=(s[i]=='1')?(mul-1):(-1);
            tmp[tn]=now;
            tmp2[tn]=tmp2[i]+(s[i]=='1');
            while(tmp2[tn]-tmp2[ll]>AA){
                ccc[tmp[ll]]++;
                ll++;
            }
            an+=ccc[tmp[tn++]];
        }
        REP(i,tn)ccc[tmp[i]]=0;
    }
}
int main(){
    RS(s);
    n=LEN(s);
    REP(i,n){
        if(s[i]=='1') one_cnt++;
    }
    if(one_cnt==0){
        W(0);
        return 0;
    }
    solve_case1();
    solve_case2();
    W(an);
    return 0;
}