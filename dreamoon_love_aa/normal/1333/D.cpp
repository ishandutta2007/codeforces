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
char s[SIZE];
vector<VI>ans;
int main(){
    int n,k;
    R(n,k);
    RS(s+1);
    int rn=0;
    int ln=0;
    int ma=0;
    int lt_l=-1;
    FOR(i,1,n){
        if(s[i]=='R')rn++;
        else{
            ln++;
            lt_l=i;
            ma+=rn;
        }
    }
    if(lt_l==-1){
        W(-1);
        return 0;
    }
    REP(cs,n){
        bool suc=0;
        VI AA;
        for(int i=n;i>1;i--){
            if(s[i]=='L'&&s[i-1]=='R'){
                AA.PB(i-1);
                swap(s[i],s[i-1]);
                i--;
                suc=1;
            }
        }
        if(!suc){
            break;
        }
        else{
            ans.PB(AA);
        }
    }
    if(k<SZ(ans)||ma<k){
        W(-1);
        return 0;
    }
    REP(i,SZ(ans)){
        REP(j,SZ(ans[i])){
            if(SZ(ans)-i==k){
                printf("%d ",SZ(ans[i])-j);
                for(int it=j;it<SZ(ans[i]);it++)printf("%d%c",ans[i][it]," \n"[it==SZ(ans[i])-1]);
                REPP(it,i+1,SZ(ans)){
                    W(SZ(ans[it]),ans[it]);
                }
                return 0;
            }
            W(1,ans[i][j]);
            k--;
        }
    }
    return 0;
}