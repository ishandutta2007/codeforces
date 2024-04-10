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
const int SIZE = 1<<19;
int N,M;
int p[SIZE],b[SIZE];
LL fastR(){
  LL _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
#include <bits/extc++.h>
const int kerker = 512;
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
set_t AA[SIZE];
int small[SIZE][16];
void build(int L,int R,int id){
    if(R-L<kerker)return;
    /*
    if(R-L<kerker){
        FOR(i,L,R){
            small[id][i-L]=b[i];
        }
    }
    else{*/
        AA[id]=set_t(b+L,b+R+1);
    //}
    if(L==R)return;
    int mm=(L+R)/2;
    build(L,mm,id*2);
    build(mm+1,R,id*2+1);
}
int xx,yy;
void change(int L,int R,int id){
    if(R-L<kerker)return;
    if(xx<L){
        AA[id].erase(b[yy]);
        AA[id].insert(b[xx]);
    }
    else if(yy>R){
        AA[id].erase(b[xx]);
        AA[id].insert(b[yy]);
    }
    if(L==R)return;
    int mm=(L+R)/2;
    if((yy<=mm&&L<=yy)
     ||(xx<=mm&&L<=xx))change(L,mm,id*2);
    if((xx>mm&&xx<=R)
     ||(yy>mm&&yy<=R))change(mm+1,R,id*2+1);
}
int an;
int l1,r1,l2,r2;
void solve(int L,int R,int id){
    if(R<l2||L>r2)return;
    if(min(r2,R)-max(l2,L)<kerker){
        int ed=min(r2,R);
        FOR(i,max(l2,L),ed){
            an+=(b[i]>=l1&&b[i]<=r1);
        }
        return;
    }
    if(L>=l2&&R<=r2){
        an+=AA[id].order_of_key(r1+1)-AA[id].order_of_key(l1);
        return;
    }
    int mm=(L+R)/2;
    solve(L,mm,id*2);
    solve(mm+1,R,id*2+1);
}
int main(){
    N=fastR();
    M=fastR();
    FOR(i,1,N){
        int x;
        x=fastR();
        p[x]=i;
    }
    FOR(i,1,N){
        int x; 
        x=fastR();
        b[i]=p[x];
    }
    build(1,N,1);
    while(M--){
        int ty=fastR();
        if(ty==1){
            l1=fastR();
            r1=fastR();
            l2=fastR();
            r2=fastR();
            an=0;
            solve(1,N,1);
            W(an);
        }
        else{
            xx=fastR();
            yy=fastR();
            if(xx>yy)swap(xx,yy);
            change(1,N,1);
            swap(b[xx],b[yy]);
        }
    }
    return 0;
}