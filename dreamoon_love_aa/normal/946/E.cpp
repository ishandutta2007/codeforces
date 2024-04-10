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
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
char s[SIZE];
int zero[SIZE];
int bit_cnt[1024];
bool good(int st,int mask,int n){
    int m=bit_cnt[mask];
    if(st+m>n)return 0;
    if(n-st-m+mask%2!=zero[st]){
        return zero[st]<n-st-m+mask%2;
    }
    int it=n-m;
    REP(i,10){
        if((mask>>i)&1){
            if(i!=s[it]-'0'){
                return i<s[it]-'0';
            }
            it++;
        }
    }
    return 1;
}
int main(){
    REPP(i,1,1024){
        bit_cnt[i]=bit_cnt[i>>1]+(i&1);
    }
    CASET{
        RS(s);
        int n=LEN(s);
        zero[n]=0;
        zero[n-1]=(s[n-1]=='0');
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0')
                zero[i]=zero[i+1]+1;
            else
                zero[i]=0;
            
        }
        if(s[0]=='1'&&(zero[1]==n-1||(zero[1]==n-2&&s[n-1]=='1'))){
            REP(i,n-2)putchar('9');
            puts("");
        }
        else{
            s[n-1]--;
            for(int i=n-1;i>=0;i--){
                if(s[i]<'0'){
                    s[i]='9';
                    s[i-1]--;
                }
                else break;
            }
            zero[n-1]=(s[n-1]=='0');
            for(int i=n-2;i>=0;i--){
                if(s[i]=='0')
                    zero[i]=zero[i+1]+1;
                else
                    zero[i]=0;

            }
            {
                int tmp=0;
                REP(i,n){
                    tmp^=1<<(s[i]-'0');
                }
                if(!tmp){
                    puts(s);
                    continue;
                }
            }
            int now=0;
            bool nines=0;
            REP(i,n){
                now^=1<<(s[i]-'0');
                while(!good(i+1,now,n)){
                    now^=1<<(s[i]-'0');
                    s[i]--;
                    now^=1<<(s[i]-'0');
                    if(!nines){
                        FOR(j,i+1,n-1)s[j]='9';
                        nines=1;
                        zero[n-1]=(s[n-1]=='0');
                        for(int j=n-2;j>i;j--){
                            if(s[j]=='0')
                                zero[j]=zero[j+1]+1;
                            else
                                zero[j]=0;

                        }
                    }
                }
            }
            puts(s);
        }
    }
    return 0;
}