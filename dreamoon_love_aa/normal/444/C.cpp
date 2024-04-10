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
LL ma[SIZE],_tmp[SIZE],num[SIZE];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]+=_tmp[id];
    ma[id*2]+=num[id*2]*_tmp[id];
    _tmp[id*2+1]+=_tmp[id];
    ma[id*2+1]+=num[id*2+1]*_tmp[id];
    _tmp[id]=0;
}
void pull(int id){
    ma[id]=ma[id*2]+ma[id*2+1];
}
void seg_init(int L,int R,int id){
    if(L==R){
        num[id]=1;
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    num[id]=num[id*2]+num[id*2+1];
    pull(id);
}
LL qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return 0;
    if(L>=ll&&R<=rr)return ma[id];
    int mm=(L+R)/2;
    push(id);
    return qq(L,mm,id*2,ll,rr)+qq(mm+1,R,id*2+1,ll,rr);
}
void ins(int L,int R,int id,int ll,int rr,LL v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        ma[id]+=v*num[id];
        _tmp[id]+=v;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
PII cross(PII x,PII y){
    int v1=max(x.F,y.F);
    int v2=min(x.S,y.S);
    return MP(v1,v2);
}
void solve() {
    int n,m;
    R(n,m);
    seg_init(1,n,1);
    set<pair<PII,int>>AA;
    FOR(i,1,n)AA.insert(MP(MP(i,i),i));
    REP(i,m){
        int ty;
        R(ty);
        if(ty==1){
            int l,r,v;
            R(l,r,v);
            auto it=AA.lower_bound(MP(MP(l,0),0));
            auto st=it;
            vector<pair<PII,int>> added;
            if(it->F.S<l)added.PB(MP(MP(l-1,it->F.S),it->S));
            added.PB(MP(MP(r,l),v));
            for(;it!=AA.end();it++){
                PII cc=cross(MP(l,r),MP(it->F.S,it->F.F));
                if(cc.F>cc.S)break;
                if(it->F.F>r){
                    added.PB(MP(MP(it->F.F,r+1),it->S));
                }
                ins(1,n,1,cc.F,cc.S,abs(it->S-v));
            }
            AA.erase(st,it);
            AA.insert(ALL(added));
        }
        else{
            int l,r;
            R(l,r);
            W(qq(1,n,1,l,r));
        }
    }
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