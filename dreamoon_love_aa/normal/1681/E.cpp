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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<18;
int n;
#define int long long
const LL INF = 1e10;
int mat[SIZE][4][4];
struct node{
    int a[4][4];
    void clear(){
        MS1(a);
    }
}tree[SIZE];
PII sp[SIZE][4];
int dis[8][8];
void calc(){
    REP(k,8){
        REP(i,8)REP(j,8){
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
}
int dd(PII x, PII y){
    return abs(x.F-y.F)+abs(x.S-y.S);
}
inline void merge(node &C, node A, node B) { // [A][B]  [C]
    if(A.a[0][0]==-1){
        memcpy(C.a,B.a,sizeof(B.a));
        return;
    }
    REP(i,4)REP(j,4){
        C.a[i][j]=A.a[i][0]+B.a[0][j];
        REPP(k,1,4){
            C.a[i][j]=min(C.a[i][j],A.a[i][k]+B.a[k][j]);
        }
    }
}
void build(int L,int R, int p) {
    if(L == R) {
        memcpy(tree[p].a,mat[L],sizeof(mat[L]));
        return;
    }
    int mid = (L + R) / 2;
    build(L, mid, p * 2);
    build(mid + 1, R, p * 2 + 1);
    merge(tree[p], tree[p * 2], tree[p * 2 + 1]);
}
node res;
void query(int L,int R, int p, int l, int r) {
    if(R < l || L > r) return;
    if(L >= l && R <= r) {
        merge(res, res, tree[p]);
        return;
    }
    int mid = (L + R) / 2;
    query(L, mid, p * 2, l, r);
    query(mid + 1, R, p * 2 + 1, l, r);
}
void solve() {
    build(1,n-1,1);
    int m;
    R(m);
    while(m--){
        PII x,y;
        R(x,y);
        int lv1=max(x.F,x.S);
        int lv2=max(y.F,y.S);
        if(lv1==lv2){
            W(dd(x,y));
            continue;
        }
        if(lv1>lv2){
            swap(x,y);
            swap(lv1,lv2);
        }
        res.clear();
        query(1,n-1,1,lv1,lv2-1);
        int an=INF;
        REP(i,4)REP(j,4){
            an=min(an,dd(x,sp[lv1][i])+dd(y,sp[lv2][j])+res.a[i][j]);
        }
        W(an);
    }
}
void input() {
    R(n);
    FOR(i,1,n-1){
        REP(j,2){
            R(sp[i][j]);
        }
        sp[i+1][2]=sp[i][0];
        sp[i+1][2].F++;
        sp[i+1][3]=sp[i][1];
        sp[i+1][3].S++;
    }
    sp[1][2]=sp[1][3]={1,1};
    sp[n][0]=sp[n][1]={n,1};
    FOR(i,1,n-1){
        REP(j,8)REP(k,8)dis[j][k]=INF;
        REP(j,4)REP(k,4)dis[j][k]=dd(sp[i][j],sp[i][k]);
        REP(j,4)REP(k,4)dis[j+4][k+4]=dd(sp[i+1][j],sp[i+1][k]);
        dis[0][6]=dis[1][7]=1;
        calc();
        REP(j,4)REP(k,4)mat[i][j][k]=dis[j][k+4];
    }
}
signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}