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
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<10;
int n,m,k;
char s[SIZE][SIZE];
void print(){
    REP(i,n){
        s[i][m]=0;
        W(s[i]);
    }
}
void solve() {
    if(n%2==0&&m%2==0){
        int v=n*m/2;
        if((v-k)%2==0){
            W("YES");
            for(int i=0;i<n;i+=2){
                for(int j=0;j<m;j+=2){
                    char c1=(i+j)%26+'a';
                    char c2=(i+j+1)%26+'a';
                    if(k>0){
                        k-=2;
                        s[i][j]=s[i][j+1]=c1;
                        s[i+1][j]=s[i+1][j+1]=c2;
                    }else{
                        s[i][j]=s[i+1][j]=c1;
                        s[i][j+1]=s[i+1][j+1]=c2;
                    }
                }
            }
            print();
        }else{
            W("NO");
        }

    }else if(m%2==0){
        int v=n*m/2;
        if((v-k)%2==0&&k>=m/2){
            W("YES");
            k-=m/2;
            for(int i=0;i+1<n;i+=2){
                for(int j=0;j<m;j+=2){
                    char c1=(i+j)%26+'a';
                    char c2=(i+j+1)%26+'a';
                    if(k>0){
                        k-=2;
                        s[i][j]=s[i][j+1]=c1;
                        s[i+1][j]=s[i+1][j+1]=c2;
                    }else{
                        s[i][j]=s[i+1][j]=c1;
                        s[i][j+1]=s[i+1][j+1]=c2;
                    }
                }
                s[i][m]=s[i+1][m]=0;
            }
            for(int j=0;j<m;j+=2){
                char c1=(n-1+j)%26+'a';
                s[n-1][j]=s[n-1][j+1]=c1;
            }
            print();
        }
        else{
            W("NO");
        }
    }else{
        int v=n*(m-1)/2;
        if(k<=v&&(v-k)%2==0){
            W("YES");
            for(int i=0;i<n;i+=2){
                for(int j=0;j+1<m;j+=2){
                    char c1=(i+j)%26+'a';
                    char c2=(i+j+1)%26+'a';
                    if(k>0){
                        k-=2;
                        s[i][j]=s[i][j+1]=c1;
                        s[i+1][j]=s[i+1][j+1]=c2;
                    }else{
                        s[i][j]=s[i+1][j]=c1;
                        s[i][j+1]=s[i+1][j+1]=c2;
                    }
                }
                s[i][m]=s[i+1][m]=0;
            }
            for(int i=0;i<n;i+=2){
                char c1=(i+m-1)%26+'a';
                s[i][m-1]=s[i+1][m-1]=c1;
            }
            print();
        }else{
            W("NO");
        }
    }
}
void input() {
    R(n,m,k);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}