/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 2e6+10;
int d[SIZE];
int cnt[SIZE],v[SIZE],u[SIZE],tt,tmp_v[SIZE];
void add(int id,int _v){
    if(u[id]!=tt){
        u[id]=tt;
        tmp_v[id]=_v;
    }
    else{
        tmp_v[id]=min(tmp_v[id],_v);
    }
}
void add(int num){
    tt++;
    FOR(i,1,num){
        int r=num/i;
        add(r+1,i);
        if(num%i==0){
            add(r,i);
        }
    }
    FOR(i,1,num+1){
        if(u[i]==tt){
            cnt[i]++;
            v[i]+=tmp_v[i];
        }
    }
}
void solve(){
    int n;
    R(n);
    memset(cnt,0,sizeof(int)*(n+1));
    memset(v,0,sizeof(int)*(n+1));
    REP(i,n)R(d[i]);
    sort(d,d+n);
    int t=0;
    for(int i=0,j;i<n;i=j){
        t++;
        for(j=i+1;j<n&&d[j]==d[i];j++);
        add(j-i);
    }
    int an=n;
    FOR(i,1,n){
        if(cnt[i]==t)an=min(an,v[i]);
    }
    W(an);
}
int main(){
    CASET{
        solve();
    }
    return 0;
}