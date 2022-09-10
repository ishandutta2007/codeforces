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
int u[4][4];
VI AA[4][4];
int v[10][3];
VPII pp{{0,0},{0,1},{0,2},{0,3},{1,1},{1,2},{1,3},{2,2},{2,3},{3,3}};
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
int an;
int ty[10];
void dfs(int x,int res){
    if(x==10){
        int cnt[4]={};
        U.init(4);
        int id=-1;
        REP(i,10){
            cnt[pp[i].F]+=ty[i];
            cnt[pp[i].S]+=ty[i];
            if(ty[i]){
                id=pp[i].F;
                U.uu(pp[i].F,pp[i].S);
            }
        }
        int odd=0;
        REP(i,4){
            if(cnt[i]&1)odd++;
        }
        if(odd&&odd!=2)return;
        if(id!=-1){
            REP(i,4){
                if(cnt[i]){
                    if(U.find(i)!=U.find(id))return;
                }
            }
        }
        an=max(an,res);
        return;
    }
    REP(i,3){
        ty[x]=i;
        if(v[x][i]>=0){
            dfs(x+1,res+v[x][i]);
        }
    }
}
int main(){
    int n; R(n);
    REP(i,n){
        int x,v,y;
        R(x,v,y);
        x--;y--;
        if(x>y)swap(x,y);
        AA[x][y].PB(v);
    }
    REP(i,SZ(pp)){
        int num=SZ(AA[pp[i].F][pp[i].S]);
        sort(ALL(AA[pp[i].F][pp[i].S]));
        int sum=0;
        for(int x:AA[pp[i].F][pp[i].S]){
            sum+=x;
        }
        v[i][1]=v[i][2]=-100000000;
        if(num==0)continue;
        if(num==1){
            v[i][1]=sum;
            continue;
        }
        if(num%2==0){
            v[i][2]=sum;
            v[i][1]=sum-AA[pp[i].F][pp[i].S][0];
        }
        else{
            v[i][1]=sum;
            v[i][2]=sum-AA[pp[i].F][pp[i].S][0];
        }
    }
    dfs(0,0);
    W(an);
    return 0;
}