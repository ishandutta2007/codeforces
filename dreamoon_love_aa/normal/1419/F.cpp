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

#define UnionFindSIZE 1234567
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE];
    vector<pair<int*,int>>bk;
    void comeback(){
        for(int i=SZ(bk)-1;i>=0;i--){
            *bk[i].F=bk[i].S;
        }
        bk.clear();
    }
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        while(x!=d[x])x=d[x];
        return x;
    }
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y,bool save=0){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y]){
            if(save){
                bk.PB(MP(&num[x],num[x]));
                bk.PB(MP(&num[y],num[y]));
            }
            swap(x,y);
        }
        if(save){
            bk.PB(MP(&num[y],num[y]));
            bk.PB(MP(&d[x],d[x]));
        }
        num[y]+=num[x];
        d[x]=y;
        return 1;
    }
}U;
int x[4096],y[4096];
VI xx,yy;
int id[2048][2048],dir[2048][2048][4];
const int RIGHT = 0;
const int LEFT = 2;
const int UP = 1;
const int DOWN = 3;
int dis(int u,int v){
    DEBUG(u,v);
    return abs(xx[x[u]]-xx[x[v]])+abs(yy[y[u]]-yy[y[v]]);
}
struct EDGE{
    int x,y,v;
    EDGE(int x=0,int y=0,int v=0):x(x),y(y),v(v){}
    void get_dis(){
        v=dis(x,y);
    }
    bool operator<(const EDGE& b)const{
        return v<b.v;
    }
}e[8192];
int n;
void solve() {
    MS1(id);
    REP(i,n){
        xx.PB(x[i]);
        yy.PB(y[i]);
    }
    SORT_UNIQUE(xx);
    {
        int xn=SZ(xx);
        REPP(i,1,xn){
            if(xx[i]!=xx[i-1]+1){
                xx.PB((xx[i]+xx[i-1])/2);
            }
        }
        SORT_UNIQUE(xx);
    }
    SORT_UNIQUE(yy);
    {
        int yn=SZ(yy);
        REPP(i,1,yn){
            if(yy[i]!=yy[i-1]+1){
                yy.PB((yy[i]+yy[i-1])/2);
            }
        }
        SORT_UNIQUE(yy);
    }
    REP(i,n){
        x[i]=GET_POS(xx,x[i]);
        y[i]=GET_POS(yy,y[i]);
        id[x[i]][y[i]]=i;
        //DEBUG("xy",x[i],y[i]);
    }
    REP(i,2048){
        int lt=-1;
        REP(j,2048){
            dir[i][j][LEFT]=lt;
            if(id[i][j]!=-1)lt=id[i][j];
        }
        lt=-1;
        for(int j=2047;j>=0;j--){
            dir[i][j][RIGHT]=lt;
            if(id[i][j]!=-1)lt=id[i][j];
        }
    }
    REP(j,2048){
        int lt=-1;
        REP(i,2048){
            dir[i][j][UP]=lt;
            if(id[i][j]!=-1)lt=id[i][j];
        }
        lt=-1;
        for(int i=2047;i>=0;i--){
            dir[i][j][DOWN]=lt;
            if(id[i][j]!=-1)lt=id[i][j];
        }
    }
    int en=0;
    REP(i,2048)REP(j,2048){
        if(id[i][j]==-1)continue;
        REP(k,2){
            if(dir[i][j][k]==-1)continue;
            e[en].x=id[i][j];
            e[en].y=dir[i][j][k];
            e[en].get_dis();
            //DEBUG(id[i][j],dir[i][j][k],e[en].v);
            en++;
        }
    }
    sort(e,e+en);
    int it=0;
    U.init(n+1);
    int gg=n;
    int ma=0;
    while(it<en&&gg>4){
        if(U.uu(e[it].x,e[it].y)){
            ma=e[it].v;
            gg--;
        }
        it++;
    }
    vector<EDGE>AA;
    int saved_gg=gg;
    while(it<en&&gg>1){
        if(U.uu(e[it].x,e[it].y,1)){
            AA.PB(e[it]);
            gg--;
        }
        it++;
    }
    U.comeback();
    //for(auto x:AA)DEBUG(x.v,x.x,x.y);
    EDGE tmp[8];
    int an=MOD*2;
    REP(i,SZ(xx))REP(j,SZ(yy)){
        if(id[i][j]!=-1)continue;
        int tn=0;
        x[n]=i;
        y[n]=j;
        REP(k,4){
            if(dir[i][j][k]==-1)continue;
            EDGE me(n,dir[i][j][k]);
            me.get_dis();
            tmp[tn++]=me;
        }
        for(auto me:AA)tmp[tn++]=me;
        sort(tmp,tmp+tn);
        int tmp_ma=0;
        int tmp_gg=saved_gg+1;
        REP(k,tn){
            if(U.uu(tmp[k].x,tmp[k].y,1)){
                tmp_gg--;
                tmp_ma=tmp[k].v;
                
            }
        }
        if(tmp_gg==1){
            an=min(an,max(tmp_ma,ma));
        }
        U.comeback();
    }
    {
        int tn=0;
        for(auto me:AA)tmp[tn++]=me;
        sort(tmp,tmp+tn);
        int tmp_ma=0;
        int tmp_gg=saved_gg;
        REP(k,tn){
            if(U.uu(tmp[k].x,tmp[k].y,1)){
                tmp_gg--;
                tmp_ma=tmp[k].v;
                
            }
        }
        if(tmp_gg==1){
            an=min(an,max(tmp_ma,ma));
        }
    }
    if(an==MOD*2)W(-1);
    else W(an);
}
void input() {
    R(n);    
    REP(i,n)R(x[i],y[i]);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET
#endif
    {
        input();
        solve();
    }
    return 0;
}