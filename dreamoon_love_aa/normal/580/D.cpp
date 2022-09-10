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
const int SIZE = 1e6+10;
// template end here
int d[20][20],a[20],bn[1<<18];
int bit_cnt(int x){
    int res=0;
    while(x){
        res+=x&1;
        x>>=1;
    }
    return res;
}
LL dp[1<<19][20];
int nn;
LL f(int x,int y){
    if(bn[x]==1)return a[y];
    if(dp[x][y]!=-1)return dp[x][y];
    LL res=0;
    REP(i,nn){
        if(i==y)continue;
        if((x>>i)&1){
            res=max(res,f(x^(1<<y),i)+a[y]+d[i][y]);
        }
    }
    return dp[x][y]=res;
}
int main(){
    MS1(dp);
    REP(i,1<<18)bn[i]=bit_cnt(i);
    DRIII(n,m,k);
    LL an=0;
    nn=n;
    REP(i,n)RI(a[i]);
    REP(i,k){
        DRIII(x,y,v);
        assert(v>=0);
        x--;y--;
        d[x][y]=v;
    }
    REP(i,1<<n){
        if(bn[i]==m){
            REP(j,n){
                if((i>>j)&1)an=max(an,f(i,j));
            }
        }
    }
    cout<<an<<endl;

    return 0;
}