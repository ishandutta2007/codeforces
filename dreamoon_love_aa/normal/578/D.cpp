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
const int SIZE = 1e5+10;
// template end here
LL dp[SIZE][8];
char s[SIZE];
int get_bit(int x,int v){return (x>>v)&1;}
int main(){
    DRII(n,m);
    RS(s+1);
    REPP(i,1,n+1)s[i]-='a';
    s[n+1]=-1;
    REP(i,m){
        int state=1;
        if(i==s[1])state|=2;
        if(i==s[1]||i==s[2])state|=4;
        dp[1][state]++;
    }
    REPP(i,2,n+1){
        REP(j,8){
            int d[4]={i-3+get_bit(j,0),i-2+get_bit(j,1),i-2+get_bit(j,2)};
            REP(k,m){
                int d2[4]={};
                REPP(l,1,4){
                    if(s[i-2+l]==k)d2[l]=d[l-1]+1;
                    else d2[l]=max(d2[l-1],d[l]);
                }
                if(d2[1]>=i-2&&min(d2[2],d2[3])>=i-1)dp[i][(d2[1]-(i-2))|((d2[2]-(i-1))<<1)|((d2[3]-(i-1))<<2)]+=dp[i-1][j];
            }
        }
    }
    printf("%I64d\n",dp[n][0]+dp[n][1]+dp[n][4]+dp[n][5]);
    return 0;
}