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
const LL INF = 1e18;
const int SIZE = 2e4;
// template end here
int l[SIZE],r[SIZE];
int d[SIZE],dn;
LL dp[2][SIZE];
int main(){
    DRII(n,x);
    d[dn++]=x;
    REPP(i,1,n+1){
        RII(l[i],r[i]);
        d[dn++]=l[i];
        d[dn++]=r[i];
    }
    sort(d,d+dn);
    dn=unique(d,d+dn)-d;
    int now=0,nxt=1;
    REP(i,dn){
        if(d[i]!=x)dp[now][i]=INF;
    }
    REPP(i,1,n+1){
        LL mi=dp[now][0];
        REP(j,dn){
            mi=min(mi,dp[now][j]);
            dp[nxt][j]=mi+max(0,max(d[j]-r[i],l[i]-d[j]));
            mi+=d[j+1]-d[j];
        }
        mi=dp[now][dn-1];
        for(int j=dn-1;j>=0;j--){
            mi=min(mi,dp[now][j]);
            dp[nxt][j]=min(dp[nxt][j],mi+max(0,max(d[j]-r[i],l[i]-d[j])));
            if(j)mi+=d[j]-d[j-1];
        }
        swap(now,nxt);
    }
    LL an=INF;
    REP(i,dn){
        an=min(an,dp[now][i]);
    }
    cout<<an<<endl;
    return 0;
}