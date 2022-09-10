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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
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
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
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
        return 1;
    }
}U;
int n,m;
int get(int x,int y){
    return x*m+y;
}
bool out(int x,int y){
    if(x<0||y<0||x>=n||y>=m)return 1;
    return 0;
}
char s[1024][1024];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    R(n,m);
    REP(i,n)RS(s[i]);
    U.init(n*m);
    REP(i,n)REP(j,m){
        if(s[i][j]=='*')continue;
        else{
            if(s[i+1][j]=='.'){
                U.uu(get(i+1,j),get(i,j));
            }
            if(s[i][j+1]=='.'){
                U.uu(get(i,j+1),get(i,j));
            }
        }
    }
    REP(i,n){
        REP(j,m){
            if(s[i][j]=='.')printf(".");
            else{
                int an=1;
                set<int>AA;
                REP(k,4){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(out(nx,ny))continue;
                    if(AA.count(U.find(get(nx,ny))))continue;
                    if(s[nx][ny]=='*')continue;
                    AA.insert(U.find(get(nx,ny)));
                    an+=U.num[U.find(get(nx,ny))];
                }
                printf("%d",an%10);
            }
        }
        W("");
    }
    return 0;
}