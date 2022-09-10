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
const int SIZE = 1e6+10;
char s[SIZE],a[SIZE],b[SIZE];
int n,K;
bool f(int it,int to[],bool u[][26],int state){
    if(it==n)return 1;
    if(u[0][s[it]]){
        int me=to[s[it]];
        if((state&1)&&me<a[it]){
            return 0;
        }
        if((state&2)&&me>b[it]){
            return 0;
        }
        if(!(state&1)&&me<b[it])return 1;
        if(!(state&2)&&me>a[it])return 1;
        if(a[it]<me&&me<b[it])return 1;
        if(me!=a[it])state&=2;
        if(me!=b[it])state&=1;
        return f(it+1,to,u,state);
    }
    int lo=a[it]+1;
    int hi=b[it]-1;
    if(!(state&1))lo=0;
    if(!(state&2))hi=K-1;
    FOR(i,lo,hi){
        if(!u[1][i]){
            to[s[it]]=i;
            u[1][i]=1;
            u[0][s[it]]=1;
            return 1;
        }
    }
    if(lo-1==hi+1){
        if(!u[1][lo-1]){
            to[s[it]]=lo-1;
            u[1][lo-1]=1;
            u[0][s[it]]=1;
            if(f(it+1,to,u,state))return 1;
            u[1][lo-1]=0;
            u[0][s[it]]=0;
        }
        return 0;
    }
    if(lo>0&&!u[1][lo-1]){
        to[s[it]]=lo-1;
        u[1][lo-1]=1;
        u[0][s[it]]=1;
        if(f(it+1,to,u,state&1)){
            return 1;
        }
        u[1][lo-1]=0;
        u[0][s[it]]=0;
    }
    if(hi+1<K&&!u[1][hi+1]){
        to[s[it]]=hi+1;
        u[1][hi+1]=1;
        u[0][s[it]]=1;
        if(f(it+1,to,u,state&2)){
            return 1;
        }
        u[1][hi+1]=0;
        u[0][s[it]]=0;
    }
    return 0;
}
void solve(){
    bool u[2][26]={};
    int to[26];
    if(f(0,to,u,3)){
        W("YES");
        int it=0;
        REP(i,K){
            if(!u[0][i]){
                while(u[1][it])it++;
                u[1][it]=1;
                to[i]=it;
            }
        }
        REP(i,K)putchar('a'+to[i]);
        W("");
    }
    else{
        W("NO");
    }
}
int main(){
    CASET{
        R(K);
        RS(s);
        RS(a);
        RS(b);
        n=LEN(s);
        REP(i,n){
            s[i]-='a';
            a[i]-='a';
            b[i]-='a';
        }
        solve();
    }
    return 0;
}