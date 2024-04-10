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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e6+10;
char s[SIZE];
char an[SIZE];
int dp[SIZE],far[SIZE];
int main(){
    DRII(n,K);
    RS(s);
    if(K==1){
        REP(i,n)an[i]='1';
        puts(an);
        return 0;
    }
    int ll=0,rr=0;
    for(int i=1;i<n;i++){
        int k=0;
        if(i<rr){
            k=min(rr-i,far[i-ll]);
        }
        while(i+k<n&&s[i+k]==s[k])k++;
        far[i]=k;
        if(i+k>rr){
            rr=i+k;
            ll=i;
        }
        if(far[i]>=(LL)i*(K-1)){
            dp[i*K-1]++;
            dp[min(i*(K+1),i+far[i])]--;
        }
    }
    REPP(i,1,SIZE)dp[i]+=dp[i-1];
    REP(i,n){
        an[i]=(dp[i]!=0)?'1':'0';
    }
    puts(an);
    return 0;
}