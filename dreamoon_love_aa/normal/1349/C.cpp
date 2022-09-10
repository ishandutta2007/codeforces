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
int n,m,t;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool u[1024][1024];
char s[1024][1024];
int v[1024][1024];
bool out(int x,int y){
    return x<=0||y<=0||x>n||y>m;
}
PII bfs[SIZE];
bool go(){
    int bn=0;
    FOR(i,1,n){
        FOR(j,1,m){
            bool suc=0;
            REP(k,4){
                PII nxt=MP(i+dx[k],j+dy[k]);
                if(out(nxt.F,nxt.S))continue;
                if(s[nxt.F][nxt.S]==s[i][j])suc=1;
            }
            if(suc){
                bfs[bn++]=MP(i,j);
                u[i][j]=1;
            }
        }
    }
    if(!bn)return 0;
    REP(i,bn){
        PII x=bfs[i];
        REP(j,4){
            PII nxt=MP(x.F+dx[j],x.S+dy[j]);
            if(out(nxt.F,nxt.S))continue;
            if(u[nxt.F][nxt.S])continue;
            u[nxt.F][nxt.S]=1;
            bfs[bn++]=nxt;
            v[nxt.F][nxt.S]=v[x.F][x.S]+1;
        }
    }
    return 1;
}
int main(){
    R(n,m,t);
    FOR(i,1,n)RS(s[i]+1);
    if(n*m==1){
        REP(k,t)printf("%c\n",s[1][1]);
        return 0;
    }
    if(!go()){
        REP(cs,t){
            int x,y;
            LL k;
            R(x,y,k);
            printf("%c\n",s[x][y]);
        }
    }
    else{
        REP(cs,t){
            int x,y;
            LL k;
            R(x,y,k);
            if(k<v[x][y]){
                printf("%c\n",s[x][y]);
            }
            else{
                printf("%d\n",(s[x][y]-'0')^(int)((k-v[x][y])&1));
            }
        }
    }
    return 0;
}