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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 300001;
VI fac[SIZE];
int n,k,an[SIZE];
bitset<SIZE>u;
void dfs(int x,int m,int r){
    if(!r){
        W("Yes");
        W(m);
        W(VI(an,an+m));
        exit(0);
    }
    if(x>n)return;
    int nxt_r=r;
    REP(i,SZ(fac[x])){
        if(u[fac[x][i]])nxt_r--;
    }
    if(nxt_r>=0){
        u[x]=1;
        an[m]=x;
        dfs(x+1,m+1,nxt_r);
        u[x]=0;
    }
    dfs(x+1,m,r);
}
void print(){
    VI ans;
    W("Yes");
    FOR(i,1,n){
        if(u[i])ans.PB(i);
    }
    W(SZ(ans));
    W(ans);
    exit(0);
}
int main(){
    R(n,k);
    int sum=0;
    FOR(i,1,n){
        for(int j=i+i;j<=n;j+=i)fac[j].PB(i);
        sum+=n/i-1;
    }
    if(sum<k)W("No");
    else if(sum==k){
        W("Yes");
        W(n);
        FOR(i,1,n)W(i);
    }
    else{
        if(n<=23){
            dfs(1,0,k);
            W("No");
        }
        else{
            FOR(i,1,n)u[i]=1;
            FOR(i,1,n){
                int cnt=0;
                REP(j,SZ(fac[i])){
                    if(u[fac[i][j]])cnt++;
                }
                cnt+=n/i-1;
                if(sum-cnt>=k){
                    u[i]=0;
                    sum-=cnt;
                    if(sum==k)print();
                }
            }
            n=23;
            dfs(1,0,k);
            assert(0);
        }
    }
    return 0;
}