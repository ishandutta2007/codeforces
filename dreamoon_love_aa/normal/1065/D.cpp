/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const LL INF = 1e8; //INF should be enough large.
typedef long long MYTYPE;
struct Data{
    MYTYPE v;
    int id;
    Data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const Data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
        REP(i,n+1)e[i].clear();
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
    }
    void dis(int st){
        priority_queue<Data>qq;
        REP(i,n+1)mi[i]=INF,used[i]=0;
        mi[st]=0;
        qq.push(Data(0,st));
        while(!qq.empty()){
            Data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            REP(i,SZ(e[now.id])){
                int y=e[now.id][i].F;
                if(mi[y]>now.v+e[now.id][i].S){
                    mi[y]=now.v+e[now.id][i].S;
                    qq.push(Data(mi[y],y));
                }
            }
        }
    }
}dij;
int N;
bool out(int x,int y){
    return x<=0||y<=0||x>N||y>N;
}
PII pos[101];
int dp[101][3];
int dx2[8]={1,1,-1,-1,2,2,-2,-2};
int dy2[8]={2,-2,2,-2,1,-1,1,-1};
void update(PII &x,PII y){
    x=min(x,y);
}
int a[11][11];
int _id[11][11];
int get_id(PII p, int ty){
    return _id[p.F][p.S]*3+ty;
}
int dis[300][300];
int dx1[4]={1,1,-1,-1};
int dy1[4]={1,-1,1,-1};
int main(){
    R(N);
    dij.init(N*N*3);
    FOR(i,1,N)FOR(j,1,N){
        R(a[i][j]);
        pos[a[i][j]]=MP(i,j);
        _id[i][j]=(i-1)*N+j-1;
    }
    FOR(i,1,N)FOR(j,1,N){
        FOR(k,1,N){
            if(j!=k)dij.add_edge(get_id(MP(i,j),0),get_id(MP(i,k),0),1024);
            if(i!=k)dij.add_edge(get_id(MP(i,j),0),get_id(MP(k,j),0),1024);
        }
        REP(k,4){
            PII now=MP(i,j);
            now=MP(now.F+dx1[k],now.S+dy1[k]);
            while(!out(now.F,now.S)){
                dij.add_edge(get_id(MP(i,j),1),get_id(MP(now.F,now.S),1),1024);
                now=MP(now.F+dx1[k],now.S+dy1[k]);
            }
        }
        REP(k,8){
            PII now=MP(i+dx2[k],j+dy2[k]);
            if(!out(now.F,now.S)){
                dij.add_edge(get_id(MP(i,j),2),get_id(MP(now.F,now.S),2),1024);
            }
        }
        REP(k1,3)REP(k2,3){
            if(k1!=k2){
                dij.add_edge(get_id(MP(i,j),k1),get_id(MP(i,j),k2),1025);
            }
        }
    }
    REP(i,3*N*N){
        dij.dis(i);
        REP(j,3*N*N)dis[i][j]=dij.mi[j];
    }
    REP(i,101)REP(j,3)dp[i][j]=MOD;
    REP(j,3)dp[1][j]=0;
    FOR(i,1,N*N-1){
        REP(j,3){
            REP(k,3){
                dp[i+1][k]=min(dp[i+1][k],dp[i][j]+dis[get_id(pos[i],j)][get_id(pos[i+1],k)]);
            }
        }
    }
    int an=MOD;
    REP(j,3)an=min(an,dp[N*N][j]);
    W(an>>10,an&1023);
    return 0;
}