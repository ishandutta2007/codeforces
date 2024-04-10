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

const int SIZE = 1<<20;
int a[SIZE],n,m;
LL sum[SIZE];
VI stu[SIZE];
string an[SIZE];
// compare a/b and c/d
bool cmp_fraction(LL a, LL b, LL c, LL d){
    return a * d < b * c;
}
bool cmp(int x, int y){
    return cmp_fraction(sum[x],SZ(stu[x]),sum[y],SZ(stu[y]));
}
bool my_equal(LL a, LL b, LL c, LL d){
    return a * d == b * c;
}
int d[SIZE];
int dp[3][SIZE];
void solve() {
    sort(a+1,a+n+1,greater<int>());
    REP(i,m)d[i+1]=i;
    sort(d+1,d+m+1,cmp);
    reverse(d+1,d+m+1);
    FOR(i,1,m){
        REP(j,3)dp[j][i]=dp[j][i-1];
        if(!cmp_fraction(a[i],1,sum[d[i]],SZ(stu[d[i]]))){
            dp[1][i]++;
        }
        if(i==1||!cmp_fraction(a[i],1,sum[d[i-1]],SZ(stu[d[i-1]]))){
            dp[0][i]++;
        }
        if(i==m||!cmp_fraction(a[i],1,sum[d[i+1]],SZ(stu[d[i+1]]))){
            dp[2][i]++;
        }
    }
    FOR(i,1,m){
        REP(j,SZ(stu[d[i]])){
            LL p=sum[d[i]]-stu[d[i]][j];
            LL q=SZ(stu[d[i]])-1;
            if(my_equal(p,q,sum[d[i]],SZ(stu[d[i]]))){
                if(dp[1][m]==m){
                    an[d[i]][j]='1';
                }
            }else{
                if(cmp_fraction(p,q,sum[d[i]],SZ(stu[d[i]]))){
                    int ll=i,rr=m;
                    while(ll<rr){
                        int mm=(ll+rr+1)/2;
                        if(cmp_fraction(p,q,sum[d[mm]],SZ(stu[d[mm]]))){
                            ll=mm;
                        }else{
                            rr=mm-1;
                        }
                    }
                    if(!cmp_fraction(a[ll],1,p,q)&&dp[1][i-1]+dp[1][m]-dp[1][ll]+dp[2][ll-1]-dp[2][i-1]==m-1){
                        an[d[i]][j]='1';
                    }
                }else{
                    int ll=1,rr=i;
                    while(ll<rr){
                        int mm=(ll+rr)/2;
                        if(cmp_fraction(p,q,sum[d[mm]],SZ(stu[d[mm]]))){
                            ll=mm+1;
                        }else{
                            rr=mm;
                        }
                    }
                    if(!cmp_fraction(a[ll],1,p,q)&&dp[1][ll-1]+dp[1][m]-dp[1][i]+dp[0][i]-dp[0][ll]==m-1){
                        an[d[i]][j]='1';
                    }
                }
            }
        }
    }
    REP(i,m){
        _W(an[i]);
    }
    W("");
}
void input() {
    R(n,m);
    FOR(i,1,n)R(a[i]);
    REP(i,m){
        int k;
        R(k);
        an[i]=string(k,'0');
        sum[i]=0;
        stu[i].clear();
        REP(j,k){
            int x;
            R(x);
            stu[i].PB(x);
            sum[i]+=x;
        }
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}