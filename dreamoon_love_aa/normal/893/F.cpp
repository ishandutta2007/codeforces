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
const int SIZE = 1e5+10;
int n;
VI e[SIZE];
int a[SIZE],l_id[SIZE],r_id[SIZE],h[SIZE],node_id,pos[SIZE];
bool u[SIZE];
void dfs(int x){
    u[x]=1;
    pos[node_id]=x;
    l_id[x]=r_id[x]=node_id++;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(u[y])continue;
        h[y]=h[x]+1;
        dfs(y);
        r_id[x]=r_id[y];
    }
}
struct node{
	int ch[2],ma;
    node():ma(1000000000){ch[0]=ch[1]=-1;}
}tree[SIZE*80];
int gen[SIZE],top;
auto maa = [](auto& x,auto y){if(x>y)x=y;};
void ins(int p,int l,int r,int v){
	maa(tree[p].ma,a[v]);
	if (l==r) return;
	int m=(l+r)>>1;
	if (h[v]<=m){
        if(tree[p].ch[0]==-1)tree[p].ch[0]=top++;
        ins(tree[p].ch[0],l,m,v);
    }
	else{
        if(tree[p].ch[1]==-1)tree[p].ch[1]=top++;
        ins(tree[p].ch[1],m+1,r,v);
    }
}
void build2(int l,int r,int id,int x){
    ins(id,0,n-1,pos[x]);
    if(l==r)return;
    int m=(l+r)/2;
    if(x<=m)build2(l,m,id*2,x);
    else build2(m+1,r,id*2+1,x);
}
void build(){
    top=SIZE*4;
    REP(i,n){
        build2(0,n-1,1,i);
    }
}
int lol,ror,ll,rr,ans;
void query(int x,int l,int r){
    if(x==-1)return;
    if(l>=lol&&r<=ror){
        maa(ans,tree[x].ma);
        return;
    }
	int m=(l+r)>>1;
    if(m>=lol)query(tree[x].ch[0],l,m);
	if(m+1<=ror)query(tree[x].ch[1],m+1,r);
}
void qq1(int l,int r,int id){
    if(l>rr||r<ll)return;
    if(l>=ll&&r<=rr){
        query(id,0,n-1);
        return;
    }
    int m=(l+r)/2;
    qq1(l,m,id*2);
    qq1(m+1,r,id*2+1);
}
int main(){
    int r;
    R(n,r);
    r--;
    REP(i,n)R(a[i]);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(r);
    build();
    CASET{
        int x,y;
        R(x,y);
        x=(x+ans)%n;
        y=(y+ans)%n;
        lol=h[x];
        ror=min(n-1,lol+y);
        ll=l_id[x];
        rr=r_id[x];
        DEBUG(lol,ror,ll,rr);
        ans=1e9;
        qq1(0,n-1,1);
        W(ans);
    }
    return 0;
}