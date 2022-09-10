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
const int SIZE = 21*21;
int an[SIZE][SIZE];
int cnt[1024];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){return (x!=d[x])?(d[x]=find(d[x])):x;}
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
int n;
int id[21][21];
VI ty[5];
int AA[5];
VI BB[SIZE];
bool good(){
    if(SZ(ty[4])>AA[4]){
        return 0;
    }
    AA[4]-=SZ(ty[4]);
    AA[2]+=AA[4]*2;
    if(SZ(ty[2])>AA[2]){
        return 0;
    }
    REP(i,n)REP(j,n){
        if(U.num[U.find(id[i][j])]==4&&!an[i][j]){
            FOR(k,1,1000){
                if(cnt[k]>=4){
                    cnt[k]-=4;
                    an[i][j]=an[i][n-1-j]=an[n-1-i][j]=an[n-1-i][n-1-j]=k;
                    break;
                }
            }
        }
    }
    REP(i,n)REP(j,n){
        if(U.num[U.find(id[i][j])]==2&&!an[i][j]){
            FOR(k,1,1000){
                if(cnt[k]>=2){
                    cnt[k]-=2;
                    an[i][j]=an[i][n-1-j]=an[n-1-i][j]=an[n-1-i][n-1-j]=k;
                    break;
                }
            }
        }
    }
    REP(i,n)REP(j,n){
        if(U.num[U.find(id[i][j])]==1&&!an[i][j]){
            FOR(k,1,1000){
                if(cnt[k]>=1){
                    cnt[k]-=1;
                    an[i][j]=an[i][n-1-j]=an[n-1-i][j]=an[n-1-i][n-1-j]=k;
                    break;
                }
            }
        }
    }
    return 1;
}
int main(){
    R(n);
    {
        int tt=0;
        REP(i,n)REP(j,n){
            id[i][j]=tt++;
        }
    }
    U.init(n*n+1);
    FOR(i,1,n*n){
        int x; R(x);
        cnt[x]++;
    }
    REP(i,n)REP(j,n){
        U.uu(id[i][j],id[i][n-1-j]);
        U.uu(id[i][j],id[n-1-i][j]);
    }
    REP(i,n*n){
        if(U.is_root(i)){
            ty[U.num[i]].PB(i);
        }
    }
    FOR(i,1,1000){
        int v=cnt[i];
        AA[4]+=v/4;
        v%=4;
        AA[2]+=v/2;
        v%=2;
        AA[1]+=v;
    }
    if(!good())W("NO");
    else{
        W("YES");
        REP(i,n)W(VI(an[i],an[i]+n));
    }
    return 0;
}