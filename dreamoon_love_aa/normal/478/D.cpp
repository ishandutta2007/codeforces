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
int dp[200001];
void add(int &x,int v){
    x+=v;
    if(x>=MOD)x-=MOD;
}
int main(){
    DRII(r,g);
    int G=r+g;
    int lv=1;
    while((lv+1)*(lv+2)/2<=G)lv++;
    int h=0;
    dp[0]=1;
    REPP(i,1,lv+1){
        for(int j=min(h,200000-i);j>=0;j--){
            if(dp[j])add(dp[j+i],dp[j]);
        }
        h+=i;
    }
    int all=lv*(lv+1)/2;
    int an=0;
    for(int i=r;all-i<=g&&i>=0;i--)add(an,dp[i]);
    cout<<an<<endl;
    return 0;
}