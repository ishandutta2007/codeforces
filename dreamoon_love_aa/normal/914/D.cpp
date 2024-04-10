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
const int SIZE = 2e6+10;
int gg[SIZE],a[SIZE],len[SIZE];
void pull(int id){
    gg[id]=__gcd(gg[id*2],gg[id*2+1]);
}
void seg_init(int L,int R,int id){
    if(L==R){
        gg[id]=a[L];
        len[id]=1;
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    len[id]=len[id*2]+len[id*2+1];
    pull(id);
}
int target;
VI cul;
void qq(int L,int R,int id,int ll,int rr){
    if(gg[id]%target==0||SZ(cul)>1)return;
    if(L>=ll&&R<=rr){
        cul.PB(id);
        return;
    }
    int mm=(L+R)/2;
    if(mm>=rr)qq(L,mm,id*2,ll,rr);
    else if(mm<ll)qq(mm+1,R,id*2+1,ll,rr);
    else{
        qq(L,mm,id*2,ll,rr);
        qq(mm+1,R,id*2+1,ll,rr);
    }
}
void ins(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        gg[id]=v;
        return;
    }
    int mm=(L+R)/2;
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
bool test(int id){
    if(len[id]==1)return 1;
    int v1=gg[id*2]%target;
    int v2=gg[id*2+1]%target;
    if(v1&&v2)return 0;
    if(!v1&&!v2)return 1;
    if(!v1)return test(id*2+1);
    return test(id*2);
}
int main(){
    int n;R(n);
    FOR(i,1,n)R(a[i]);
    seg_init(1,n,1);
    int Q;
    R(Q);
    while(Q--){
        int ty;R(ty);
        if(ty==1){
            int l,r,x;
            R(l,r,x);
            target=x;
            cul.clear();
            qq(1,n,1,l,r);
            if(!SZ(cul))W("YES");
            else if(SZ(cul)>1)W("NO");
            else{
                W(test(cul[0])?"YES":"NO");
            }
        }
        else{
            int i,y;
            R(i,y);
            ins(1,n,1,i,i,y);
        }
    }
    return 0;
}