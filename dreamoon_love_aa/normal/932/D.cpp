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
const int SIZE = 4e5+10;
const LL INF = 1e18;
// 0-based
#define MAX_LV 19
VI e[SIZE];
int jump[MAX_LV+1][SIZE];
int nxt[MAX_LV+1][SIZE];
LL sum[MAX_LV+1][SIZE];
LL ww[SIZE];
LL ma[MAX_LV+1][SIZE];
void build(int id,int parent,LL w){
    jump[0][id]=parent;
    ma[0][id]=w;
    FOR(i,1,MAX_LV){
        jump[i][id]=jump[i-1][jump[i-1][id]];
        ma[i][id]=max(ma[i-1][id],ma[i-1][jump[i-1][id]]);
    }
    int now=parent;
    if(ww[now]<w){
        for(int i=MAX_LV;i>=0;i--){
            if(ma[i][now]<w)now=jump[i][now];
        }
    }
    nxt[0][id]=now;
    sum[0][id]=w;
    REPP(i,1,MAX_LV+1){
        nxt[i][id]=nxt[i-1][nxt[i-1][id]];
        sum[i][id]=min(INF,sum[i-1][id]+sum[i-1][nxt[i-1][id]]);
    }
}
int main(){
    int Q;R(Q);
    int last_ans=0;
    ww[0]=INF;
    FOR(i,0,MAX_LV){
        ma[i][0]=INF;
        sum[i][0]=INF;
    }
    build(1,0,0);
    int cnt=1;
    while(Q--){
        int ty;R(ty);
        LL p,q;R(p,q);
        p^=last_ans;
        q^=last_ans;
        if(ty==1){
            cnt++;
            ww[cnt]=q;
            build(cnt,p,q);
            //DEBUG(cnt,nxt[0][cnt]);
        }
        else{
            int ans=0,me=p;
            for(int i=MAX_LV;i>=0;i--){
                //if(i<2)DEBUG(i,me,sum[i][me]);
                if(sum[i][me]<=q){
                    q-=sum[i][me];
                    ans+=1<<i;
                    me=nxt[i][me];
                }
            }
            W(ans);
            last_ans=ans;
        }
    }
    return 0;
}