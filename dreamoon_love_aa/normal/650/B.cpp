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
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int n;
int solve(char s[],int a,int b,int T){
    if(s[0]=='w'&&b+1>T)return 0;
    int now=0;
    int rr=0;
    while(rr<n){
        if(s[rr]=='w'){
            if(now+b+1>T){
                now-=a;
                rr--;
                break;
            }
            now+=b+1;
        }
        else{
            if(now+1>T){
                now-=a;
                rr--;
                break;
            }
            now++;
        }
        if(rr==n-1||now+a+1>T)break;
        rr++;
        now+=a;
    }
    if(rr+1==n)return n;
    int an=rr+1;
    int ll=n;
    while(rr>=0){
        while(ll-1>rr&&now+2*a+1+(s[ll-1]=='w')*b<=T){
            now+=2*a+1+(s[ll-1]=='w')*b;
            ll--;
        }
        an=max(an,rr+1+(n-ll));
        now--;
        if(s[rr]=='w')now-=b;
        now-=a;
        rr--;
    }
    return an;

}
char s[SIZE];
int main(){
    RI(n);
    DRIII(a,b,T);
    RS(s);
    int an=solve(s,a,b,T);
    reverse(s+1,s+n);
    an=max(an,solve(s,a,b,T));
    printf("%d\n",an);

    return 0;
}