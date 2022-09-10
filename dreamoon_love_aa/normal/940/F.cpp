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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE],in[SIZE][3],ans[SIZE];
const int R_R=1<<12;
int cnt[SIZE],cul[SIZE];
int get_answer(){
    int ret=1;
    while(cul[ret])ret++;
    return ret;
}
void add(int y,int v){
    cul[cnt[y]]--;
    cnt[y]+=v;
    cul[cnt[y]]++;
}
void change(int x,int y){
    if(x==y)return;
    add(b[x],-1);
    b[x]=y;
    add(b[x],1);
}
int solve(int ll,int rr){
    FOR(i,ll,rr){
        add(b[i],1);
    }
    int ret=get_answer();
    FOR(i,ll,rr){
        add(b[i],-1);
    }
    return ret;
}
int main(){
    VI d;
    MS1(ans);
    int n,q;
    R(n,q);
    REP(i,n){
        R(a[i]);
        d.PB(a[i]);
    }
    REP(i,q){
        REP(j,3)R(in[i][j]);
        if(in[i][0]==1){
            in[i][1]--;in[i][2]--;
        }
        else{
            in[i][1]--;
            d.PB(in[i][2]);
        }
    }
    SORT_UNIQUE(d);
    REP(i,n)b[i]=a[i]=GET_POS(d,a[i]);
    REP(i,q){
        if(in[i][0]==2){
            in[i][2]=GET_POS(d,in[i][2]);
            b[in[i][1]]=in[i][2];
        }
        else{
            if(in[i][2]-in[i][1]<=R_R)
                ans[i]=solve(in[i][1],in[i][2]);
        }
    }
    for(int len=R_R;len<n;len+=R_R){
        for(int ll=0;ll+len<n;ll+=R_R){
            int rr=ll+len+R_R;
            REPP(i,ll,min(n,rr))b[i]=a[i];
            REPP(i,ll+R_R,ll+len){
                add(b[i],1);
            }
            REP(i,q){
                if(in[i][0]==2){
                    if(in[i][1]>=ll+R_R&&in[i][1]<ll+len){
                        change(in[i][1],in[i][2]);
                    }
                    else{
                        b[in[i][1]]=in[i][2];
                    }
                }
                else{
                    if(ans[i]==-1&&in[i][1]>=ll&&in[i][2]<rr){
                        REPP(j,in[i][1],ll+R_R){
                            add(b[j],1);
                        }
                        FOR(j,ll+len,in[i][2]){
                            add(b[j],1);
                        }
                        ans[i]=get_answer();
                        REPP(j,in[i][1],ll+R_R){
                            add(b[j],-1);
                        }
                        FOR(j,ll+len,in[i][2]){
                            add(b[j],-1);
                        }
                    }
                }
            }
            REPP(i,ll+R_R,ll+len){
                add(b[i],-1);
            }
        }
    }
    REP(i,q){
        if(ans[i]!=-1)W(ans[i]);
    }
    return 0;
}