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
const int SIZE = 1<<17;
#define FN 500010
#define FM 2000010
#define INF 1000000000000000LL
struct E {
    int k;
    LL c;
    E(){}
    E( int _k, LL _c ):k(_k),c(_c){}
} es[FM];

struct Flow {
    int n,m,dis[FN];
    int qq[FN],qr,ql;
    int ptr[FN];
    vector<int> e[FN];
    void init( int _n ) {
        n=_n; m=0;
        for ( int i=0; i<n; i++ ) {
            vector<int>tmp;
            e[i].swap(tmp);
        }
    }
    void add_edge( int a, int b, LL c ) {
        e[a].push_back(m); es[m]=E(b,c); m++;
        e[b].push_back(m); es[m]=E(a,0); m++;
    }
    bool BFS() {
        memset(dis,-1,n*sizeof(int));
        ql=qr=0;
        qq[qr++]=0;
        dis[0]=0;
        while ( ql!=qr && dis[n-1]==-1 ) {
            int p=qq[ql++];
            for(auto& it:e[p]) {
                E ee=es[it];
                if ( ee.c==0 || dis[ee.k]!=-1 ) continue;
                dis[ee.k]=dis[p]+1;
                qq[qr++]=ee.k;
            }
        }
        return dis[n-1]!=-1;
    }
    LL go( int p, LL c ) {
        if ( p==n-1 ) return c;
        LL ret=0,tmp;
        for(int &i=ptr[p];i<SZ(e[p]);i++){
            auto it=e[p][i];
            E &ee=es[it];
            if ( ee.c==0 || dis[p]+1!=dis[ee.k] ) continue;
            tmp=go(ee.k,min(c-ret,(LL)ee.c));
            ret+=tmp; ee.c-=tmp; es[it^1].c+=tmp;
            if ( ret==c ) break;
        }
        if ( ret==0 ) dis[p]=-1;
        return ret;
    }
    LL maxflow() {
        LL ret=0;
        while ( BFS() ) {
            memset(ptr,0,n*sizeof(int));
            ret+=go(0,1LL<<60);
        }
        return ret;
    }
} flow;
VI a[SIZE],an[SIZE];
string dir[SIZE];
char s[SIZE];
int n,m;
bool out(int x,int y){
    return x<0||y<0||x>=n||y>=m;
}
int get(int x, int y){
    return x*m+y+1;
}
VI same_dir[SIZE];
string dir_c="DRUL";
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int safe_dir[SIZE];
void my_clear(){
    REP(i,n*m){
        same_dir[i].clear();
    }
    REP(i,n){
        {
            string tmp_s;
            dir[i].swap(tmp_s);
        }
        {
            VI tmp;
            a[i].swap(tmp);
        }
        {
            VI tmp;
            an[i].swap(tmp);
        }
    }
}
void solve() {
    flow.init(n*m+4);
    int cnt[2]={};
    REP(i,n)REP(j,m){
        cnt[(i+j)&1]++;
        if((i+j)&1){
            flow.add_edge(0,get(i,j),1);
        } else {
            flow.add_edge(get(i,j),n*m+3,1);
        }
        REP(k,4){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(out(nx,ny)){
                continue;
            }
            if(a[nx][ny]<a[i][j]){
                safe_dir[get(i,j)]=k;
            } else if(a[nx][ny]==a[i][j]){
                if((i+j)&1){
                    flow.add_edge(get(i,j),get(nx,ny),1);
                }
            }
        }
    }
    int v1=flow.maxflow();
    if(v1<cnt[1]){
        int added_v = cnt[1] - v1;
        REP(i,n)REP(j,m){
            if(!((i+j)&1))continue;
            if(safe_dir[get(i,j)]!=-1){
                flow.add_edge(get(i,j),n*m+1,1);
            }
        }
        flow.add_edge(n*m+1,n*m+3,added_v);
        if(flow.maxflow()!=added_v){
            W("NO");
            return;
        }
    }
    if(v1<cnt[0]){
        int added_v = cnt[0] - v1;
        REP(i,n)REP(j,m){
            if((i+j)&1)continue;
            if(safe_dir[get(i,j)]!=-1){
                flow.add_edge(n*m+2,get(i,j),1);
            }
        }
        flow.add_edge(0,n*m+2,added_v);
        if(flow.maxflow()!=added_v){
            W("NO");
            return;
        }
    }
    REP(i,n)REP(j,m){
        int id=get(i,j);
        if((i+j)&1){
            for(int eid:flow.e[id]){
                if(!es[eid].c && es[eid^1].k){
                    int y=es[eid].k;
                    if(y>n*m){
                        dir[i][j]=dir_c[safe_dir[id]];
                        an[i][j]=a[i][j]-a[i+dx[safe_dir[id]]][j+dy[safe_dir[id]]];
                        //DEBUG(id,"here",y);
                    }else{
                        REP(k,4){
                            int nx=i+dx[k];
                            int ny=j+dy[k];
                            if(out(nx,ny))continue;
                            if(y==get(nx,ny)){
                                dir[i][j]=dir_c[k];
                                an[i][j]=1;
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int eid:flow.e[id]){
                if(es[eid].c && es[eid^1].k != n*m+3){
                    int y=es[eid].k;
                    if(y>n*m){
                        dir[i][j]=dir_c[safe_dir[id]];
                        an[i][j]=a[i][j]-a[i+dx[safe_dir[id]]][j+dy[safe_dir[id]]];
                    }else{
                        REP(k,4){
                            int nx=i+dx[k];
                            int ny=j+dy[k];
                            if(out(nx,ny))continue;
                            if(y==get(nx,ny)){
                                dir[i][j]=dir_c[k];
                                an[i][j]=a[i][j]-1;
                            }
                        }
                    }
                }
            }
        }
    }
    W("YES");
    REP(i,n){
        W(an[i]);
    }
    REP(i,n){
        REP(j,m){
            printf("%c%c",dir[i][j]," \n"[j==m-1]);
        }
    }
}
void input() {
    R(n,m);
    REP(i,n*m)safe_dir[i+1]=-1;
    REP(i,n){
        a[i].resize(m);
        an[i].resize(m);
        dir[i].resize(m);
        REP(j,m){
            R(a[i][j]);
        }
    }
}
int main(){
#define MULTITEST 1
#if MULTITEST    
    CASET
#endif
    {
        input();
        solve();
        my_clear();
    }
    return 0;
}