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
const int SIZE = 500;
bitset<SIZE> lv[61][SIZE][2],lv_inv[61][SIZE][2];
bool dp[64][SIZE];
int main(){
    DRII(n,m);
    LL an=0;
    int ma_gg=-1;
    REP(i,m){
        DRII(x,y);x--;y--;
        DRI(z);
        if(!z)ma_gg=0;
        lv[0][x][z][y]=1;
        lv_inv[0][y][z][x]=1;
    }
    if(ma_gg==-1)return 0*puts("0");
    REP(gg,60){
        REP(i,n)REP(j,n){
            if((lv[gg][i][0]&lv_inv[gg][j][1]).any()){
                lv[gg+1][i][0][j]=1;
                lv_inv[gg+1][j][0][i]=1;
                ma_gg=gg+1;
            }
            if((lv[gg][i][1]&lv_inv[gg][j][0]).any()){
                lv[gg+1][i][1][j]=1;
                lv_inv[gg+1][j][1][i]=1;
            }
        }
    }
    an=1LL<<ma_gg;
    int now=0,st=1;
    REP(i,n)REP(j,n)
        if(lv[ma_gg][i][0][j])dp[now][j]=1;
    for(int gg=ma_gg-1;gg>=0;gg--){
        bool yes=0;
        REP(i,n){
            REP(j,n){
                if(dp[now][i]&&lv[gg][i][st][j]){
                    yes=1;
                    dp[now+1][j]=1;
                }
            }
        }
        if(yes){
            an+=1LL<<gg;
            st^=1;
            now++;
        }
    }
    if(an>1000000LL*1000000*1000000)an=-1;
    cout<<an<<endl;
    return 0;
}