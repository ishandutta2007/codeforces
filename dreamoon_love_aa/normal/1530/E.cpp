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

const int SIZE = 1<<20;
char s[SIZE];
int cnt[26];
void solve() {
    MS0(cnt);
    int n=0;
    for(int i=0;s[i];i++){
        n++;
        cnt[s[i]-'a']++;
    }
    REP(i,26){
        if(cnt[i]==n){
            W(s);
            return;
        }
    }
    REP(i,26){
        if(cnt[i]==1){
            REP(j,n){
                if(s[j]==i+'a'){
                    if(j){
                        swap(s[j],s[0]);
                    }
                    sort(s+1,s+n);
                    W(s);
                    return;
                }
            }
        }
    }
    int st;
    REP(i,26){
        if(cnt[i]){
            st=i;
            break;
        }
    }
    if((cnt[st]-2)*2<=n-2){
        putchar('a'+st);
        putchar('a'+st);
        cnt[st]-=2;
        REP(i,n-2){
            if(i&1){
                REPP(j,st,26){
                    if(cnt[j]>0){
                        putchar(j+'a');
                        cnt[j]--;
                        break;
                    }
                }
            }else{
                REPP(j,st+1,26){
                    if(cnt[j]>0){
                        putchar(j+'a');
                        cnt[j]--;
                        break;
                    }
                }
            }
        }
        W("");
        return;
    }
    int sd;
    REPP(i,st+1,26){
        if(cnt[i]){
            sd=i;
            break;
        }
    }
    if(26-count(cnt,cnt+26,0)>2){
        putchar(st+'a');
        putchar(sd+'a');
        REPP(i,1,cnt[st]){
            putchar(st+'a');
        }
        cnt[sd]--;
        REPP(i,sd+1,26){
            if(cnt[i]){
                cnt[i]--;
                putchar(i+'a');
                break;
            }
        }
        REPP(i,st+1,26){
            REP(j,cnt[i]){
                putchar(i+'a');
            }
        }
        W("");
        return;
    }
    putchar('a'+st);
    REP(i,cnt[sd]){
        putchar('a'+sd);
    }
    REPP(i,1,cnt[st]){
        putchar('a'+st);
    }
    W("");
}
void input() {
    RS(s);
}
int main(){
    CASET {
        input();
        solve();
    }
    return 0;
}