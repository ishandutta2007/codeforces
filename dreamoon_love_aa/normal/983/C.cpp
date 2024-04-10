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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2010;
bool dp[9][SIZE][715];
int cnt[SIZE];
int a[SIZE],b[SIZE];
int five[10];
VI hh;
void dfs(int x,int now,int r){
    if(x==9||r==0){
        hh.PB(now);
        return;
    }
    FOR(i,0,r){
        dfs(x+1,now+five[x]*i,r-i);
    }
}
void build(){
    five[0]=1;
    REPP(i,1,10)five[i]=five[i-1]*5;
    dfs(0,0,4);
    SORT_UNIQUE(hh);
    REP(i,SZ(hh)){
        int me=hh[i];
        while(me){
            cnt[i]+=me%5;
            me/=5;
        }
    }
}
int get_id(int x){
    int id=GET_POS(hh,x);
    if(id<SZ(hh)&&hh[id]==x)return id;
    return -1;
}
struct DATA{
    int x,id,state,v;
    DATA(){}
    DATA(int x,int id,int state,int v):x(x),id(id),state(state),v(v){}
};
int get_num(int x,int v){
    return x/five[v]%5;
}
bool update(int &x,int v){
    if(x==-1||x>v){
        x=v;
        return 1;
    }
    return 0;
}
int main(){
    build();
    int n; R(n);
    FOR(i,1,n){
        R(a[i],b[i]);
        a[i]--;
        b[i]--;
    }
    deque<DATA>qq;
    int st_n=0,st_state=0;
    while(st_n+1<=n&&st_n+1<=4&&a[st_n+1]==0){
        st_n++;
        st_state+=five[b[st_n]];
    }
    dp[0][st_n][get_id(st_state)]=1;
    qq.push_back(DATA(0,st_n,st_state,0));
    while(SZ(qq)){
        DATA now=qq.front();
        qq.pop_front();
        if(now.id==n&&now.state==0){
            W(now.v+n*2);
            return 0;
        }
        if(now.x<=7){//+1
            auto nxt=now;
            nxt.v++;
            nxt.x++;
            int v=get_num(nxt.state,nxt.x);
            nxt.state-=v*five[nxt.x];
            while(nxt.id+1<=n&&a[nxt.id+1]==nxt.x&&cnt[get_id(nxt.state)]<4){
                nxt.id++;
                nxt.state+=five[b[nxt.id]];
            }
            if(!dp[nxt.x][nxt.id][get_id(nxt.state)]){
                dp[nxt.x][nxt.id][get_id(nxt.state)]=1;
                qq.push_back(nxt);
            }
        }
        if(now.x>0){//-1
            auto nxt=now;
            nxt.v++;
            nxt.x--;
            int v=get_num(nxt.state,nxt.x);
            nxt.state-=v*five[nxt.x];
            while(nxt.id+1<=n&&a[nxt.id+1]==nxt.x&&cnt[get_id(nxt.state)]<4){
                nxt.id++;
                nxt.state+=five[b[nxt.id]];
            }
            if(!dp[nxt.x][nxt.id][get_id(nxt.state)]){
                dp[nxt.x][nxt.id][get_id(nxt.state)]=1;
                qq.push_back(nxt);
            }
        }
    }
    return 0;
}