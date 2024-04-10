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
const int SIZE = 1e6+10;
const int R = 0;
const int DD = 1;
const int L = 2;
const int UU = 3;
// template end here
int a[333][333];
int dp[4][333][333];
int main(){
    DRIII(n,m,t);
    DRIII(P,U,D);
    REP(i,n)REP(j,m)RI(a[i+1][j+1]);
    REPP(i,1,n+1){
        REPP(j,1,m){
            dp[R][i][j]=dp[R][i][j-1];
            if(a[i][j]==a[i][j+1])dp[R][i][j]+=P;
            else if(a[i][j]>a[i][j+1])dp[R][i][j]+=D;
            else dp[R][i][j]+=U;
        }
        REPP(j,1,m){
            dp[L][i][j]=dp[L][i][j-1];
            if(a[i][j]==a[i][j+1])dp[L][i][j]+=P;
            else if(a[i][j]>a[i][j+1])dp[L][i][j]+=U;
            else dp[L][i][j]+=D;
        }
    }

    REPP(j,1,m+1){
        REPP(i,1,n){
            dp[DD][i][j]=dp[DD][i-1][j];
            dp[UU][i][j]=dp[UU][i-1][j];
            if(a[i][j]==a[i+1][j]){
                dp[DD][i][j]+=P;
                dp[UU][i][j]+=P;
            }
            else if(a[i][j]>a[i+1][j]){
                dp[DD][i][j]+=D;
                dp[UU][i][j]+=U;
            }
            else{
                dp[DD][i][j]+=U;
                dp[UU][i][j]+=D;
            }
        }
    }
    int best=-1;
    vector<int>an(4);
    REPP(x1,1,n)REPP(x2,x1+2,n+1){
        set<PII>H;
        int add=0;
        REPP(y,3,m+1){
            int v=dp[R][x1][y-2]-dp[R][x1][y-3]
                 +dp[L][x2][y-2]-dp[L][x2][y-3]
                 +dp[UU][x2-1][y-2]-dp[UU][x1-1][y-2]
                 +dp[DD][x2-1][y-1]-dp[DD][x1-1][y-1]
                 -add;
            H.insert(MP(v,y-2));
            add+=dp[R][x1][y-1]-dp[R][x1][y-2]
                 +dp[L][x2][y-1]-dp[L][x2][y-2]
                 -dp[DD][x2-1][y-1]+dp[DD][x1-1][y-1]
                 +dp[DD][x2-1][y]-dp[DD][x1-1][y];
            set<PII>::iterator it=H.lower_bound(MP(t-add,0));
            if(it!=H.end()&&abs(it->F+add-t)<abs(best-t)){
                best=it->F+add;
                an[0]=x1;
                an[2]=x2;
                an[1]=it->S;
                an[3]=y;
            }
            if(it!=H.begin()){
                it--;
                if(abs(it->F+add-t)<abs(best-t)){
                    best=it->F+add;
                    an[0]=x1;
                    an[2]=x2;
                    an[1]=it->S;
                    an[3]=y;
                }
            }
        }
    }
    REP(i,4)printf("%d ",an[i]);
    return 0;
}