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
const int SIZE = 1<<20;
bitset<200001>an_set,now_set;
void solve() {
    int n,m,k;
    R(n,m,k);
    VPII d[4];
    VI AA;
    REP(i,n){
        int x,v1,v2;
        R(x,v1,v2);
        int v=(v1<<1)|v2;
        d[v].PB(MP(x,i+1));
    }
    REP(i,4)sort(ALL(d[i]));
    if(SZ(d[3])<k){
        if(SZ(d[3])+2*(k-SZ(d[3]))>m){
            W(-1);
            return;
        }
        if(min(SZ(d[1]),SZ(d[2]))<k-SZ(d[3])){
            W(-1);
            return;
        }
    }
    int st=min({SZ(d[1]),SZ(d[2]),k});
    int an=2.1e9;
    priority_queue<PII,VPII,greater<PII>>qq;
    priority_queue<PII>gg;
    FOR(id,1,2){
        REPP(j,st,SZ(d[id])){
            qq.push(d[id][j]);
        }
    }
    REPP(i,k,SZ(d[3])){
        qq.push(d[3][i]);
    }
    REP(i,SZ(d[0])){
        qq.push(d[0][i]);
    }
    int now=0,num=0;
    REP(i,st){
        now+=d[1][i].F+d[2][i].F;
        now_set[d[1][i].S]=1;
        now_set[d[2][i].S]=1;
        num+=2;
    }
    int it_3=0;
    REP(i,k-st){
        now+=d[3][i].F;
        now_set[d[3][i].S]=1;
        it_3=i+1;
        num++;
    }
    while(num<m){
        if(!qq.empty()){
            num++;
            gg.push(qq.top());
            now+=qq.top().F;
            now_set[qq.top().S]=1;
            qq.pop();
        }
        else break;
    }
    if(num==m){
        an=now;
        an_set=now_set;
    }
    while(st>0){
        st--;
        num-=2;
        now-=d[1][st].F+d[2][st].F;
        now_set[d[1][st].S]=now_set[d[2][st].S]=0;
        qq.push(d[1][st]);
        qq.push(d[2][st]);
        if(it_3>=SZ(d[3]))break;
        num++;
        now+=d[3][it_3++].F;
        now_set[d[3][it_3-1].S]=1;
        while(num<m){
            if(!qq.empty()){
                num++;
                gg.push(qq.top());
                now+=qq.top().F;
                now_set[qq.top().S]=1;
                qq.pop();
            }
            else break;
        }
        while(!qq.empty()&&!gg.empty()&&gg.top().F>qq.top().F){
            auto tmp1=qq.top();
            auto tmp2=gg.top();
            now+=tmp1.F-tmp2.F;
            now_set[tmp1.S]=1;
            now_set[tmp2.S]=0;
            qq.pop();
            gg.pop();
            qq.push(tmp2);
            gg.push(tmp1);
        }
        if(num==m){
            if(an>now){
                an=now;
                an_set=now_set;
            }
        }
    }
    W(an);
    VI res;
    FOR(i,1,n){
        if(an_set[i])res.PB(i);
    }
    W(res);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}