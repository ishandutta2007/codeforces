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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
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
const int SIZE = 3e3+10;
char s[SIZE][SIZE],t[SIZE][SIZE];
vector<char>bk,ft;
int same[SIZE+SIZE];
bool f(string from, string to,string &x,string &y){
    if(SZ(from)>=SZ(x)){
        string AA=x+from;
        int ll=0,rr=0;
        for(int i=1;i<SZ(AA);i++){
            int k=0;
            if(rr>i)k=min(rr-i,same[i-ll]);
            while(i+k<SZ(AA)&&AA[i+k]==AA[k])k++;
            same[i]=k;
            if(i+k>rr){
                ll=i;
                rr=i+k;
            }
            if(same[i]>=SZ(x)&&i>=SZ(x)){
                from=from.substr(0,i-SZ(x))+y+from.substr(i);
                break;
            }
        }
    }
    return from==to;
}
char x[SIZE],y[SIZE];
int mid_len;
int main(){
    int n; R(n);
    REP(i,n)R(s[i]);
    REP(i,n)R(t[i]);
    REP(i,n){
        int mi=1e9,ma=0;
        int len=LEN(s[i]);
        REP(j,len){
            if(s[i][j]!=t[i][j]){
                mi=min(mi,j);
                ma=max(ma,j);
            }
        }
        if(mi>ma)continue;
        if(!mid_len){
            memcpy(x,s[i]+mi,ma+1-mi);
            memcpy(y,t[i]+mi,ma+1-mi);
            mid_len=ma-mi+1;
            REPP(j,ma+1,len){
                if(s[i][j]==t[i][j])bk.PB(s[i][j]);
                else break;
            }
            for(int j=mi-1;j>=0;j--){
                if(s[i][j]==t[i][j])ft.PB(s[i][j]);
                else break;
            }
        }
        else{
            if(strncmp(x,s[i]+mi,mid_len)||strncmp(y,t[i]+mi,mid_len)){
                W("NO");
                return 0;
            }
            if(len-ma-1<SZ(bk))bk.resize(len-ma-1);
            for(int j=0;j<SZ(bk);j++){
                if(s[i][j+ma+1]!=t[i][j+ma+1]||s[i][j+ma+1]!=bk[j]){
                    bk.resize(j);
                    break;
                }
            }
            if(mi<SZ(ft))ft.resize(mi);
            REP(j,SZ(ft)){
                if(s[i][mi-1-j]!=t[i][mi-1-j]||s[i][mi-j-1]!=ft[j]){
                    ft.resize(j);
                    break;
                }
            }
        }
    }
    string an1,an2;
    for(int i=SZ(ft)-1;i>=0;i--){
        an1+=ft[i];
        an2+=ft[i];
    }
    an1+=x;
    an2+=y;
    REP(i,SZ(bk)){
        an1+=bk[i];
        an2+=bk[i];
    }
    REP(i,n){
        if(!f(s[i],t[i],an1,an2)){
            W("NO");
            return 0;
        }
    }
    W("YES");
    W(an1);W(an2);
    return 0;
}