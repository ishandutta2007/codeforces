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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const int MAXLEN = (int)2e5 + 5;
 
char s[MAXLEN];
int SA[MAXLEN], cnt[MAXLEN], ary1[MAXLEN], ary2[MAXLEN];
int *Rank, *Height;
 
 
inline bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
 
void make_suffix_array(int MSIZE, int len) {
    int p, *x, *y, *tmp, i, j, k;
    x = ary1; y = ary2;
    memset(cnt, 0, sizeof(int) * MSIZE);
    for (i = 0; i < len; i++) cnt[x[i] = s[i]]++;
    for (i = 1; i < MSIZE; i++) cnt[i] += cnt[i - 1];
    for (i = len - 1; i >= 0; i--) SA[--cnt[x[i]]] = i;
    for (j = p = 1; p < len; j <<= 1, MSIZE = p) {
        for (p = 0, i = len - j; i < len; i++) y[p++] = i;
        for (i = 0; i < len; i++) {
            if (SA[i] >= j) y[p++] = SA[i] - j;
        }
        memset(cnt, 0, sizeof(int) * MSIZE);
        for (i = 0; i < len; i++) cnt[x[y[i]]]++;
        for (i = 1; i < MSIZE; i++) cnt[i] += cnt[i - 1];
        for (i = len - 1; i >= 0; i--) SA[--cnt[x[y[i]]]] = y[i];
        tmp = x; x = y; y = tmp;
        x[SA[0]] = 0;
        for (i = p = 1; i < len; i++) {
            x[SA[i]] = cmp(y, SA[i - 1], SA[i], j) ? p - 1 : p++;
        }
    }
    Rank = x;
    Height = y;
    for (i = k = 0; i < len - 1; i++) {
        if (k > 0) k--;
        j = SA[Rank[i] - 1];
        while (s[i + k] == s[j + k]) k++;
        Height[Rank[i]] = k;
    }
}
int get(int lv,int ll,int rr,char c){
    rr++;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(s[lv+SA[mm]]>=c)rr=mm;
        else ll=mm+1;
    }
    return ll;
}

const int BIT_NUM = 13;
struct BIT{
    int _n;
    int _d[1 << BIT_NUM];
    void init(int __n) {
        _n=__n;
        memset(_d, 0, sizeof(int) * (_n+1));
    }
    void ins(int x, int v) {
        for(; x <= _n; x += x & -x) { _d[x] = max(_d[x], v); }
    }
    int qq(int x) {
        if(x <= 0) {
            return 0;
        }
        int res = 0;
        for(; x; x -= x & -x) { res = max(res, _d[x]);}
        return res;
    }
}bit;
int N;
long long K;
char qs[SIZE];
long long dp[SIZE];
int tmp[SIZE],tn;
void dfs(int lv, int L, int R) {
        if(s[SA[L] + lv] == 0) { L++; }
        if(L > R) { return; }
        for(int i=L,j;i<=R;i=j){
            for(j=i+1;j<=R&&s[SA[j]+lv]==s[SA[i]+lv];j++);
            int k=lv+1;
            if(j>i+1){
                while(s[SA[j-1]+k]==s[SA[i]+k])k++;
            }else{
                k=N-SA[i];
            }
            tn=0;
            for(int r=i;r<j;r++){
                tmp[tn++]=SA[r];
            }
            sort(tmp,tmp+tn,greater<int>());
            REP(r,tn){
                int v=bit.qq(tmp[r]+1);
                bit.ins(tmp[r]+1,v+k-lv);
            }
            dfs(k,i,j-1);
        }
}
void solve() {
    R(N);
    scanf("%s",s);
    make_suffix_array(128, N + 1);
    bit.init(N);
    dfs(0, 1, N);
    W(bit.qq(N));
}
int main(){
    CASET{
        solve();
    }
    return 0;
}