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
const int MAX_N = 40;
bitset<MAX_N>MASK,ZERO,e[MAX_N],ans;
int N=40;
void bk_init(){
    ans=0;
    MASK=ZERO;
    MASK.flip();
}
void bk(bitset<MAX_N>use, bitset<MAX_N>can_start,bitset<MAX_N>can_other){
    if(can_start.none()&&can_other.none()){
        if(use.count()>ans.count())ans=use;
        return;
    }
    bitset<MAX_N> r=can_start;
    bool fi=1;
    REP(i,N)
        if(r[i]){
            if(fi){
                fi=0;
                r&=e[i]^MASK;
            }
            use[i]=1;
            bk(use,can_start&e[i],can_other&e[i]);
            use[i]=0;
            can_start[i]=0;
            can_other[i]=1;
        }
}
void solve_bk(){
    bitset<MAX_N>me;
    bk(me,MASK,ZERO);
}
int id=0;
map<string,int>AA;
int get(string &s){
    if(AA.count(s))return AA[s];
    return AA[s]=id++;
}
bitset<MAX_N>now;
int n,m;
void clr(){
    REP(i,id){
        if(!now[i])continue;
        REP(j,i){
            if(now[j]){
                e[i][j]=e[j][i]=1;
            }
        }
    }
    now.reset();
}
int main(){
    R(n,m);
    REP(i,n){
        int ty;
        R(ty);
        if(ty==1){
            clr();
        }
        else{
            string s;R(s);
            int it=get(s);
            now[it]=1;
        }
    }
    clr();
    N=id;
    bk_init();
    REP(i,N)REP(j,N){
        if(i!=j)e[i][j]=!e[i][j];
    }
    solve_bk();
    int an=0;
    REP(i,N)an+=ans[i];
    W(an);
}
/*
int main(){
    bk_init();
    int k;
    R(N,k);
    REP(i,N)REP(j,N){
        DRI(x);
        if(x)e[i][j]=1;
    }
    solve_bk();
    printf("%.12f\n",k*k*(ans.count()-1)*0.5/ans.count());
    return 0;
}*/