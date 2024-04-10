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
char s[20];
int m,n,ten[20];
LL dp[1<<18][100];
int main(){
    LL fac[20]={1};
    REPP(i,1,20)fac[i]=fac[i-1]*i;
    RS(s);RI(m);
    n=LEN(s);
    ten[0]=1;
    REPP(i,1,n)ten[i]=ten[i-1]*10%m;
    REP(i,n)s[i]-='0';
    sort(s,s+n);
    REPP(i,1,1<<n){
        if(!(i&(i-1))){
            int it=0;
            while((1LL<<it)<i)it++;
            if(s[it])dp[i][s[it]*ten[n-1]%m]=1;
        }
        else{
            int bn=0;
            REP(j,n){
                bn+=(i>>j)&1;
            }
            REP(j,n){
                if((i>>j)&1){
                    int you=i^(1<<j);
                    REP(k,m){
                        dp[i][(k+ten[n-bn]*s[j])%m]+=dp[you][k];
                    }
                }
            }
        }
    }
    LL an=dp[(1<<n)-1][0];
    REP(i,n){
        int j;
        for(j=i+1;j<n&&s[j]==s[i];j++);
        an/=fac[j-i];
        i=j-1;
    }
    cout<<an;
    return 0;
}