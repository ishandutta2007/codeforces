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
int h;
#include<ctime>
int my_rand(int lb, int ub) {
    LL x=((LL)rand()<<14)^rand();
    return lb+x%(ub-lb+1);
}
int qq(int u,int v,int w){
    W("?",u,v,w);
    fflush(stdout);
    int ret;
    R(ret);
    return ret;
}
void solve() {
    VI AA((1<<h)-3);
    while(1) {
        int x=my_rand(1,(1<<h)-1);
        int y=my_rand(1,(1<<h)-1);
        if(x==y)continue;
        {
            int it=0;
            FOR(i,1,(1<<h)-1){
                if(i==x||i==y)continue;
                AA[it++]=i;
            }
            REPP(i,1,SZ(AA)){
                int id=my_rand(0,i);
                if(id!=i){
                    swap(AA[i],AA[id]);
                }
            }
        }
        map<int,int>dm;
        int x_cnt=0;
        int y_cnt=0;
        bool err=0;
        REP(i,SZ(AA)){
            if(i==30){
                for(auto &tmp:dm){
                    if(tmp.S>12){
                        err=1;
                        break;
                    }
                }
                if(err)break;
            }
            if(i==60){
                for(auto &tmp:dm){
                    if(tmp.S>26){
                        err=1;
                        break;
                    }
                }
                if(err)break;
            }
            int ret=qq(x,y,AA[i]);
            if(ret==x){
                x_cnt++;
            }else if(ret==y){
                y_cnt++;
            }else{
                dm[ret]++;
            }
        }
        if(err)continue;
        if(x_cnt==(1<<(h-1))-1){
            W("!",x);
            return;
        }
        if(y_cnt==(1<<(h-1))-1){
            W("!",y);
            return;
        }
        for(auto &tmp:dm){
            if(tmp.S==1){
                W("!",tmp.F);
                return;
            }
        }
    }
}
void input() {
    srand(time(NULL));
    R(h);
}
int main(){
    input();
    solve();
    return 0;
}