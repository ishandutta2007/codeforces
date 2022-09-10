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
const int SIZE = 310;
deque<char>s1[SIZE][SIZE];
int cnt[SIZE][SIZE],n,m;
VI ans;
void move(deque<char>ss[][SIZE],int x1,int y1,int x2,int y2){
    char c=ss[x1][y1].back();
    ss[x1][y1].pop_back();
    ss[x2][y2].push_front(c);
    cnt[x1][y1]-=c-'0';
    cnt[x2][y2]+=c-'0';
    ans.PB(x1);
    ans.PB(y1);
    ans.PB(x2);
    ans.PB(y2);
}
bool all_zero(deque<char>ss[][SIZE],int x,int y){
    return cnt[x][y]==0;
}
bool all_one(deque<char>ss[][SIZE],int x,int y){
    return SZ(ss[x][y])==cnt[x][y];
}
void go(VI &res){
    ans.clear();
    while(!all_zero(s1,1,1)){
        move(s1,1,1,2,1);
    }
    while(!all_one(s1,n,m)){
        move(s1,n,m,n-1,m);
    }
    FOR(i,1,n)FOR(j,2,m-1){
        while(SZ(s1[i][j])){
            if(s1[i][j].back()=='0')move(s1,i,j,i,1);
            else move(s1,i,j,i,m);
        }
    }
    REP(k,10){
        FOR(i,2,n){
            while(!s1[i][1].empty()){
                if(s1[i][1].back()=='0'){
                    move(s1,i,1,1,1);
                }
                else{
                    move(s1,i,1,i,m);
                }
            }
        }
        FOR(i,1,n-1){
            while(!s1[i][m].empty()){
                if(s1[i][m].back()=='0'){
                    move(s1,i,m,i,1);
                }
                else{
                    move(s1,i,m,n,m);
                }
            }
        }
    }
    res=ans;
}
int main(){
    R(n,m);
    FOR(i,1,n)FOR(j,1,m){
        string s; R(s);
        for(char c: s){
            s1[i][j].PB(c);
            cnt[i][j]+=c-'0';
        }
    }
    VI r1,r2;
    go(r1);

    MS0(cnt);
    FOR(i,1,n)FOR(j,1,m){
        string s; R(s);
        s1[i][j].clear();
        for(int k=SZ(s)-1;k>=0;k--){
            s1[i][j].PB(s[k]);
            cnt[i][j]+=s[k]-'0';
        }
    }
    go(r2);
    W(SZ(r1)/4+SZ(r2)/4);
    for(int i=0;i<SZ(r1);i+=4){
        W(r1[i],r1[i+1],r1[i+2],r1[i+3]);
    }
    for(int i=SZ(r2)-4;i>=0;i-=4){
        W(r2[i+2],r2[i+3],r2[i],r2[i+1]);
    }
    return 0;
}