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
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 9000010;
int n,k;
int a[SIZE];
int get_bit(long long x, int v) { return (x >> v) & 1; }
int ID;
int nxt[SIZE][2],num[SIZE];
int from[SIZE];
int hi_bit;
void ins(int v,int p){
    int now=0;
    num[now]++;
    from[now]=p;
    for(int i=hi_bit-1;i>=0;i--){
        int bit=get_bit(v,i);
        if(!nxt[now][bit]){
            nxt[now][bit]=++ID;
        }
        now=nxt[now][bit];
        num[now]++;
        from[now]=p;
    }
}
void del(int v){
    int now=0;
    num[now]--;
    for(int i=hi_bit-1;i>=0;i--){
        int bit=get_bit(v,i);
        now=nxt[now][bit];
        num[now]--;
    }
}
int qq(int v){
    int now=0;
    num[now]++;
    bool done=0;
    for(int i=hi_bit-1;i>=0;i--){
        int bit=get_bit(v,i);
        int bit2=get_bit(k,i);
        if(done){
            REP(i,2){
                if(nxt[now][i]&&num[nxt[now][i]]){
                    now=nxt[now][i];
                    break;
                }
            }
        }else{
            if(nxt[now][bit^1]&&num[nxt[now][bit^1]]){
                now=nxt[now][bit^1];
                if(!bit2){
                    done=1;
                }
            }else{
                if(bit2) return -1;
                if(!nxt[now][bit]||!num[nxt[now][bit]])return -1;
                now=nxt[now][bit];
            }
        }
    }
    return from[now];
}
void solve() {
    if(!k){
        W(n);
        VI an;
        FOR(i,1,n)an.PB(i);
        W(an);
        return;
    }
    if(k==1){
        VPII AA;
        FOR(i,1,n){
            AA.PB(MP(a[i],i));
        }
        VI an;
        sort(ALL(AA));
        REP(i,SZ(AA)){
            if(!i||AA[i].F!=AA[i-1].F){
                an.PB(AA[i].S);
            }
        }
        W(SZ(an));
        W(an);
        return;
    }
    hi_bit=0;
    for(int i=29;i>=0;i--){
        if(get_bit(k,i)){
            hi_bit=i;
            break;
        }
    }
    VPII AA;
    FOR(i,1,n){
        AA.PB(MP(a[i],i));
    }
    sort(ALL(AA));
    VI pos;
    for(int i=0,j;i<SZ(AA);i=j){
        pos.PB(i);
        for(j=i+1;j<SZ(AA)&&(AA[i].F>>hi_bit)==(AA[j].F>>hi_bit);j++);
    }
    VI an;
    pos.PB(SZ(AA));
    REP(i,SZ(pos)-1){
        if(i+2<SZ(pos)&&(AA[pos[i]].F>>hi_bit+1)==(AA[pos[i+1]].F>>hi_bit+1)){
            REPP(j,pos[i],pos[i+1]){
                ins(AA[j].F,AA[j].S);
            }
            bool found=0;
            REPP(j,pos[i+1],pos[i+2]){
                int ret=qq(AA[j].F);
                if(ret!=-1){
                    found=1;
                    an.PB(ret);
                    an.PB(AA[j].S);
                    break;
                }
            }
            if(!found)an.PB(AA[pos[i]].S);
            REPP(j,pos[i],pos[i+1]){
                del(AA[j].F);
            }
            i++;
        }else{
            an.PB(AA[pos[i]].S);
        }
    }
    if(SZ(an)<2)W(-1);
    else {
        W(SZ(an));
        W(an);
    }
}
void input() {
    R(n,k);
    FOR(i,1,n)R(a[i]);
}
int main(){
    input();
    solve();
    return 0;
}