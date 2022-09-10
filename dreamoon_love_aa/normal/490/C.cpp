#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE];
bool fail[SIZE];
int main(){
    RS(s);
    int n=LEN(s);
    DRII(a,b);
    fail[0]=1;
    REP(i,n)
        if(s[i]=='0')fail[i]=1;
    LL now=0;
    REP(i,n){
        now*=10;
        now+=s[i]-'0';
        now%=a;
        if(now)fail[i+1]=1;
    }
    LL ten=1;
    now=0;
    for(int i=n-1;i>=0;i--){
        now=(now+ten*(s[i]-'0'))%b;
        if(now)fail[i]=1;
        ten=ten*10%b;
    }
    REP(i,n)
        if(!fail[i]){
            puts("YES");
            REP(j,i)putchar(s[j]);
            puts("");
            REPP(j,i,n)putchar(s[j]);
            puts("");
            return 0;
        }
    puts("NO");
    return 0;
}