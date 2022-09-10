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
const int SIZE = 300010;
const int MAX_BIT = 19;
const int AA = MAX_BIT*(MAX_BIT-1)/2;
int n,q;
int a[SIZE];
void No(){
    W("Fou");
}
void Yes(){
    W("Shi");
}
int nxt[SIZE][AA];
int target[MAX_BIT],tt;
int id[MAX_BIT][MAX_BIT];
void solve(int x,int y){
    if(!a[x]||!a[y]){
        No();
        return;
    }
    if(a[x]&a[y]){
        Yes();
        return;
    }
    tt++;
    {
        int now=a[y];
        while(now){
            target[__builtin_ctz(now)]=tt;
            now=now&(now-1);
        }
    }
    priority_queue<PII,VPII,greater<PII>>pq;
    bool visited[MAX_BIT]={};
    int mi[MAX_BIT];
    REP(i,MAX_BIT)mi[i]=y+1;
    {
        int now=a[x];
        while(now){
            int me=__builtin_ctz(now);
            mi[me]=x;
            pq.push({x,me});
            now=now&(now-1);
        }
    }
    while(SZ(pq)&&pq.top().F<=y){
        PII now=pq.top();
        pq.pop();
        if(visited[now.S])continue;
        visited[now.S]=1;
        REP(i,MAX_BIT){
            if(i==now.S)continue;
            int me=id[now.S][i];
            int v=nxt[now.F][me];
            if(v>=mi[i])continue;
            mi[i]=v;
            if(target[i]==tt){
                Yes();
                return;
            }
            pq.push({v,i});
        }
    }
    No();
}
int main(){
    R(n,q);
    {
        int it=0;
        REP(i,MAX_BIT)REP(j,i){
            id[j][i]=id[i][j]=it++;
        }
    }
    FOR(i,1,n){
        R(a[i]);
    }
    int tmp[MAX_BIT],tmp_n;
    REP(i,AA)nxt[n+1][i]=n+1;
    for(int i=n;i>0;i--){
        tmp_n=0;
        int now=a[i];
        while(now){
            tmp[tmp_n++]=__builtin_ctz(now);
            now=now&(now-1);
        }
        REP(j,AA){
            nxt[i][j]=nxt[i+1][j];
        }
        REP(j,tmp_n)REP(k,j){
            nxt[i][id[tmp[k]][tmp[j]]]=i;
        }
    }
    while(q--){
        int x,y; R(x,y);
        solve(x,y);
    }
    return 0;
}