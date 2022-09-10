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
struct AA{
    int x,y;
    AA(int x=0,int y=0):x(x),y(y){}
    bool operator==(const AA& b)const{return x==b.x&&y==b.y;}
    void scan(){R(x,y);}
}me,black[SIZE];
const int N = 666;
bool best(AA king){
    if(king.x<=0||king.y<=0||king.x>999||king.y>999)return 0;
    bool good=0;
    FOR(i,1,666){
        if(king==black[i])return 0;
        if(king.x==black[i].x||king.y==black[i].y)good=1;
    }
    return good;
}
void mov(int x ,int y){
    W(x,y);
    fflush(stdout);
}
void update(){
    int k,x,y;
    R(k,x,y);
    black[k]=AA(x,y);
}
void can_win(AA king){
    FOR(dx,-1,1)FOR(dy,-1,1){
        if(best(AA(king.x+dx,king.y+dy))){
            mov(king.x+dx,king.y+dy);
            exit(0);
        }
    }
}
int main(){
    me.scan();
    FOR(i,1,666)black[i].scan();
    AA O(500,500);
    while(!(me==O)){
        can_win(me);
        if(me.x>O.x)me.x--;
        else if(me.x<O.x)me.x++;
        
        if(me.y>O.y)me.y--;
        else if(me.y<O.y)me.y++;
        mov(me.x,me.y);
        update();
    }
    int cnt[4]={};
    FOR(i,1,666){
        int ty=0;
        if(black[i].x>me.x)ty|=1;
        if(black[i].y>me.y)ty|=2;
        cnt[ty]++;
    }
    int mi=min({cnt[0],cnt[1],cnt[2],cnt[3]});
    int dx,dy;
    if(mi==cnt[0]){
        dx=dy=1;
    }
    else if(mi==cnt[1]){
        dx=-1;
        dy=1;
    }
    else if(mi==cnt[2]){
        dx=1;
        dy=-1;
    }
    else{
        dx=dy=-1;
    }
    while(1){
        can_win(me);
        me.x+=dx;
        me.y+=dy;
        mov(me.x,me.y);
        update();
    }
    return 0;
}