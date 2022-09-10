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
const int SIZE = 2010;
char s[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m;
bool out(int x,int y){
    return 0>x||x>=n||0>y||y>=m||s[x][y]=='*';
}
void AC(){
    W("YES");
    exit(0);
}
int main(){
    R(n,m);
    PII x,y;
    REP(i,n){
        RS(s[i]);
        REP(j,m){
            if(s[i][j]=='S')x=MP(i,j);
            else if(s[i][j]=='T')y=MP(i,j);
        }
    }
    REP(i,4){
        PII now=x;
        while(!out(now.F,now.S)){
            if(s[now.F][now.S]=='T')AC();
            s[now.F][now.S]='S';
            now.F+=dx[i];
            now.S+=dy[i];
        }
    }
    REP(i,4){
        PII now=y;
        while(!out(now.F,now.S)){
            if(s[now.F][now.S]=='S')AC();
            s[now.F][now.S]='T';
            now.F+=dx[i];
            now.S+=dy[i];
        }
    }
    REP(i,n){
        for(int j=0,k;j<m;j=k){
            if(s[i][j]=='*'){
                k=j+1;
                continue;
            }
            int now=0;
            for(k=j;k<m&&s[i][k]!='*';k++){
                if(s[i][k]=='S')now|=1;
                else if(s[i][k]=='T')now|=2;
            }
            if(now==3)AC();
        }
    }
    REP(j,m){
        for(int i=0,k;i<n;i=k){
            if(s[i][j]=='*'){
                k=i+1;
                continue;
            }
            int now=0;
            for(k=i;k<n&&s[k][j]!='*';k++){
                if(s[k][j]=='S')now|=1;
                else if(s[k][j]=='T')now|=2;
            }
            if(now==3)AC();
        }
    }
    W("NO");
    return 0;
}