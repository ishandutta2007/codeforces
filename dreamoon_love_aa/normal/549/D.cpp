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
const int SIZE = 1e3+10;
// template end here
LL dp[SIZE][SIZE];
char s[SIZE][SIZE];
int main(){
    DRII(n,m);
    REP(i,n){
        RS(s[i]);
    }
    int an=0;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int need;
            if(s[i][j]=='W')need=1;
            else need=-1;
            LL now=dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1];
            if(now!=need){
                an++;
            }
            dp[i][j]=need;
        }
    }
    cout<<an<<endl;
    return 0;
}