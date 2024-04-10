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
const int SIZE = 600;
int n,m;
int w[SIZE][SIZE];
int a[SIZE][SIZE];
int b[SIZE][SIZE];
int from[SIZE][SIZE];
PII my_heap[SIZE*SIZE+SIZE];
bitset<SIZE>u[SIZE];
int hn;
void init_heap(){
    REP(i,n){
        REP(j,i){
            my_heap[++hn]=MP(j,i);
            from[j][i]=hn;
        }
    }
}
bool update(int &x, int v){
    if(x<v){
        x=v;
        return 1;
    }
    return 0;
}
int del(int id){
    while(1){
        int ma=0,ma_id=-1;
        if(id*2<=hn){
            if(update(ma,a[my_heap[id*2].F][my_heap[id*2].S])){
                ma_id=id*2;
            }
        }
        if(id*2+1<=hn){
            if(update(ma,a[my_heap[id*2+1].F][my_heap[id*2+1].S])){
                ma_id=id*2+1;
            }
        }
        if(ma_id==-1){
            return id;
        }
        my_heap[id]=my_heap[ma_id];
        from[my_heap[id].F][my_heap[id].S]=id;
        id=ma_id;
    }
}
void push(int id){
    while(id!=1&&a[my_heap[id].F][my_heap[id].S]>a[my_heap[id>>1].F][my_heap[id>>1].S]){
        swap(my_heap[id],my_heap[id>>1]);
        from[my_heap[id].F][my_heap[id].S]=id;
        id>>=1;
        from[my_heap[id].F][my_heap[id].S]=id;
    }
}
void change_heap(int x, int y){
    if(x>y){
        swap(x,y);
    }
    int my_id=from[x][y];
    int pos=del(my_id);
    my_heap[pos]=MP(x,y);
    from[x][y]=pos;
    push(pos);
}
void solve() {
    while(a[my_heap[1].F][my_heap[1].S]){
        int x=my_heap[1].F;
        int y=my_heap[1].S;
        int v=a[my_heap[1].F][my_heap[1].S];
        b[x][y]=v;
        a[x][y]=0;
        change_heap(x,y);
        u[x][y]=1;
        REP(i,n){
            int nx=i;
            int ny=y;
            int nv=v-w[x][i];
            if(nx>ny){
                swap(nx,ny);
            }
            if(nx!=ny&&!u[nx][ny]&&nv>a[nx][ny]){
                a[nx][ny]=nv;
                change_heap(nx,ny);
            }
            nx=x;
            ny=i;
            nv=v-w[y][i];
            if(nx>ny){
                swap(nx,ny);
            }
            if(nx!=ny&&!u[nx][ny]&&nv>a[nx][ny]){
                a[nx][ny]=nv;
                change_heap(nx,ny);
            }
        }
    }
    int an=0;
    REP(i,n)REPP(j,i+1,n){
        if(w[j][j]&&w[i][j]<=b[i][j]){
            an++;
        }
    }
    W(an);
}
void input() {
    R(n,m);
    REP(i,n)REP(j,n)w[i][j]=MOD;
    init_heap();
    REP(i,m){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        w[x][y]=w[y][x]=v;
    }
    int q;
    R(q);
    REP(i,q){
        int x,y,v;
        R(x,y,v);
        x--;y--;
        a[x][y]=a[y][x]=v;
        change_heap(x,y);
    }
}
int main(){
    input();
    solve();
    return 0;
}