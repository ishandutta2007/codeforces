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
const int SIZE = 1<<18;
int n;
VI e[SIZE];
int lv[SIZE];
bool cmp(int x, int y){
    return lv[x] < lv[y];
}
void my_clear(){
    REP(i,n){
        VI tmp;
        e[i].swap(tmp);
    }
}
int bk[SIZE];
int num[SIZE];
void dfs(int x, int lt){
    num[x]=1;
    for(int y: e[x]){
        if(y==lt){
            continue;
        }
        bk[y]=x;
        lv[y]=lv[x]+1;
        dfs(y,x);
        num[x]+=num[y];
    }
}
bitset<SIZE>u;
VI ord[2];
PII pos[SIZE];
bool valid(int mm){
    REP(i,n)u[i]=0;
    REP(i,2)ord[i].clear();
    int it=0;
    VI tmp(mm);
    REP(i,mm)tmp[i]=i+1;
    sort(ALL(tmp),cmp);
    for(int xd=mm-1;xd>=0;xd--){
        int i=tmp[xd];
        if(!u[i]){
            if(it==2){
                return 0;
            }
            int now=i;
            while(now){
                ord[it].PB(now);
                if(u[now]) {
                    return 0;
                }
                u[now]=1;
                now=bk[now];
            }
            it++;
        }
    }
    REP(i,2){
        reverse(ALL(ord[i]));
        REP(j,SZ(ord[i])){
            pos[ord[i][j]]=MP(i,j);
        }
    }
    return 1;
}
LL an[SIZE];
void calc(LL v[], int i,LL res[]){
    if(!v[i]){
        res[i]=n-num[ord[i^1][0]];
    }else{
        res[i]=num[ord[i][v[i]-1]];
    }
}
void solve() {
    FOR(i,0,n)an[i]=0;
    dfs(0,0);
    int ll=1,rr=n-1;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(valid(mm))ll=mm;
        else rr=mm-1;
    }
    valid(ll);
    an[0]=n*(n-1LL)/2;
    an[1]=n*(n-1LL)/2;
    for(int y:e[0]){
        an[1]-=num[y]*(num[y]-1LL)/2;
    }
    LL v[2]={},res[2]={};
    for(int i=1;i<=ll;i++){
        v[pos[i].F]=max(v[pos[i].F],pos[i].S+1LL);
        REP(j,2){
            calc(v,j,res);
        }
        an[i+1]=res[0]*res[1];
    }
    for(int i=0;i<n;i++){
        an[i]-=an[i+1];
    }
    W(VL(an,an+n+1));
}
void input() {
    R(n);
    REPP(i, 1, n){
        int x, y;
        R(x, y);
        e[x].PB(y);
        e[y].PB(x);
    }
}
int main(){
    CASET {
        input();
        solve();
        my_clear();
    }
    return 0;
}