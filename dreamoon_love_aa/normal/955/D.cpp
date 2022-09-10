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
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
char s[SIZE],t[SIZE];
char g[SIZE];
int far[SIZE];
VI build(int n,int m){
    strcpy(g,t);
    strcat(g,s);
    int ll=0,rr=0;
    REPP(i,1,n+m){
        int it=0;
        if(i<rr){
            it=min(rr-i,far[i-ll]);
        }
        while(it<m&&g[i+it]==g[it])it++;
        far[i]=it;
        if(i+it>rr){
            ll=i;
            rr=i+it;
        }
    }
    return VI(far+m,far+m+n);
}
void yes(int x,int y){
    W("Yes");
    W(x,y);
    exit(0);
}
void no(){
    W("No");
    exit(0);
}
int lft[SIZE];
int mi[SIZE],_tmp[SIZE];
void push(int id){
    if(_tmp[id]==MOD)return;
    mi[id*2]=min(mi[id*2],_tmp[id]);
    mi[id*2+1]=min(mi[id*2+1],_tmp[id]);
    _tmp[id*2]=min(_tmp[id*2],_tmp[id]);
    _tmp[id*2+1]=min(_tmp[id*2+1],_tmp[id]);
    _tmp[id]=MOD;
}
void pull(int id){
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
void seg_init(int L,int R,int id){
    _tmp[id]=MOD;
    if(L==R){
        mi[id]=MOD;
        return;
    }
    int mm=(L+R)/2;
    seg_init(L,mm,id*2);
    seg_init(mm+1,R,id*2+1);
    pull(id);
}
int qq(int L,int R,int id,int ll,int rr){
    if(R<ll||L>rr)return MOD;
    if(L>=ll&&R<=rr)return mi[id];
    int mm=(L+R)/2;
    push(id);
    return min(qq(L,mm,id*2,ll,rr),qq(mm+1,R,id*2+1,ll,rr));
}
void ins(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        mi[id]=min(mi[id],v);
        _tmp[id]=min(_tmp[id],v);
        return;
    }
    int mm=(L+R)/2;
    push(id);
    ins(L,mm,id*2,ll,rr,v);
    ins(mm+1,R,id*2+1,ll,rr,v);
    pull(id);
}
int main(){
    int n,m,k; R(n,m,k);
    RS(s); RS(t);
    VI ll=build(n,m);
    reverse(s,s+n);
    reverse(t,t+m);
    VI rr=build(n,m);
    seg_init(1,k,1);
    MS1(lft);
    REP(i,n){
        if(ll[i]==m){
            int mii=min(i+1,n-2*k+1);
            yes(mii,mii+k);
        }
        if(ll[i]>0&&ll[i]+i>=k){
            if(i==4)DEBUG("{%d,%d}\n",max(1,k-i),ll[i]);
            ins(1,k,1,max(1,k-i),ll[i],i);
        }
    }
    FOR(i,1,k){
        lft[i]=qq(1,k,1,i,i);
        if(lft[i]==MOD)lft[i]=-1;
    }
    REP(i,n){
        if(rr[i]!=-1&&rr[i]+i>=k){
            rr[i]=min(rr[i],k);
            int op=lft[m-rr[i]];
            if(op==-1)continue;
            if(op+m+i>n)continue;
            DEBUG("[%d,%d]\n",op,i);
            yes(op+(m-rr[i])-k+1,n-i-rr[i]+1);
        }
    }
    no();
    return 0;
}