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
int n;
LL k;
int a[SIZE];
int zero_cnt[SIZE];
LL sum[SIZE];
void solve() {
    FOR(i,1,n){
        sum[i]=sum[i-1];
        zero_cnt[i]=zero_cnt[i-1];
        if(a[i]==0){
            zero_cnt[i]++;
        }else{
            sum[i]+=a[i];
        }
    }
    if(abs(sum[n])>k*zero_cnt[n]){
        W(-1);
        return;
    }
    LL an=0;
    FOR(i,0,n)FOR(j,i,n){
        LL left1=sum[i]-zero_cnt[i]*k;
        LL right1=sum[i]+zero_cnt[i]*k;

        LL left2=(sum[j]-sum[i])-(zero_cnt[j]-zero_cnt[i])*k;
        LL right2=(sum[j]-sum[i])+(zero_cnt[j]-zero_cnt[i])*k;
        
        LL left3=(sum[n]-sum[j])-(zero_cnt[n]-zero_cnt[j])*k;
        LL right3=(sum[n]-sum[j])+(zero_cnt[n]-zero_cnt[j])*k;
        if(right1>=0&&right3>=0){
            LL ma1=right1+right3;
            LL mi1=max(0LL,left1)+max(0LL,left3);
            LL ma2=-left2;
            LL mi2=-right2;
            if(ma2>=mi1&&ma1>=mi2)an=max(an,min(ma2,ma1));
        }
        if(left1<=0&&left3<=0){
            LL ma1=-left1-left3;
            LL mi1=max(0LL,-right1)+max(0LL,-right3);
            LL mi2=left2;
            LL ma2=right2;
            if(ma2>=mi1&&ma1>=mi2)an=max(an,min(ma2,ma1));
        }
    }
    W(an+1);
}
void input() {
    R(n,k);
    FOR(i,1,n)R(a[i]);
}
int main(){
    input();
    solve();
    return 0;
}