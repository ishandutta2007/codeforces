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
const int SIZE = 1<<20;
int n,p[SIZE],from[SIZE];
void solve() {
    VI u(n+1);
    FOR(i,1,n)from[p[i]]=i;
    VI q;
    q.PB(1);
    u[1]=1;
    int now=1;
    int cnt=1;
    while(!u[from[now]]){
        u[from[now]]=1;
        q.PB(from[now]);
        now=from[now];
    }
    FOR(i,2,n){
        if(!u[i]){
            cnt++;
            int ins_pos=-1;
            REP(j,SZ(q)){
                if(q[j]==i-1){
                    ins_pos=j+1;
                    break;
                }
            }
            VI tmp{from[i]};
            u[from[i]]=1;
            now=from[i];
            while(!u[from[now]]){
                u[from[now]]=1;
                tmp.PB(from[now]);
                now=from[now];
            }
            q.insert(q.begin()+ins_pos,ALL(tmp));
        }
    }
    LL sum=0;
    REP(i,n){
        sum+=abs(q[i]-p[q[(i+1)%n]]);
    }
    /*
    if(sum!=2*cnt-2){
        DEBUG(sum,cnt);
        DEBUG(VI(p+1,p+n+1));
        DEBUG(q);
        exit(0);
    }*/
    W(q);
}
void test(){
    FOR(_n,1,6){
        n=_n;
        VI _p(_n);
        REP(i,_n)_p[i]=i+1;
        do{
            FOR(i,1,n)p[i]=_p[i-1];
            solve();
        }while(next_permutation(ALL(_p)));
    }
}
void input() {
    R(n);
    FOR(i,1,n)R(p[i]);
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //test();
    CASET {
        input();
        solve();
    }
    return 0;
}