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
#define PB emplace_back
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<13;
LL INF=1e18;
int n;
LL t[SIZE],x[SIZE];
bool dp[SIZE][2];
LL fast[SIZE];
void update1(int id,LL v){
    if(!dp[id][1]){
        dp[id][1]=1;
        fast[id]=v;
    }else{
        fast[id]=min(fast[id],v);
    }
}
void solve() {
    if(abs(x[1])>t[1]){
        W("NO");
        return;
    }
    FOR(i,0,n)fast[i]=INF;
    {
        bool very_easy=1;
        FOR(i,1,n){
            if(abs(x[i]-x[i-1])>t[i]-t[i-1]){
                very_easy=0;
            }
        }
        if(very_easy){
            W("YES");
            return;
        }
    }
    dp[1][1]=1;
    fast[1]=abs(x[1]);
    FOR(i,2,n){
        bool easy=0;
        if(dp[i-1][1]){
            LL sp_t=max(fast[i-1]+abs(x[i]-x[i-1]),t[i-1]);
            if(sp_t<=t[i]){
                update1(i,sp_t);
            }
        }
        if(dp[i-1][0]){
            LL sp_t=max(t[i-2]+abs(x[i]-x[i-2]),t[i-1]);
            if(sp_t<=t[i]){
                update1(i,sp_t);
            }
        }
        for(int j=i-1;j>=0;j--){
            if(j+1<i){
                if(abs(x[j]-x[i])+abs(x[i]-x[j+1])<=abs(t[j+1]-t[j])){
                    easy=1;
                }
                if(abs(x[j+1]-x[j])>t[j+1]-t[j]){
                    break;
                }
            }
            if(j>0){
                if(dp[j-1][0]){
                    if(easy&&abs(x[j-2]-x[j])<=t[j]-t[j-2]){
                        dp[i][0]=1;
                    }
                    LL sp_t=max(t[j-1],t[j-2]+abs(x[j-2]-x[i]));
                    if(sp_t<=t[j]&&abs(x[i]-x[j])<=t[j]-sp_t){
                        dp[i][0]=1;
                    }
                    if(abs(x[j]-x[j-2])<=t[j]-t[j-2]&&abs(x[i]-x[i-1])<=t[i]-t[i-1]){
                        update1(i,t[i-1]+abs(x[i]-x[i-1]));
                    }
                }
                if(dp[j-1][1]){
                    LL sp_t=fast[j-1]; //time sp_t at x[j-1]
                    if(easy&&abs(x[j]-x[j-1])<=t[j]-sp_t){
                        dp[i][0]=1;
                    }
                    int sp2_t=max(t[j-1],sp_t+abs(x[i]-x[j-1]));
                    if(sp2_t<=t[j]&&sp2_t+abs(x[i]-x[j])<=t[j]){
                        dp[i][0]=1;
                    }
                    if(abs(x[j]-x[j-1])<=t[j]-sp_t&&abs(x[i]-x[i-1])<=t[i]-t[i-1]){
                        update1(i,t[i-1]+abs(x[i]-x[i-1]));
                    }
                }
            }else{
                if(easy){
                    dp[i][0]=1;
                }
                if(abs(x[i]-x[i-1])<=t[i]-t[i-1]){
                    update1(i,t[i-1]+abs(x[i]-x[i-1]));
                }
            }
        }
    }
    if(dp[n][0]||dp[n][1]){
        W("YES");
        return;
    }
    for(int j=n;j>1;j--){
        if(dp[j-1][0]){
            if(abs(x[j]-x[j-2])<=t[j]-t[j-2]){
                W("YES");
                return;
            }
        }
        if(dp[j-1][1]){
            if(abs(x[j]-x[j-1])+abs(x[j-1]-x[j-2])<=t[j]-t[j-2]){
                W("YES");
                return;
            }
        }
        if(abs(x[j]-x[j-1])>t[j]-t[j-1])break;
    }
    W("NO");
}
void input() {
    R(n);
    t[0]=x[0]=0;
    FOR(i,1,n){
        R(t[i],x[i]);
    }
}
int main(){
    input();
    solve();
    return 0;
}