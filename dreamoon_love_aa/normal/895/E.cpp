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
const int SIZE = 4e5+10;
int a[SIZE],num[SIZE];
double s[SIZE],_tmp[SIZE][2];
void push(int id){
    if(_tmp[id]==0)return;
    _tmp[id*2][0]*=_tmp[id][0];
    _tmp[id*2][1]=_tmp[id*2][1]*_tmp[id][0]+_tmp[id][1];
    s[id*2]=_tmp[id][0]*s[id*2]+_tmp[id][1]*num[id*2];
    _tmp[id*2+1][0]*=_tmp[id][0];
    _tmp[id*2+1][1]=_tmp[id*2+1][1]*_tmp[id][0]+_tmp[id][1];
    s[id*2+1]=_tmp[id][0]*s[id*2+1]+_tmp[id][1]*num[id*2+1];
    _tmp[id][0]=1;_tmp[id][1]=0;
}
void pull(int id){
    s[id]=s[id*2]+s[id*2+1];
}
void init(int L,int R,int id){
    _tmp[id][0]=1;
    _tmp[id][1]=0;
    if(L==R){
        s[id]=a[L];
        num[id]=1;
        return;
    }
    int mm=(L+R)/2;
    init(L,mm,id*2);
    init(mm+1,R,id*2+1);
    num[id]=num[id*2]+num[id*2+1];
    pull(id);
}
double qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return 0;
    if(L>=ll&&R<=rr)return s[id];
    int mm=(L+R)/2;
    push(id);
    return qq(L,mm,id*2,ll,rr)+qq(mm+1,R,id*2+1,ll,rr);
}
double c1,c2;
void ins(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        s[id]=s[id]*c1+c2*num[id];
        _tmp[id][0]*=c1;
        _tmp[id][1]=_tmp[id][1]*c1+c2;
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr);
    ins(mm+1,R,id*2+1,ll,rr);
    pull(id);
}
int main(){
    int n,q;
    R(n,q);
    FOR(i,1,n)R(a[i]);
    init(1,n,1);
    while(q--){
        int ty;
        R(ty);
        if(ty==1){
            int l1,r1,l2,r2;
            R(l1,r1,l2,r2);
            int n1=r1-l1+1;
            int n2=r2-l2+1;
            double v1=qq(1,n,1,l1,r1);
            double v2=qq(1,n,1,l2,r2);
            //DEBUG(v1,v2);
            c1=(n1-1.)/n1;
            c2=v2/((LL)n1*n2);
            ins(1,n,1,l1,r1);
            c1=(n2-1.)/n2;
            c2=v1/((LL)n1*n2);
            ins(1,n,1,l2,r2);
        }
        else{
            int l,r;
            R(l,r);
            printf("%.9f\n",qq(1,n,1,l,r));
        }
    }
    return 0;
}