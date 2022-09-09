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
#define PB emplace_back
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
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
int p[SIZE];
vector<int>pp;
void prime_init(){
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
bool is_prime(int x){
    return p[x]==x;
}
bitset<SIZE>u;
int ask(char c,int x){
    W(c,x);
    fflush(stdout);
    if(c=='C'){
        exit(0);
    }
    int v;
    R(v);
    return v;
}
void solve() {
    prime_init();
    int n;
    R(n);
    VI AA;
    FOR(i,2,n){
        if(is_prime(i))AA.PB(i);
    }
    int sqn=sqrt(SZ(AA)+0.1);
    int rn=n;
    VI ps;
    bool found=0;
    for(int i=0;i<SZ(AA);i+=sqn){
        int rr=min(SZ(AA),i+sqn);
        REPP(j,i,rr){
            int real_v=ask('B',AA[j]);
            int expeted_v=0;
            for(int k=AA[j];k<=n;k+=AA[j]){
                if(!u[k]){
                    u[k]=1;
                    expeted_v++;
                    rn--;
                }
            }
            if(real_v!=expeted_v){
                ps.PB(AA[j]);
            }
        }
        if(!found){
            int ret=ask('A',1);
            if(ret!=rn){
                found=1;
                REPP(j,i,rr){
                    ret=ask('A',AA[j]);
                    if(ret==1){
                        ps.PB(AA[j]);
                        break;
                    }
                }
            }
        }
    }
    LL an=1;
    REP(i,SZ(ps)){
        an*=ps[i];
        while(an*ps[i]<=n&&ask('A',an*ps[i])==1){
            an*=ps[i];
        }
    }
    ask('C',an);
}
int main(){
#define MULTITEST 0
#if MULTITEST    
    CASET{
        solve();
    }
#else
    solve();
#endif
    return 0;
}