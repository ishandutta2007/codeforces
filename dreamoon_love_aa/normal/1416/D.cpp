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
int A[SIZE];
int _v[SIZE],pos[SIZE];
VPII AA;
int n;
struct Seg{
    int N;
    int ma[SIZE];
    void build(int L,int R,int id){
        if(L==R){
            ma[id]=_v[L];
            return;
        }
        int mm=(L+R)/2;
        build(L,mm,id*2);
        build(mm+1,R,id*2+1);
        ma[id]=max(ma[id*2],ma[id*2+1]);
    }
    void init(int _N){
        N=_N;
        build(1,N,1);
    }
    void ins(int L,int R,int id,int x,int v){
        int mm=(L+R)/2;
        if(L==R){
            ma[id]=v;
            return;
        }
        if(x<=mm)ins(L,mm,id*2,x,v);
        else ins(mm+1,R,id*2+1,x,v);
        ma[id]=max(ma[id*2],ma[id*2+1]);
    }
    int qq(int L,int R,int id,int ll,int rr){
        if(L>rr||R<ll)return INT_MIN;
        if(L>=ll&&R<=rr)return ma[id];
        int mm=(L+R)/2;
        return max(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
    }
}seg;

int p[SIZE];
int node_id;
VI e[SIZE];
int tree_l[SIZE],tree_r[SIZE],_id;
#define UnionFindSIZE 1234567
struct Union_Find{
    int d[UnionFindSIZE],num[UnionFindSIZE];
    int rt[UnionFindSIZE];
    void init(int _n){
        REP(i,_n)d[i]=i,num[i]=1,rt[i]=i;
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) y = d[y];
        while(x != y){
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x){return d[x]==x;}
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]>num[y])swap(x,y);
        num[y]+=num[x];
        d[x]=y;
        e[node_id].PB(rt[x]);
        e[node_id].PB(rt[y]);
        rt[y]=node_id;
        node_id++;
        return 1;
    }
}U;
int a[SIZE],b[SIZE];
int op[SIZE],op_id[SIZE],rt_id[SIZE];
bool edge_in_tree[SIZE];
void merge(int x,int y){
    U.uu(x,y);
}
void dfs(int x){
    tree_l[x]=tree_r[x]=++_id;
    if(x<n){
        _v[_id]=p[x];
        pos[p[x]]=_id;
    }
    for(int y:e[x]){
        dfs(y);
        tree_r[x]=tree_r[y];
    }
}
void solve() {
    int m,q;
    R(n,m,q);
    REP(i,n)R(p[i]);
    REP(i,m){
        edge_in_tree[i]=1;
        R(a[i],b[i]);
        a[i]--;
        b[i]--;
    }
    REP(i,q){
        R(op[i],op_id[i]);
        op_id[i]--;
        if(op[i]==2){
            edge_in_tree[op_id[i]]=0;
        }
    }
    node_id=n;
    U.init(2*n);
    REP(i,m){
        if(edge_in_tree[i]){
            merge(a[i],b[i]);
        }
    }
    for(int i=q-1;i>=0;i--){
        if(op[i]==2){
            int e_id=op_id[i];
            U.uu(a[e_id],b[e_id]);
        }else{
            rt_id[i]=U.rt[U.find(op_id[i])];
        }
    }
    REP(i,n){
        if(U.is_root(i)){
            dfs(U.rt[i]);
        }
    }
    seg.init(_id);
    REP(i,q){
        if(op[i]==1){
            int v=seg.qq(1,_id,1,tree_l[rt_id[i]],tree_r[rt_id[i]]);
            W(v);
            if(v){
                seg.ins(1,_id,1,pos[v],0);
            }
        }
    }
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET
#endif
    {
        solve();
    }
    return 0;
}