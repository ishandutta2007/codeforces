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
const int SIZE = 1<<12;
int n,m;
int x[SIZE],y[SIZE],v[SIZE];
int res[SIZE];
VI e[SIZE];
int ty[SIZE];
bool dfs(int _x,int _v){
    ty[_x]=_v;
    for(int _y:e[_x]){
        if(ty[_y]){
            if(ty[_y]==ty[_x]){
                return 0;
            }
        }else{
            if(!dfs(_y,-_v))return 0;
        }
    }
    return 1;
}
void solve() {
    if(!dfs(1,1)){
        W("NO");
        return;
    }
    int ans=-1;
    int tmp[SIZE];
    auto maa = [](auto& x,auto y){if(x<y)x=y;};
    FOR(i,1,n){
        FOR(j,1,n)tmp[j]=0;
        tmp[i]=500000;
        REP(j,n){
            REP(k,m){
                if(v[k]==1){
                    if(tmp[x[k]]){
                        maa(tmp[y[k]],tmp[x[k]]+1);
                    }
                    if(tmp[y[k]]){
                        maa(tmp[x[k]],tmp[y[k]]-1);
                    }
                }else{
                    if(tmp[x[k]]){
                        maa(tmp[y[k]],tmp[x[k]]-1);
                    }
                    if(tmp[y[k]]){
                        maa(tmp[x[k]],tmp[y[k]]-1);
                    }
                }
            }
        }
        bool good=1;
        REP(k,m){
            if(v[k]==1){
                if(tmp[y[k]]!=tmp[x[k]]+1){
                    good=0;
                    break;
                }
            }else{
                if(abs(tmp[y[k]]-tmp[x[k]])!=1){
                    good=0;
                    break;
                }
            }
        }
        if(good){
            int now_ma=*max_element(tmp+1,tmp+n+1)-*min_element(tmp+1,tmp+n+1);
            if(now_ma>ans){
                ans=now_ma;
                FOR(j,1,n)res[j]=tmp[j];
            }
        }
    }
    if(ans==-1){
        W("NO");
        return;
    }
    W("YES");
    W(ans);
    FOR(i,1,n)W(res[i]);
}
void input() {
    R(n,m);
    REP(i,m){
        R(x[i],y[i],v[i]);
        e[x[i]].PB(y[i]);
        e[y[i]].PB(x[i]);
    }
}
int main(){
    input();
    solve();
    return 0;
}