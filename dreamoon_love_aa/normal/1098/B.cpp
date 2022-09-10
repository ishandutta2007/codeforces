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
string s[SIZE],tmp[SIZE],an[SIZE];
char c[5]="ACGT";
int n,m; 
void print(){
    REP(i,n)W(an[i]);
}
int main(){
    R(n,m);
    REP(i,n)R(s[i]);
    if(n==1||m==1){
        REP(i,n)an[i]=s[i];
    }
    else{
        REP(i,n)tmp[i]=string(m,'a');
        int best=1e9;
        REP(x,4)REPP(y,x+1,4){
            bool u[4]={};
            u[x]=1;
            u[y]=1;
            int z=0,w=0;
            while(u[z])z++;
            u[z]=1;
            while(u[w])w++;
            char AA[2][2]={{c[x],c[y]},{c[z],c[w]}};
            int wa_sum=0;
            REP(i,n){
                int wa[2]={};
                REP(j,m){
                    if(s[i][j]!=AA[i&1][j&1])wa[0]++;
                    if(s[i][j]!=AA[i&1][(j&1)^1])wa[1]++;
                }
                wa_sum+=min(wa[0],wa[1]);
                if(wa[0]<wa[1]){
                    REP(j,m)tmp[i][j]=AA[i&1][j&1];
                }
                else{
                    REP(j,m)tmp[i][j]=AA[i&1][(j&1)^1];
                }
            }
            if(wa_sum<best){
                best=wa_sum;
                REP(i,n)an[i]=tmp[i];
            }
            wa_sum=0;
            REP(j,m){
                int wa[2]={};
                REP(i,n){
                    if(s[i][j]!=AA[j&1][i&1])wa[0]++;
                    if(s[i][j]!=AA[j&1][(i&1)^1])wa[1]++;
                }
                wa_sum+=min(wa[0],wa[1]);
                if(wa[0]<wa[1]){
                    REP(i,n)tmp[i][j]=AA[j&1][i&1];
                }
                else{
                    REP(i,n)tmp[i][j]=AA[j&1][(i&1)^1];
                }
            }
            if(wa_sum<best){
                best=wa_sum;
                REP(i,n)an[i]=tmp[i];
            }
        }
    }
    print();
    return 0;
}