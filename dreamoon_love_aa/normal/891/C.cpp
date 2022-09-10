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
const int SIZE = 1.5e6+10;
int new_id[SIZE],sc[SIZE],ID,LAST_ID;
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
vector<pair<int*,int>>undo_list;
struct Union_Find2{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?find(d[x]):x;}
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        undo_list.PB(MP(&num[y],num[y]));
        num[y]+=num[x];
        undo_list.PB(MP(&d[x],d[x]));
        d[x]=y;
        return 1;
    }
}U2;
void undo(){
    for(int i=SZ(undo_list)-1;i>=0;i--){
        *(undo_list[i].F)=undo_list[i].S;
    }
    undo_list.clear();
}
struct EDGE{
    int x,y,v,id;
    EDGE(int x=0,int y=0,int v=0,int id=0):x(x),y(y),v(v),id(id){}
    bool operator<(const EDGE& b)const{
        return v<b.v;
    }
}e[SIZE];
int main(){
    int n,m;
    R(n,m);
    U.init(n);
    REP(i,m){
        R(e[i].x,e[i].y,e[i].v);
        e[i].id=i;
        e[i].x--;
        e[i].y--;
    }
    sort(e,e+m);
    ID=n;
    for(int i=0,j;i<m;i=j){
        LAST_ID=ID;
        for(j=i;j<m&&e[j].v==e[i].v;j++){
            sc[e[j].id]=j;
            e[j].x=U.find(e[j].x);
            e[j].y=U.find(e[j].y);
            if(e[j].x==e[j].y)e[j].x=e[j].y=-1;
        }
        for(j=i;j<m&&e[j].v==e[i].v;j++){
            if(e[j].x==-1)continue;
            U.uu(e[j].x,e[j].y);
        }
    }
    REP(i,m)DEBUG(e[i].id,e[i].x,e[i].y);
    int Q;
    R(Q);
    U2.init(n);
    REP(cs,Q){
        int K;
        R(K);
        bool fail=0;
        VI es;
        REP(i,K){
            int eid;
            R(eid);
            eid=sc[eid-1];
            if(e[eid].x==-1)fail=1;
            es.PB(eid);
        }
        if(!fail){
            REP(i,SZ(es)){
                if(!U2.uu(e[es[i]].x,e[es[i]].y)){
                    fail=1;
                    break;
                }
            }
        }
        undo();
        puts(fail?"NO":"YES");
    }
    return 0;
}