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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<17;
PII a[31][SIZE];
int n;
int get_bit(long long x, int v) { return (x >> v) & 1; }
int node[SIZE*31][2];
int nxt_node_id;
PII rg[SIZE*31];
void init(int id){
    node[id][0]=node[id][1]=-1;
}
void build(int node_id,int lv, int ll, int rr){
    rg[node_id]={ll,rr};
    //DEBUG(node_id,lv,ll,rr);
    if(lv==-1)return;
    int nxt_ll=ll,nxt_rr=ll;
    REPP(i,ll,rr){
        if(!get_bit(a[lv+1][i].S,lv))nxt_rr++;
    }
    REPP(i,ll,rr){
        if(get_bit(a[lv+1][i].S,lv))a[lv][nxt_rr++]=a[lv+1][i];
        else a[lv][nxt_ll++]=a[lv+1][i];
    }
    if(ll<nxt_ll){
        int l_node=nxt_node_id++;
        init(l_node);
        node[node_id][0]=l_node;
        build(l_node,lv-1,ll,nxt_ll);
    }
    if(nxt_ll<nxt_rr){
        int r_node=nxt_node_id++;
        init(r_node);
        node[node_id][1]=r_node;
        build(r_node,lv-1,nxt_ll,nxt_rr);
    }
}
int solve(int lv, int node_id, int l, int r, VI &bonus){
    if(lv<0)return 0;
    int zero_cnt=0;
    for(int x: bonus){
        if(!get_bit(x,lv))zero_cnt++;
    }
    int l_pos=-1,r_pos=-1;
    if(node_id != -1 && node[node_id][0]!=-1){
        int l_id=node[node_id][0];
        r_pos=lower_bound(a[lv]+rg[l_id].F,a[lv]+rg[l_id].S,MP(r+1,0))-a[lv];
        l_pos=lower_bound(a[lv]+rg[l_id].F,a[lv]+rg[l_id].S,MP(l,0))-a[lv];
        zero_cnt+=r_pos-l_pos;
    }
    if(zero_cnt>1){
        int it=0;
        REP(i,SZ(bonus)){
            if(!get_bit(bonus[i],lv))bonus[it++]=bonus[i];
        }
        bonus.resize(it);
        return solve(lv-1,node_id!=-1?node[node_id][0]:-1,l,r,bonus);
    }else{
        if(l_pos<r_pos){
            bonus.PB(a[lv][l_pos].S);
        }
        return solve(lv-1,node_id!=-1?node[node_id][1]:-1,l,r,bonus)|(1<<lv);
    }
}
void solve() {
    node[0][0]=node[0][1]=-1;
    nxt_node_id=1;
    build(0,29,0,n);
    int q;
    R(q);
    while(q--){
        int l,r;
        R(l,r);
        l--;r--;
        VI bonus;
        W(solve(29,0,l,r,bonus));
    }
}
void input() {
    R(n);
    REP(i,n){
        a[30][i].F=i;
        R(a[30][i].S);
    }
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}