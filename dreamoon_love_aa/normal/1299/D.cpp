#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
namespace io {
    const int SIZE = 1e7 + 10;
    char inbuff[SIZE];
    char *l, *r;
    inline void init() {
        l = inbuff;
        r = inbuff + fread(inbuff, 1, SIZE, stdin);
    }
    inline char gc() {
        if (l == r) init();
        return (l != r) ? *(l++) : EOF;
    }
    void read(int &x) {
        x = 0; char ch = gc();
        while(!isdigit(ch)) ch = gc();
        while(isdigit(ch)) x = x * 10 + ch - '0', ch = gc();
    }
} using io::read;
const int SIZE = 1e6+10;
VPII e[SIZE];
map<PII,int>AA;
int rt[SIZE];
int pp[SIZE];
int w[SIZE];
int u[SIZE],ut;
int val[SIZE];
bool in[SIZE];
int ban;
int tmp[SIZE],tn;
map<VI,int>id;
void dfs(int x,int lt,int v){
    u[x]=ut;
    in[x]=1;
    val[x]=v;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        if(u[y]==ut){
            if(in[y]){
                tmp[tn++]=v^val[y]^e[x][i].S;
            }
        }
        else{
            dfs(y,x,v^e[x][i].S);
        }
    }
    in[x]=0;
    return;
}
int get_bit(int x,int v){return (x>>v)&1;}
VI err{-1};
void fix(VI &x){
    if(SZ(x)==0)return;
    if(SZ(x)&&x.back()==0){
        x=err;
        return;
    }
    int now=0;
    for(int i=4;i>=0;i--){
        if(get_bit(x[now],i)){
            REP(j,SZ(x)){
                if(j==now)continue;
                if(get_bit(x[j],i))x[j]^=x[now];
            }
            now++;
            if(now==SZ(x))break;
            sort(x.begin()+now,x.end(),greater<int>());
        }
    }
    if(x.back()==0){
        x=err;
    }
}
VI get(int x,int added=-1){
    tn=0;
    if(added!=-1){
        tmp[tn++]=added;
    }
    ut++;
    dfs(x,1,0);
    if(tn>5)return err;
    sort(tmp,tmp+tn,greater<int>());
    REPP(i,1,tn){
        if(tmp[i]==tmp[i-1])return err;
    }
    VI ret=VI(tmp,tmp+tn);
    fix(ret);
    return ret;
}
LL dp[2][1000];
VI merge(VI x, VI y){
    if(SZ(x)+SZ(y)>5)return err;
    x.resize(SZ(x)+SZ(y));
    REP(i,SZ(y))x[SZ(x)-1-i]=y[i];
    sort(ALL(x),greater<int>());
    fix(x);
    return x;
}
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int _id;
int trans[1000][1000];
VI dm[1000];
int add_vi(const VI& x){
    if(id.count(x))return id[x];
    dm[_id]=x;
    int me=id[x]=_id++;
    trans[me][me]=add_vi(merge(x,x));
    REP(i,me)trans[i][me]=trans[me][i]=add_vi(merge(x,dm[i]));
    return me;
}
int main(){
    id[err]=-1;
    int n,m;
    read(n);
    read(m);
    REP(i,m){
        int x,y,v;
        read(x);
        read(y);
        read(v);
        if(x>y)swap(x,y);
        if(x==1){
            rt[y]=1;
            w[y]=v;
        }
        else{
            e[x].PB({y,v});
            e[y].PB({x,v});
        }
        AA[MP(x,y)]=v;
    }
    FOR(x,2,n){
        if(!rt[x])continue;
        for(auto t:e[x]){
            if(rt[t.F]){
                pp[x]=t.F;
                pp[t.F]=x;
            }
        }
    }
    int now=0,nxt=1;
    dp[now][add_vi(VI())]=1;
    VI gg;
    VPII gg2;
    FOR(i,2,n){
        if(rt[i]){
            if(!pp[i]){
                VI ret=get(i);
                if(ret!=err){
                    gg.PB(add_vi(ret));
                }
            }
        }
    }
    FOR(i,2,n){
        if(rt[i]){
            if(pp[i]&&pp[i]>i){
                VI ret=get(i);
                if(ret!=err){
                    VI ret2=merge(ret,VI(1,w[i]^w[pp[i]]^AA[MP(i,pp[i])]));
                    gg2.PB(MP(add_vi(ret),add_vi(ret2)));
                }
            }
        }
    }
    for(auto y:gg){
        if(dm[y]==VI()){
            REP(i,_id)ADD(dp[now][i],dp[now][i]);
            continue;
        }
        memcpy(dp[nxt],dp[now],sizeof(LL)*_id);
        REP(i,_id){
            ADD(dp[nxt][trans[i][y]],dp[now][i]);
        }
        swap(now,nxt);
    }
    for(auto y:gg2){
        memcpy(dp[nxt],dp[now],sizeof(LL)*_id);
        REP(i,_id){
            if(trans[i][y.F]!=-1){
                ADD(dp[nxt][trans[i][y.F]],dp[now][i]*2);
            }
        }
        REP(i,_id){
            if(y.S!=-1&&trans[i][y.S]!=-1){
                ADD(dp[nxt][trans[i][y.S]],dp[now][i]);
            }
        }
        swap(now,nxt);
    }
    LL an=0;
    REP(i,_id)ADD(an,dp[now][i]);
    W(an);
    return 0;
}