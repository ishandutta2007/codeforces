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
const int SIZE = 600000;
const int MM = 300000;
vector<pair<LL*,LL>>rr;
LL VAL;
struct Union_Find{
    LL d[SIZE];
    LL num[SIZE],l_num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,l_num[i]=(i<MM);
    }
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        while(x!=d[x])x=d[x];
        while(y!=d[y])y=d[y];
        if(x==y)return 0;
        VAL-=(num[x]-l_num[x])*l_num[x]+(num[y]-l_num[y])*l_num[y];
        if(num[x]>num[y])swap(x,y);
        rr.PB({&num[y],num[y]});
        num[y]+=num[x];
        rr.PB({&d[x],d[x]});
        d[x]=y;
        rr.PB({&l_num[y],l_num[y]});
        l_num[y]+=l_num[x];
        VAL+=(num[y]-l_num[y])*l_num[y];
        return 1;
    }
    void recover(int id){
        for(int i=rr.size()-1;i>=id;i--){
            *rr[i].F=rr[i].S;
        }
        rr.resize(id);
    }
}U;
VPII seg[1<<21];
PII obj;
void ins(int L,int R,int id,int x,int y){
    if(L>=x&&R<=y){
        seg[id].PB(obj);
        return;
    }
    int mm=(L+R)/2;
    if(mm>=x)ins(L,mm,id*2,x,y);
    if(mm+1<=y)ins(mm+1,R,id*2+1,x,y);
}
VL res;
void dfs(int L,int R,int id){
    int ed=rr.size();
    LL pre_val=VAL;
    for(auto x:seg[id]){
        U.uu(x.F,x.S);
    }
    if(L!=R){
        int mm=(L+R)/2;
        dfs(L,mm,id*2);
        dfs(mm+1,R,id*2+1);
    }
    else{
        res.PB(VAL);
    }
    VAL=pre_val;
    U.recover(ed);
}
int main(){
    U.init(SIZE);
    map<PII,int>AA;
    int n; R(n);
    REP(i,n){
        int v1,v2; R(v1,v2);
        v1--;v2--;
        v2+=MM;
        auto it=AA.find({v1,v2});
        if(it==AA.end()){
            AA[{v1,v2}]=i;
        }
        else{
            obj={v1,v2};
            ins(0,n-1,1,it->S,i-1);
            AA.erase(it);
        }
    }
    for(auto pp:AA){
        obj=pp.F;
        ins(0,n-1,1,pp.S,n-1);
    }
    dfs(0,n-1,1);
    W(res);
    return 0;
}