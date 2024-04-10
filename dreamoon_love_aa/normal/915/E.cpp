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
const int SIZE = 4e6+10;
LL s[SIZE],_tmp[SIZE],num[SIZE];
int d[SIZE],dn;
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2]=_tmp[id*2+1]=_tmp[id];
    if(_tmp[id]==1){
        s[id*2]=num[id*2];
        s[id*2+1]=num[id*2+1];
    }
    else s[id*2]=s[id*2+1]=0;
    _tmp[id]=0;
}
void pull(int id){
    s[id]=s[id*2]+s[id*2+1];
}
void seg_init(int L,int R,int id){
    if(L==R){
        s[id]=d[L]-d[L-1];
        num[id]=s[id];
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    pull(id);
    num[id]=num[id*2]+num[id*2+1];
}
void ins(int L,int R,int id,int ll,int rr,int v){
    if(L>=ll&&R<=rr){
        _tmp[id]=v;
        if(v==1)s[id]=num[id];
        else s[id]=0;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    if(mm>=ll)ins(L,mm,id*2,ll,rr,v);
    if(mm<rr)ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int input[300000][3];
int main(){
    int N,Q;
    R(N);
    R(Q);
    d[dn++]=1;d[dn++]=N+1;
    REP(i,Q){
        REP(j,3)R(input[i][j]);
        d[dn++]=input[i][0];
        d[dn++]=input[i][1]+1;
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d-1;
    seg_init(1,dn,1);
    REP(i,Q){
        int x=lower_bound(d,d+dn+1,input[i][0])-d+1,y=lower_bound(d,d+dn+1,input[i][1]+1)-d,k=input[i][2];
        if(k==1){
            ins(1,dn,1,x,y,-1);
        }
        else{
            ins(1,dn,1,x,y,1);
        }
        W(s[1]);
    }
    return 0;
}