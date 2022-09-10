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
const int SIZE = 100001;
int p[SIZE];
vector<int>fac[SIZE];
void prime_init(){
    for(int i=1;i<SIZE;i++){
        for(int j=i;j<SIZE;j+=i)fac[j].PB(i);
    }
}
bool is_prime(int x){
    return p[x]==x;
}
bool done(int it[],int AA[]){
    REP(i,3){
        if(it[i]>=SZ(fac[AA[i]]))return 1;
    }
    return 0;
}
int solve(int AA[]){
    set<tuple<int,int,int>>gg;
    FOR(x,1,AA[0])FOR(y,1,AA[1])FOR(z,1,AA[2]){
        if(AA[0]%x==0&&AA[1]%y==0&&AA[2]%z==0)gg.insert(make_tuple(min({x,y,z}),x+y+z-max({x,y,z})-min({x,y,z}),max({x,y,z})));
    }
    return SZ(gg);
}
LL an=0;
int use[8];
int now[3];
void dfs(int x,int st,LL v,int gg[]){
    if(x==3){
        int per[3]={0,1,2};
        do{
            bool fail=0;
            REP(i,3){
                if(!((now[i]>>per[i])&1))fail=1;
            }
            if(!fail){
                an+=v;
                return;
            }
        }while(next_permutation(per,per+3));
        return;
    }
    REPP(i,st,8){
        if(use[i]>=gg[i])continue;
        int nxt_v=v;
        nxt_v*=gg[i]-use[i];
        use[i]++;
        now[x]=i;
        nxt_v /= use[i];
        dfs(x+1,i,nxt_v,gg);
        use[i]--;
    }
}
int main(){
    prime_init();
    CASET{
        int AA[3];
        REP(i,3)R(AA[i]);
        an=0;
        int gg[8]={};
        REP(i,3)gg[1<<i]=SZ(fac[AA[i]]);
        {
            gg[7]=SZ(fac[__gcd(__gcd(AA[0],AA[1]),AA[2])]);
            REPP(i,1,7)gg[i]-=gg[7];
        }
        REP(i,3)REPP(j,i+1,3){
            int cnt=SZ(fac[__gcd(AA[i],AA[j])]);
            int me=(1<<i)|(1<<j);
            gg[me]+=cnt;
            gg[1<<i]-=gg[me];
            gg[1<<j]-=gg[me];
        }
        int sum=0;
        REPP(i,1,8)sum+=gg[i];
        an+=gg[7];
        an+=gg[7]*(sum-1);
        an+=gg[3]*(gg[4]+gg[5]+gg[6]+gg[7]);
        an+=gg[5]*(gg[2]+gg[3]+gg[6]+gg[7]);
        an+=gg[6]*(gg[1]+gg[3]+gg[5]+gg[7]);
        dfs(0,1,1,gg);
        W(an);
    }
    return 0;
}