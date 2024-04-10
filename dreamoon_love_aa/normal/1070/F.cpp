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
const int SIZE = 1e6+10;
int main(){
    int n;
    R(n);
    VI d[4];
    REP(i,n){
        string s;
        int x;
        R(s,x);
        int ty=0;
        REP(j,2){
            ty*=2;
            ty+=(s[j]-'0');
        }
        d[ty].PB(x);
    }
    REP(i,4)sort(ALL(d[i]),greater<int>());
    int base=0;
    int n3=SZ(d[3]);
    REP(i,SZ(d[3]))base+=d[3][i];
    int now=0,ma=0;
    int it[2]={};
    FOR(i,0,SZ(d[2])){
        if(i)now+=d[2][i-1];
        while(it[0]>0&&(it[0]+i)*2>(it[0]+it[1]+i+n3)){
            now-=d[0][--it[0]];
        }
        while((it[0]+i)*2>(it[0]+it[1]+i+n3)){
            if(it[1]<SZ(d[1])){
                now+=d[1][it[1]++];
            }
            else break;
        }
        if((it[0]+i)*2>(it[0]+it[1]+i+n3))break;
        while((it[0]+it[1]+1)*2<=(it[0]+it[1]+1+i+n3)){
            int v[2]={-1,-1};
            REP(j,2){
                if(it[j]<SZ(d[j]))v[j]=d[j][it[j]];
            }
            if((it[0]+i+1)*2>(it[0]+it[1]+1+i+n3))v[0]=-1;
            if(max(v[0],v[1])==-1)break;
            if(v[0]<=v[1]){
                now+=v[1];
                it[1]++;
            }
            else{
                now+=v[0];
                it[0]++;
            }
        }
        ma=max(ma,now);
    }
    W(base+ma);
    return 0;
}