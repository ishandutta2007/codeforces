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
const int SIZE = 2e5+5;
int a[SIZE],dp[SIZE],n,m,w;
bool check(int v){
    MS0(dp);
    int now=0;
    int yo=0;
    REP(i,n){
        now+=dp[i];
        int need=(v-a[i]-now);
        yo+=max(0,need);
        now+=max(0,need);
        dp[i+w]-=max(0,need);
        if(yo>m)return false;
    }
    return true;
}
int main(){
    RIII(n,m,w);
    REP(i,n)RI(a[i]);
    int ll=1,rr=1e9+1e7;
    while(ll<rr){
        int mm=(ll+rr+1)>>1;
        if(check(mm))ll=mm;
        else rr=mm-1;
    }
    cout<<ll<<endl;
    return 0;
}