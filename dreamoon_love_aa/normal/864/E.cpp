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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
struct data{
    int t,d,p,id;
    data(int _t=0,int _d=0,int _p=0,int _id=0):t(_t),d(_d),p(_p),id(_id){}
    bool operator<(const data& b)const{
        return d<b.d;
    }
}a[100];
int dp[101][2010],lt[101][2010];
int main(){
    DRI(n);
    REP(i,n){
        RIII(a[i].t,a[i].d,a[i].p);
        a[i].id=i+1;
    }
    sort(a,a+n);
    MS1(lt);
    MS1(dp);
    dp[0][0]=0;
    REP(i,n){
        for(int j=2000-a[i].t;j>=0;j--){
            if(dp[i][j]==-1)continue;
            if(j+a[i].t<a[i].d&&dp[i][j]+a[i].p>dp[i+1][j+a[i].t]){
                dp[i+1][j+a[i].t]=dp[i][j]+a[i].p;
                lt[i+1][j+a[i].t]=i;
            }
        }
        REP(j,2001){
            if(dp[i][j]!=-1&&dp[i][j]>dp[i+1][j]){
                dp[i+1][j]=dp[i][j];
                lt[i+1][j]=-1;
            }
        }
    }
    int ma=-1,id;
    REP(i,2001){
        if(dp[n][i]>ma){
            ma=dp[n][i];
            id=i;
        }
    }
    VI res;
    int x=n;
    while(x){
        if(lt[x][id]==-1){
            x--;
            continue;
        }
        res.PB(a[lt[x][id]].id);
        id-=a[lt[x][id]].t;
        x--;
    }
    reverse(ALL(res));
    printf("%d\n%d\n",ma,SZ(res));
    REP(i,SZ(res))printf("%d%c",res[i]," \n"[i==SZ(res)-1]);
    return 0;
}