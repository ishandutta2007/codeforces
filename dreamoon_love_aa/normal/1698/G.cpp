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
#include<iomanip>
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
#define CASET int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
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
template<class T,class U> void _R(pair<T,U> &x) {cin >> x.F >> x.S;}
void R() {}
template<class T, class... U> void R(T &head, U &... tail) {_R(head); R(tail...);}
template<class T> void _W(const T &x) {cout << x;}
void _W(const double &x) {cout << fixed << setprecision(16) << x;}
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); cout << ' '; _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) cout << ' '; }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); cout << (sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {cout << "[DEBUG] "; W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<18;
VPLL d;
string s;
int get_bit(long long x, int v) { return (x >> v) & 1; }
int get(LL x){
    int pos=lower_bound(ALL(d),MP(x,0LL))-d.begin();
    if(pos==SZ(d))return -1;
    if(d[pos].F!=x)return -1;
    return d[pos].S;
}
void solve() {
    if(count(ALL(s),'1')==0){
        W(-1);
        return;
    }
    if(count(ALL(s),'1')==1){
        REP(i,SZ(s)){
            if(s[i]=='1'){
                W(i+1,i+2);
                return;
            }
        }
    }
    if(count(ALL(s),'1')==2){
        VI an;
        REP(i,SZ(s)){
            if(s[i]=='1'){
                an.PB(i+1);
            }
        }
        W(an);
        return;
    }
    int head_zero_cnt=0;
    while(s[0]=='0'){
        head_zero_cnt++;
        s.erase(s.begin());
    }
    while(s.back()=='0')s.pop_back();
    int n=SZ(s);
    LL base=0;
    REP(i,n){
        base<<=1;
        if(s[i]=='1')base|=1;
    }
    LL now=base^(1LL<<(n-1));
    REP(i,SIZE){
        if(!(now&(now-1))){
            W(head_zero_cnt+1,head_zero_cnt+i+(n-__builtin_ctzll(now)));
            return;
        }
        d.PB({now,i});
        if(get_bit(now,n-2))now=(now<<1)^base;
        else now<<=1;
    }
    sort(ALL(d));
    LL jp=1;
    REP(i,SIZE-100){
        if(jp&1){
            jp^=base;
            jp>>=1;
        }else{
            jp>>=1;
        }
    }
    now=1;
    REPP(i,1,SIZE){
        LL nxt=0;
        REP(i,n){
            if(nxt&1)nxt^=base;
            nxt>>=1;
            if(get_bit(now,i)){
                nxt^=jp;
            }
        }
        now=nxt;
        int v=get(now);
        if(v!=-1){
            DEBUG(i,v);
            LL res=head_zero_cnt+v+(SIZE-100LL+n-1)*i+n;
            W(head_zero_cnt+1,res);
            DEBUG(res-37452687);
            return;
        }
    }
    W(-1);
}
void input() {
    R(s);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}