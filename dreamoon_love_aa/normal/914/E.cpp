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
typedef int64_t LL;
typedef uint64_t ULL;
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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2e5+10;
char str[SIZE];
int value[SIZE];
LL an[SIZE];
VI e[SIZE],emp;
int N;
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
vector<int>qq;
void build(int st){
    bfs[0]=st;
    tt2--;
    used[st]=tt2;
    int i=0,j=1;
    for(;i<j;i++){
        int x=bfs[i];
        sons[x]=1;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            father[y]=x;
            used[y]=tt2;
            bfs[j++]=y;
        }
    }
    int num=j;
    for(i=j-1;i>=0;i--){
        int x=bfs[i];
        if(sons[x]*2>=num){
            qq.PB(x);
            used[x]=tt;
            REP(k,SZ(e[x])){
                int y=e[x][k];
                if(used[y]!=tt)build(y);
            }
            return;
        }
        sons[father[x]]+=sons[x];
    }
}
void init(){
    tt++;
    qq.clear();
    build(0);
}
int all_value[SIZE],all_num;
int from[SIZE];
LL cul[SIZE],center_value;
int xor_value[SIZE],tmp[SIZE],tmp_n;
int target[21];
int ker1[1<<20],ker2[1<<20];
void add(int st,int center){
    bfs[0]=st;
    xor_value[0]=value[st];
    tt2--;
    used[st]=tt2;
    int rr=1;
    REP(i,rr){
        int x=bfs[i];
        tmp[tmp_n++]=xor_value[i];
        ker1[xor_value[i]]++;
        ker2[xor_value[i]]++;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            used[y]=tt2;
            xor_value[rr]=xor_value[i]^value[y];
            bfs[rr++]=y;
        }
    }

    bfs[0]=st;
    xor_value[0]=value[st];
    tt2--;
    used[st]=tt2;
    rr=1;
    REP(i,rr){
        int x=bfs[i];
        cul[i]=0;
        REP(j,21){
            cul[i]+=ker2[xor_value[i]^target[j]^value[center]];
        }
        center_value-=cul[i];
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            from[rr]=i;
            used[y]=tt2;
            xor_value[rr]=xor_value[i]^value[y];
            bfs[rr++]=y;
        }
    }
    for(int i=rr-1;i>=0;i--){
        ker2[xor_value[i]]=0;
        an[bfs[i]]-=cul[i];
        if(i)cul[from[i]]+=cul[i];
    }
}
void add2(int st,int center){
    bfs[0]=st;
    xor_value[0]=value[st];
    tt2--;
    used[st]=tt2;
    int rr=1;
    REP(i,rr){
        int x=bfs[i];
        cul[i]=0;
        REP(j,21){
            cul[i]+=ker1[xor_value[i]^target[j]^value[center]];
        }
        center_value+=cul[i];
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            from[rr]=i;
            used[y]=tt2;
            xor_value[rr]=xor_value[i]^value[y];
            bfs[rr++]=y;
        }
    }
    for(int i=rr-1;i>=0;i--){
        an[bfs[i]]+=cul[i];
        if(i)cul[from[i]]+=cul[i];
    }
}
void solve(){
    tt++;
    REP(i,SZ(qq)){
        int me=qq[i];
        used[me]=tt;
        center_value=2;
        all_num=0;
        tmp_n=0;
        REP(j,SZ(e[me])){
            int you=e[me][j];
            if(used[you]!=tt){
                add(you,me);
            }
        }
        REP(j,21){
            center_value+=ker1[target[j]^value[me]];
        }
        ker1[0]++;
        REP(j,SZ(e[me])){
            int you=e[me][j];
            if(used[you]!=tt){
                add2(you,me);
            }
        }
        REP(j,tmp_n)ker1[tmp[j]]=0;
        ker1[0]=0;
        an[me]+=center_value/2;
    }
}
int main(){
    REP(i,20)target[i]=1<<i;
    tt++;
    R(N);
    REPP(i,1,N){
        int x,y;
        R(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    RS(str);
    REP(i,N)value[i]=1<<(str[i]-'a');
    init();
    solve();
    W(VL(an,an+N));
    return 0;
}